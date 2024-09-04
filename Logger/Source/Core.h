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

#ifdef PL_DEBUG

// This part of the memory leak detection detects within dll.
// The result is printed from the EntryPoint.h in Polymnia


    #define _CRTDBG_MAP_ALLOC
    #include <cstdlib>
    #include <crtdbg.h>
    
    class MemoryLeakDetector
    {
    public:
        MemoryLeakDetector()
        {
            _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
        }
    };
    
    static MemoryLeakDetector memoryLeakDetector;

#endif