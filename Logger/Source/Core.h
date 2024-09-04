#pragma once

#ifdef PL_PLATFORM_WINDOWS
    #ifdef LOG_BUILD_DLL
        #define LOG_TOOL_API __declspec(dllexport)
    #else
        #define LOG_TOOL_API __declspec(dllimport)
    #endif
    #else
    #error Unsupported OS Environment
#endif