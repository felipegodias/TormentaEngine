cmake_minimum_required(VERSION 3.21)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

set(CMAKE_VERBOSE_MAKEFILE ON)
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

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "7.0")
        message(FATAL_ERROR "Insufficient GCC version. Minimum Required is 7.0!")
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "19.14")
        message(FATAL_ERROR "Insufficient MSVC version. Minimum required is 19.14!")
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "6.0")
        message(FATAL_ERROR "Insufficient Clang version. Minimum required is 6!")
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "10.0")
        message(FATAL_ERROR "Insufficient AppleClang version. Minimum required is 10.0!")
    endif()
else()
    message(FATAL_ERROR "Compiler not supported!")
endif()

set(MSVC_COMPILER_OPTIONS /W4 /WX /permissive-)
set(GCC_COMPILER_OPTIONS -Wall -Wextra -Werror)
add_compile_options("$<IF:$<CXX_COMPILER_ID:MSVC>,${MSVC_COMPILER_OPTIONS},${GCC_COMPILER_OPTIONS}>")

include("ThirdParty/vcpkg.cmake")

add_subdirectory("Src")

include(CPack)
