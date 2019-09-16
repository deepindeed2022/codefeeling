#ifndef CODEFEELING_MACRO_H_
#define CODEFEELING_MACRO_H_
#include <cstdio>
#include <cstring>
#if defined __GNUC__
  #define CF_Func __func__
#elif defined _MSC_VER
  #define CF_Func __FUNCTION__
#else
  #define CF_Func ""
#endif

#define ERROR_INFO(errorStr, _err, _func)						\
{																\
	char buf[1 << 16];											\
	sprintf(buf, "CF Error: %s (%s), file %s, line %s",	\
			errorStr, _err , __FILE__, std::to_string(__LINE__).c_str());	\
	fprintf(stderr, "%s\n", buf);								\
	fflush(stderr);												\
}

#ifndef CF_ENABLE_ASSERT
	#error "CF_ENABLE_ASSERT is not defined"
#else
	#if CF_ENABLE_ASSERT
		#define CF_Error(code, msg) ERROR_INFO(code, msg, CF_Func)
		#define CF_ASSERT_MSG(expr)  if(!!(expr)); else ERROR_INFO("Assertion failed", expr, CF_Func)
		#define CF_ASSERT(x) CF_ASSERT_MSG(x)
	#else
		#define CF_ASSERT(x) static_cast<void>(sizeof(x))
		#define CF_Error(code, msg) ERROR_INFO(code, msg, CF_Func)
	#endif
#endif

#define CF_CUDA_CK(x) \
	do { \
		cudaError_t status_cuda = (x); \
		if (status_cuda != cudaSuccess) { \
			fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, cudaGetErrorString(status_cuda)); \
		} \
		CF_ASSERT(cudaSuccess == status_cuda); \
	} while (0)

#endif