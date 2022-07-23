#pragma once

#ifdef _WIN32

#ifdef TORMENTA_EXPORTS

#define TORMENTA_API __declspec(dllexport)

#else

#define TORMENTA_API __declspec(dllimport)

#endif

#else

#define TORMENTA_API

#endif
