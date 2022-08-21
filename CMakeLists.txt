cmake_minimum_required(VERSION 3.21)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Tormenta
        VERSION 0.1.0.0
        DESCRIPTION ""
        HOMEPAGE_URL "https://github.com/felipegodias/TormentaEngine"
        LANGUAGES CXX
)

message("Using compiler '${CMAKE_CXX_COMPILER_ID}' version '${CMAKE_CXX_COMPILER_VERSION}'")

set(GNU_MIN_VERSION "7.0")
set(MSVC_MIN_VERSION "19.14")
set(Clang_MIN_VERSION "6.0")
set(AppleClang_MIN_VERSION "10.0")

if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${${CMAKE_CXX_COMPILER_ID}_MIN_VERSION})
    message(FATAL_ERROR "Insufficient ${CMAKE_CXX_COMPILER_ID} version. Minimum Required is ${${CMAKE_CXX_COMPILER_ID}_MIN_VERSION}!")
endif()

set(MSVC_COMPILER_OPTIONS /W4 /WX /permissive-)
set(GCC_COMPILER_OPTIONS -Wall -Wextra -Werror)
set(Clang_COMPILER_OPTIONS -Wall -Wextra -Werror)
set(AppleClang_COMPILER_OPTIONS -Wall -Wextra -Werror)

add_compile_options(${${CMAKE_CXX_COMPILER_ID}_COMPILER_OPTIONS})

include("ThirdParty/vcpkg.cmake")

add_subdirectory("Src")

include(CPack)
