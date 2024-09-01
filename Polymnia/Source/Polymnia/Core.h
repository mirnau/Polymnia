#pragma once

#ifdef PL_PLATFORM_WINDOWS
	#ifdef PL_BUILD_DLL
		#define POLYMNIA_API __declspec(dllexport)
	#else
		#define POLYMNIA_API __declspec(dllimport)
	#endif
#else
	#error Polymnia only supports Windows
#endif
