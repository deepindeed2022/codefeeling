# 海思 NNIE

- 声明：本博客欢迎转发，但请保留原作者信息!
- 作者: [曹文龙]
- 博客： <https://cwlseu.github.io/>

##简介

NNIE是Neural Network Inference Engine的简称，是海思媒体Soc中专门针对神经网络特别是深度学习卷积神经网络进行加速处理的硬件单元，支持现有的大部分的公开网络，如AlexNet, VGG16, Googlenet, Resnet18,Resnet50等分类网络，Faster RCNN，YOLO，SSD，RFCN等检测网络，以及SegNet，FCN等场景分割网络。目前NNIE配套软件及工具链仅支持以Caffe框架，使用其他框架的网络模型需要转化为Caffe框架下的模型。
此处的NNIE指海思媒体处理芯片智能分析系统中的神经网络推断引擎。用户基于NNIE开发智能分析方案，降低CPU占用。

## 交叉编译环境搭建

```
➜  Hi3516CV500 tree -L 2 .
.
├── ReleaseDoc
│   ├── en
│   └── zh
└── Software
    ├── 20180919_134712007
    ├── 20180919_134914081
    ├── arm-himix200-linux.part1.rar   # 交叉编译链
    ├── arm-himix200-linux.part2.rar 
    ├── arm-himix200-linux.tgz.asc
    ├── Hi3516C V500R001C02SPC001.rar  # 终端开发用的工具，这里不关注
    ├── Hi3516C V500R001C02SPC001.rar.asc
    ├── HiIVE_PC_V2.1.0.7_64bit.tar.gz # 智能视频分析
    ├── HiIVE_PC_V2.1.0.7_64bit.tar.gz.asc
    ├── HiSVP_PC_V1.2.0.3.part1.rar    # 智能视觉异构加速平台，包含NNIE引擎
    ├── HiSVP_PC_V1.2.0.3.part2.rar
    ├── HiSVP_PC_V1.2.0.3.part3.rar
    ├── HiSVP_PC_V1.2.0.3.part4.rar
    └── HiSVP_PC_V1.2.0.3.tgz.asc
```
解压arm-himix200-linux.tar之后，运行 `source ./arm-himix200-linux.install`就会在`/opt/linux-hisi/x86-arm/arm-hisix200-linux`找到一个文件夹，这就是刚刚安装的交叉编译链。在`/etc/profile`完成了交叉编译链的PATH设置。
```bash
# 2019年 03月 14日 星期四 18:24:47 CST
# HuaWei LiteOS Linux, Cross-Toolchain PATH
export PATH="/opt/hisi-linux/x86-arm/arm-himix200-linux/bin:$PATH" 
# 
```

配置nnie转换工具的docker镜像：

`docker pull registry.sensetime.com/internal-sdk/nniemapper:opencv3.4_protobuf3.5`

`sudo nvidia-docker run -v /home/sensetime:/root -it registry.sensetime.com/internal-sdk/nniemapper:opencv3.4_protobuf3.5`

`export LD_LIBRARY_PATH=/usr/local/lib/x86_64-linux-gnu/:$LD_LIBRARY_PATH`

`./tools/nnie/linux/mapper/nnie_mapper_12`


##重要概念

![@NNIE的工作流程](./1552631267005.png)

支持网络分段
当网络中存在NNIE不支持的层的时候，需要对网络进行切分，不支持的部分用户使用CPU或者DSP的方式实现。nnie_mapper将NNI的Noe-support层分为两种，“Proposal”层和“Custom”层:
* Proposal层输出的是矩形信息，
![Alt text](./1552632024858.png)

### NNIE

用户基于NNIE开发智能分析方案，降低CPU占用率
![Alt text](./1553495154918.png)
![Alt text](./1553495322622.png)
![Alt text](./1553495347997.png)
![Alt text](./1553495393539.png)
![Alt text](./1553495435394.png)

### Runtime

![Alt text](./1553494941386.png)

基于Runtime开发智能分析方案，用户不需要关注调度逻辑，最大化复用NNIE硬件。

## 提升硬件的利用率

### 总的原则

* 相同的应用场景，减少层数，增加单层的计算量，能够减少层之间切换造成的利用率损失
* 尽量使用卷积，反卷积，Pooling， FC层，提高硬件资源利用率，减少对LRN，MVN，Normalization，softmax等操作
* 建议使用RELU，sigmod，Tanh，PreLU， RRELU激活函数并使用in-place的配置方式，以便与前一层共享blob，使得硬件高效完成计算

### 特别的针对卷积，反卷积，Pooling，DepthwiseConv层运算：

- 输出特征数据尺寸16*16的视乎，度参数的DDR贷款与卷积计算基本匹配；特征尺寸更小时，计算单元受限于DDR带宽，无法全部利用
- 硬件进行卷积计算时，数据按16组并行计算，输入的C维度是16倍数，输出的维度C是4的倍数，输出的W唯独是16的倍数的时候，可以充分利用MAC的计算性能


