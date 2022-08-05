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
    <a href="https://www.codacy.com/gh/felipegodias/TormentaEngine/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=felipegodias/TormentaEngine&amp;utm_campaign=Badge_Grade">
        <img src="https://app.codacy.com/project/badge/Grade/af2f347264344c658b47d2eba05dd33c"/>
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
    <img src="https://media.githubusercontent.com/media/felipegodias/TormentaEngine/master/Resources/logo.png" alt="Logo" width="128" height="128"/>
    <h1 align="center">Tormenta Engine</h1>
</div>

## Requirements

All third party libraries will be installed automatically via <a href="https://github.com/microsoft/vcpkg">vcpkg</a>.

### Supported Toolchains

| Compiler      | Generator | Standard Library | Test Environment   |
| :------------ | :-------- | :--------------- | :----------------- |
| GCC >= 7.0    | Ninja     | libstdc++        | Ubuntu 20.04       |
| Clang >= 6.0  | Ninja     | libc++           | Xcode 13.4.1       |
| MSVC >= 19.14 | Ninja     | Microsoft STL    | Visual Studio 2022 |

## How to Build

```bash
git clone --recurse-submodules git@github.com:felipegodias/TormentaEngine.git
```

Use one of the following presets along with CMake.

### Presets

-   Windows
    -   windows-msvc-debug
    -   windows-msvc-release
    -   windows-clang-debug
    -   windows-clang-release

-   Linux
    -   linux-gcc-debug
    -   linux-gcc-release
    -   linux-clang-debug
    -   linux-clang-release

-   MacOS
    -   mac-clang-debug
    -   mac-clang-release

```bash
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug --target install
```

<!-- LICENSE -->

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<!-- CONTACT -->

## Contact

Felipe Dias - [@felipegodias](https://twitter.com/felipegodias) - felipe.g.o.dias@outlook.com

Project Link: <https://github.com/felipegodias/TormentaEngine>
