<p align="center">
    <a href="https://github.com/felipegodias/TormentaEngine/graphs/contributors">
        <img src="https://img.shields.io/github/contributors/felipegodias/TormentaEngine.svg"/>
    </a>
    <a href="https://github.com/felipegodias/TormentaEngine/network/members">
        <img src="https://img.shields.io/github/forks/felipegodias/TormentaEngine.svg"/>
    </a>
    <a href="https://github.com/felipegodias/TormentaEngine/stargazers">
        <img src="https://img.shields.io/github/stars/felipegodias/TormentaEngine.svg"/>
    </a>
    <a href="https://github.com/felipegodias/TormentaEngine/issues">
        <img src="https://img.shields.io/github/issues/felipegodias/TormentaEngine.svg"/>
    </a>
    <a href="https://github.com/felipegodias/TormentaEngine/blob/master/LICENSE.txt">
        <img src="https://img.shields.io/github/license/felipegodias/TormentaEngine.svg"/>
    </a>
    <a href="https://www.linkedin.com/in/felipegodias">
        <img src="https://img.shields.io/badge/-LinkedIn-black.svg?logo=linkedin&colorB=1182c3"/>
    </a>
</p>

<p align="center">
    <a href="https://github.com/felipegodias/TormentaEngine/actions/workflows/windows_msvc_build.yml">
        <img src="https://github.com/felipegodias/TormentaEngine/actions/workflows/windows_msvc_build.yml/badge.svg"/>
    </a>
    <a href="https://github.com/felipegodias/TormentaEngine/actions/workflows/windows_clang_build.yml">
        <img src="https://github.com/felipegodias/TormentaEngine/actions/workflows/windows_clang_build.yml/badge.svg"/>
    </a>
</p>

<p align="center">
    <a href="https://github.com/felipegodias/TormentaEngine/actions/workflows/linux_gcc_build.yml">
        <img src="https://github.com/felipegodias/TormentaEngine/actions/workflows/linux_gcc_build.yml/badge.svg"/>
    </a>
    <a href="https://github.com/felipegodias/TormentaEngine/actions/workflows/linux_clang_build.yml">
        <img src="https://github.com/felipegodias/TormentaEngine/actions/workflows/linux_clang_build.yml/badge.svg"/>
    </a>
</p>

<p align="center">
    <a href="https://github.com/felipegodias/TormentaEngine/actions/workflows/mac_clang_build.yml">
        <img src="https://github.com/felipegodias/TormentaEngine/actions/workflows/mac_clang_build.yml/badge.svg"/>
    </a>
</p>

<div align="center">
    <img src="https://imgur.com/AUIYWVg.png" alt="Logo" width="128" height="130"/>
    <h1 align="center">Tormenta Engine</h1>
</div>

## Requirements
All third party libraries will be installed automatically via <a href="https://github.com/microsoft/vcpkg">vcpkg</a>.

### Windows
* MSVC 19 or Clang 10
* Ninja
### Linux
* GCC 9 or Clang 10
* Ninja
```
> sudo ./instal_linux_requirements.sh
```
### MacOS
* Apple Clang 10
* Ninja
```
> ./instal_mac_requirements.sh
```

## How to Build
Use one of the following presets along with CMake.

### Presets
* Windows
    * windows-msvc-debug
    * windows-msvc-release
    * windows-clang-debug
    * windows-clang-release
* Linux
    * linux-gcc-debug
    * linux-gcc-release
    * linux-clang-debug
    * linux-clang-release
* MacOS
    * mac-clang-debug
    * mac-clang-release

```
> cmake --preset windows-msvc-debug
> cmake --build --preset windows-msvc-debug --target install
```

<!-- LICENSE -->
## License
Distributed under the MIT License. See `LICENSE.txt` for more information.

<!-- CONTACT -->
## Contact

Felipe Dias - [@felipegodias](https://twitter.com/felipegodias) - felipe.g.o.dias@outlook.com

Project Link: [https://github.com/felipegodias/TormentaEngine](https://github.com/felipegodias/TormentaEngine)