#pragma once

#if defined(_WIN32) || defined(_WIN64)
#ifdef KATZU_BUILD_DLL
#define KATZU_API __declspec(dllexport)
#else
#define KATZU_API __declspec(dllimport)
#endif
#else
#define KATZU_API
#endif
