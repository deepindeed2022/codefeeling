#ifndef ALGORITHM_UTIL_H_
#define ALGORITHM_UTIL_H_
typedef int errcode_t;

#define CC_OK 0                                         ///< 正常运行
#define CC_E_INVALIDARG                     0xffffffff  ///< 无效参数 -1
#define CC_E_OUTOFMEMORY                    0xfffffffe  ///< 内存不足 -2
#define CV_E_FILE_NOT_FOUND                 0xfffffffd  ///< 文件不存在 -3
#define CC_E_FAIL                           0xfffffffc  ///< 运行失败，内部错误 -4
#define CC_E_PLATFORM_NOTSUPPORTED          0xfffffffb  ///< 不支持的平台 -5


#endif