## 开发遇到的坑

1. **数据空间的排布情况。**在NNIE中，数据都是16或者32对齐的，而shadowBlob中的数据是一整块内存。在进行数据填充和结果拷贝的时候需要注意对对齐空间的处理。特别提醒：注意width和stride的区别，width是每行有效数值的，stride是实际占用的空间，往往stride是16的倍数 >= width
![Alt text](./1554718624099.png)

2. NNIE支持的层和PPL支持的层并不是一一对应的。例如常用的PPL中的常用层`Interp`在很多情况下是不支持的，需要通过`Upsample`或者`deconv`实现类似的功能。 Interp可以实现分数大小的插值，deconv需要进行成2的倍数的上采样。
3. 在模拟器运行方式和在真机上运行方式，需要的头文件和内存申请的接口是不一致的。而且当前模拟器仅支持`>=vs2015`.真机上需要调用`HI_MPI_SYS_MmzAlloc`接口进行申请空间，调用`HI_MPI_SYS_MmzFree`进行空间释放。
```cpp
HI_S32 SvpMalloc(HI_CHAR *pchMmb, HI_CHAR *pchZone, HI_U64 *pu64PhyAddr, HI_VOID **ppvVirAddr, HI_U32 u32Size) {
    HI_S32 s32Ret = HI_SUCCESS;
#if ((defined __arm__) || (defined __aarch64__)) && defined HISI_CHIP
    s32Ret = HI_MPI_SYS_MmzAlloc(pu64PhyAddr, ppvVirAddr, pchMmb, pchZone, u32Size);
#else
    *ppvVirAddr = (HI_VOID *)malloc(u32Size);
    if(HI_NULL == *ppvVirAddr){
        s32Ret = HI_FAILURE;
    } else {
        *pu64PhyAddr = (HI_U64)*ppvVirAddr;
    }
#endif
    memset(*ppvVirAddr, 0, u32Size);
    return s32Ret;
}
```
4. NNIE中不支持根据输入reshape的情况。例如：SSD的模型一定的时候，可以输入300x300，也可以输入512x512。为什么可以reshape by input呢？主要ROI Pooling的使用，使得不同大小的输入，最终的数据的总大小是一定的，只是感受野大小与输入图片的分辨率有关系。但是NNIE中不支持该特性。加载入NNIE的模型，输入要求是啥就是啥，不能变了的。

5.  相关资料中含有windows的模拟库（vs 14 nnieit1.2.lib等），但是没有找到在linux下开发需要的libnnie.a等依赖库。
这个需要到相应的板子上将相应的静态库和头文件下载下来。

6. **NNIE中仅仅支持U8和S32的计算，不支持Float32的计算。**我们当前输入是经过白化处理后的float32的数据。为了`to	reduce the probability of underflow`，我们采用scaling的策略实现计算的处理。
![Alt text](./1554716035190.png)
这项技术在mix-precision的网络中应用广泛，其中cuda 9 中有支持混合精度训练的特性，已经在tensorflow社区中开展可相关混合精度训练的研究。而这项技术为了就是基于scale实现的。当然他们采用动态调整的方式实现scale的调整。


## 问题
1.  当前NNIE支持直接使用NNIE构建方案和使用Runtime构建方案在算法实现，性能，功耗的方面优势和不足，请问当时你们是用的那种方案？
模型像带有Proposal的模型，最后这模型是两个wk还是一个



### 编译linux-armv7-himix200的库

`TARGET_OS=linux TARGET_ARCH=armv7 TARGET_CPU_TYPE=himix200 cppbuild  build --build-type=release --install`

