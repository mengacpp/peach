#pragma once

#ifdef _WIN32
    #ifdef PH_CORE
        #define PEACH_API __declspec(dllexport)
    #else
        #define PEACH_API __declspec(dllimport)
    #endif
#elif defined(__APPLE__)
    #define PEACH_API __attribute__((visibility("default")))
#else
    #define PEACH_API
#endif
