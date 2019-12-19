# INTRODUCTION TO ALGORITHM
Before there were computers, there were algorithms. But now that there are computers, there are even more algorithms, and algorithms lie at the heart of computing.

## Chapter 1
- [insert sort](src/sort.cpp)
- [merge sort](src/sort.cpp)
- [gcb(辗转相除法，欧几里得算法)](src/buLec01.cpp)

## Chaper 2

- [exist target sum in array](src/ch2.cpp)
- [统计逆序数](src/ch2.cpp)

<!-- ## 递归
- gcd
- 汉诺塔 -->

## Divide and Conquer
- [统计逆序数](src/ch2.cpp)

## DP
- [最小编辑距离](src/editdist.cpp)
    - 递归方法
    - 矩阵递推法
    - 矩阵递推法改进版（仅仅使用一个向量实现递推，减少空间）
- [最少换乘消费]

## Time analysis
时间复杂度分析中常见的三个表示时间的符号$\Theta$, $O$, $\Omega$, 如下图所示：
![@时间复杂度表示符号](./images/TimeAnalysis.png)
从图中可以出$f(n) = O(g(n))$表示存在常数$c$,当$n > n_0$之后，始终有$f(n) < cg(n)$, 也就说$O$定义了一个上限，这也是三个中最常用的符号。

## 递归表达式 => 时间复杂度分析
- substituion method
- recursion-tree method
- master method

## CMake 

工欲善其事必先利其器。CMake学习项目，`cmaketest`

## HOW TO RUN
`mkdir build && cd build`
`cmake -DTEST=1 .. && make -j4 && make install`
`./test_practise`

## Email: caowenlong92@gmail.com

其他用途： 这个包含基本的C++的项目的开发要件，只要稍微对其中的`CMakeLists.txt`进行更改就可以适配到自己的项目中。
项目主要内容包括，
```
.
├── 3rdparty                # 第三方依赖库，主要为gtest
│   ├── gtest
│   └── README.txt
├── CMakeLists.txt          # CMake脚本
├── include                 # 放置头文件
│   ├── buLec01.h
│   ├── ch1.h
│   ├── ch2.h
│   ├── mBinaryTree.h
│   ├── mlist.h
│   ├── practise.h
│   ├── time_helper.h
│   └── cf_util.h
├── src                    # 放置源码文件
│   ├── buLec01.cpp
│   ├── ch2.cpp
│   ├── mBinaryTree.cpp
│   ├── mlist.cpp
│   └── sort.cpp
└── test                   # 测试用例
    ├── test_all.cpp
    ├── test_api.cpp
    ├── test_api.h
    ├── test_buLec01.cpp
    ├── test_ch1.cpp
    ├── test_ch2.cpp
    ├── test_mbtree.cpp
    └── test_mlist.cpp
```
其中只需要对所在文件夹名称和CMakeLists.txt进行相应的改动，就可以重新开辟新的项目。
更多第三方库，可以参考项目[LibsForDev](https://github.com/cwlseu/LibsForDev)


## FAQ
1. `Error expected initializer before 'int'` 或者
In file included from /usr/include/features.h:374:0,
                 from /usr/include/x86_64-linux-gnu/c++/4.9/bits/os_defines.h:39,
                 from /usr/include/x86_64-linux-gnu/c++/4.9/bits/c++config.h:430,
                 from /usr/include/c++/4.9/string:38,
                 from /home/sensetime/Repo/IntroductionToAlgorithm/include/editdist.h:3,
                 from /home/sensetime/Repo/IntroductionToAlgorithm/src/editdist.cpp:1:
/usr/include/string.h:27:1: error: expected initializer before ‘extern’
 __BEGIN_DECLS
 ^
In file included from /usr/lib/gcc/x86_64-linux-gnu/4.9/include/x86intrin.h:27:0,
                 from /usr/include/x86_64-linux-gnu/c++/4.9/bits/opt_random.h:33,
                 from /usr/include/c++/4.9/random:50,
                 from /usr/include/c++/4.9/bits/stl_algo.h:66,
                 from /usr/include/c++/4.9/algorithm:62,
                 from /home/sensetime/Repo/IntroductionToAlgorithm/src/editdist.cpp:6:
/usr/lib/gcc/x86_64-linux-gnu/4.9/include/ia32intrin.h:53:25: error: expected declaration before end of line
 #pragma GCC push_options
                         ^

可能是你在函数定义的地方少写了";"[^1]

[^1]: http://www.cplusplus.com/forum/general/108022/
