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

set(MSVC_COMPILER_OPTIONS /wd4251 /wd4275 /W4 /WX /permissive-)
set(GCC_COMPILER_OPTIONS -Wall -Wextra -Werror)
add_compile_options("$<IF:$<CXX_COMPILER_ID:MSVC>,${MSVC_COMPILER_OPTIONS},${GCC_COMPILER_OPTIONS}>")

include("ThirdParty/vcpkg.cmake")

add_subdirectory("Src")

include(CPack)
