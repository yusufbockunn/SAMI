#pragma once


#ifdef SM_PLATFORM_WINDOWS
	#ifdef SM_BUILD_DLL
		#define SAMI_API __declspec(dllexport)
	#else
		#define SAMI_API __declspec(dllimport)
	
	#endif
#else
#error SAMI only support Windows(x64)!

#endif