如果是新的sdk_model v2.11 需要作如下更改
1. sdk_license include protector.h 中的98行更改为`#elif __arm__ && (__ANDROID__ || (__linux__ && !HISI_VERSION))`，因为当前APP_PROTECTOR不支持linux-armv7-hisi
2. sdk_framework src/neon/neon_array中第4行，更改为`#if !defined(HIMIX_VERSION) && defined(USE_NEON) && !defined(__aarch64__)`，因为当前himix200的交叉编译连不支持PLD指令。
```bash
/tmp/cczbLCYC.s: Assembler messages:
/tmp/cczbLCYC.s:145: Error: selected processor does not support `pld [r3,#0x100]' in ARM mode
/tmp/cczbLCYC.s:310: Error: selected processor does not support `pld [r2,#0x100]' in ARM mode
/tmp/cczbLCYC.s:311: Error: selected processor does not support `pld [r3,#0x100]' in ARM mode
/tmp/cczbLCYC.s:454: Error: selected processor does not support `pld [r3,#0x100]' in ARM mode
```
pld预读取指令，pld指令只在armv5以上版本有效。
功能：cache预读取（PLD,PreLoad），使用pld指示存储系统从后面几条指令所指定的存储器地址读取，存储系统可使用这种方法加速以后的存储器访问。
格式：pld[Rn,{offset}]
显然在linux-armv7-himix200的交叉编译链中不支持该指令

3. st_imagehelper中的jpeg.cpp中的abs -> std::fabs
4. rm -rf src/PPL_ext， 减去对ppl的依赖


## 一些指令优化参考

* [memcpy 在ARM上的优化](https://www.jianshu.com/p/7b3bfc3aed12)

* []()https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_cv&expand=1286,1704,1443

* https://developer.arm.com/architectures/instruction-sets/simd-isas/neon/intrinsics


# 附录
![Alt text](./1552047432837.png)


## 海思Hi3559A有哪些优势
1、拼接全景摄像机开发方向(支持条带，半球，全球拼接)

可以提供高效的机内拼接全景/VR的视频采集设备产品方案，提供给设备商极高性价比的一个选择；

2、人工智能设备开发方向

解决了当前芯片进一步开发的计算力瓶颈问题，目前产品只能是低级别的海思芯片+协处理器的方式，无法做到较大分辨率的分析以及高速的信息交互，另外成本也较高。

3、深度学习算法方面

支持NNIE神经网络加速处理的硬件单元(须是Caffe框架)，目前竞争对象是NVDIA的TX1， 而海思在安防行业的沉淀让此方案在视频采集，编码更加具备竞争力， 另外国产芯片目前正处在市场上升期，前景乐观。

4、机器人产品开发方向

DSP支持的双目深度检测可以复原人眼的视觉效果，加上强大的算力， 足以支撑特定领域的机器人开发。

5、无人机产品开发方向

从SENSOR_HUB的描述来看， 芯片的定位之一就是无人机的控制

6、运动相机&全景的行车记录仪产品开发方向

高宽动态加全景拼接可以让这两个领域的产品发生质的改变，可预见将出现技术推动产品迭代的情景。

![Alt text](./1552042170052.png)
![Alt text](./1552042183399.png)


## NNIE 加速引擎特性如下：
- 支持 N * N 注 1 卷积
- 支持 Pooling（Max 和 Average） 
- 支持 Stride 注 2
- 支持 Pad 
- 支持激活函数（Relu、Sigmoid 和 TanH）
- 支持 LRN 运算
- 支持 BN(Batch Normalization) 
- 支持向量与矩阵的乘加运算(Inner Product) 
- 支持 Concat 
- 支持 Eltwise 
- 支持 8bit 的数据与参数模式
- 支持数据与参数位宽可配置
- 支持参数压缩和参数稀疏
- 支持输入图像为单通道（灰度图）和三通道（RGB 格式）
- 支持图像预处理(均值化和像素值缩放) 
- 支持图像批处理
- 支持中间层结果上报 
注 1：N * N 表示卷积框为正方形状。
注 2：此处 Stride 特指神经网络专用术语

## 其他参考链接
https://zhuanlan.zhihu.com/p/44814586
[芯片春秋-ARM传](https://mp.weixin.qq.com/s?__biz=MzI1NTA0MDUyMA==&mid=2456660188&idx=1&sn=b9dafaa60e10130442aac48f165800f7&chksm=fda505bbcad28cad9e38e3394e4e58132f5a81a030f1adb7fa327f50f7c6957f485a2a5fa9b9&scene=21#wechat_redirect) 

## NNIE编译相关的问题
nnie使用的编译器是gcc 6.3.0版本.

/home/sensetime/Repo/sdk_common/deps/sdk_license/include/gcc_fix.hpp: In function ‘void __cxa_throw_bad_array_new_length()’:
/home/sensetime/Repo/sdk_common/deps/sdk_license/include/gcc_fix.hpp:74:1: warning: new declaration ‘void __cxa_throw_bad_array_new_length()’ ambiguates built-in declaration ‘sizetype __cxa_throw_bad_array_new_length()’
 __cxa_throw_bad_array_new_length()

`__cxa_throw_bad_array_new_length` was added in GCC 4.9. That's what the @CXXABI_1.3.8 version suffix means. You can look up those version codes here: https://gcc.gnu.org/onlinedocs/libstdc++/manual/abi.html

This error means that you are trying to link an object file /usr/lib64/vtk/libvtkCommonDataModel.so.1 compiled by GCC 4.9 or later with libstdc++.so or libsupc++.so from GCC 4.8 or earlier. Either rebuild libvtkCommonDataModel.so with GCC 4.8, or link against the correct libstdc++.so.

Edit: Actually, if you want to compile with a newer version of GCC but run with an older libstdc++.so, that can be done.

Compile with `-D_GLIBCXX_USE_CXX11_ABI=0` if you want to compile with GCC 5+ and run with libstdc++.so from older GCC. See https://bugzilla.mozilla.org/show_bug.cgi?id=1153109 and Using dual ABI in the libstdc++ manual.

Link against stdc++compat.cpp containing back-compat hacks from Mozilla. You can also take a look at my modified version which doesn't depend on any Mozilla headers, but it's slightly out of date. In particular, this defines a stub `__cxa_throw_bad_array_new_length`.


himix200是可以进行APP_PROTECTOR加密的.
