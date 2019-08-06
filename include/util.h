#ifndef ALGORITHM_UTIL_H_
#define ALGORITHM_UTIL_H_
typedef int errcode_t;

#define CF_OK 0                                         ///< 正常运行
#define CF_E_INVALIDARG                     0xffffffff  ///< 无效参数 -1
#define CF_E_OUTOFMEMORY                    0xfffffffe  ///< 内存不足 -2
#define CF_E_FILE_NOT_FOUND                 0xfffffffd  ///< 文件不存在 -3
#define CF_E_FAIL                           0xfffffffc  ///< 运行失败，内部错误 -4
#define CF_E_PLATFORM_NOTSUPPORTED          0xfffffffb  ///< 不支持的平台 -5


#endif