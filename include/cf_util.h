/*************************************************************************
	> File Name: cv_util.h
	> Author: caowenlong
	> Mail: caowenlong92@gmail.com 
	> Created Time: 2019年07月31日 星期三 20时02分18秒
 ************************************************************************/
#ifndef CODEFEELING_UTIL_H_
#define CODEFEELING_UTIL_H_
typedef int errcode_t;


#define CF_ERR_PACK(module, reason)	\
	((int)( 0x80000000 | ((unsigned int)(module) & 0x7fff) << 16 | ((unsigned int)(reason) & 0xffff)))

#define CF_E_GLOBAL_MODULE 0x7fff

#define CF_OK								0			///< 正常运行
#define CF_E_INVALIDARG						CF_ERR_PACK(CF_E_GLOBAL_MODULE, 0xffff)  ///< 无效参数 -1
#define CF_E_OUTOFMEMORY					CF_ERR_PACK(CF_E_GLOBAL_MODULE, 0xfffe)  ///< 内存不足 -2
#define CF_E_FILE_NOT_FOUND					CF_ERR_PACK(CF_E_GLOBAL_MODULE, 0xfffd)  ///< 文件不存在 -3
#define CF_E_FAIL							CF_ERR_PACK(CF_E_GLOBAL_MODULE, 0xfffc)  ///< 运行失败，内部错误 -4
#define CF_E_PLATFORM_NOTSUPPORTED			CF_ERR_PACK(CF_E_GLOBAL_MODULE, 0xfffb)  ///< 不支持的平台 -5

typedef struct cf_rect_t {
	int left;
	int top;
	int right;
	int bottom;
} cf_rect_t;

#endif