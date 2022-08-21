#pragma once
#ifndef TORMENTA_API_HPP
#define TORMENTA_API_HPP

#ifdef _WIN32

#define TORMENTA_DLL_EXPORT __declspec(dllexport)
#define TORMENTA_DLL_IMPORT __declspec(dllimport)

#else //_WIN32

#define TORMENTA_DLL_EXPORT
#define TORMENTA_DLL_IMPORT

#endif //_WIN32

#ifdef TORMENTA_EXPORTS

#define TORMENTA_API TORMENTA_DLL_EXPORT

#else //TORMENTA_EXPORTS

#define TORMENTA_API TORMENTA_DLL_IMPORT

#endif //TORMENTA_EXPORTS

#endif //TORMENTA_API_HPP
