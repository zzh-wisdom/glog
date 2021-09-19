# Google Logging Library

## Building from Source

glog 支持多个构建系统，用于从源头编译项目：巴泽尔、CMake 和 vcpkg。

### CMake

glog 还支持可用于在各种平台上构建项目的 CMake。如果您尚未安装 CMake，您可以从 [CMake 的官方网站](http://www.cmake.org/)下载。

CMake 的工作原理是生成原生 `makefile` 或构建可在您选择的编译器环境中使用的项目。您可以使用 CMake 将 glog  构建为独立项目，也可以将其整合到其他项目的现有 CMake 构建中。

#### 使用 Cmake 构建 glog

当将 glog 构建为独立项目时，在以 GNU Make 作为构建工具的 Unix 系统上，典型的工作流程是：

1. 获取代码

```shell
git clone https://github.com/google/glog.git
cd glog
```

2. 运行 CMake 来配置构建树。

```shell
cmake -S . -B build -G "Unix Makefiles"
cmake -S . -B build # 自动选择生成器
```

CMake 提供不同的生成器，默认情况下，它会选择与您的环境最相关的生成器。如果您需要特定版本的Visual Studio，请使用 `cmake . -G <generator-name>`，并查看 `cmake --help` 找到可用的生成器。另见 `-T <toolset-name>`，可用于请求具有 -T host=x64 的原生 x64 工具链。

3. 之后，生成的文件可用于编译项目。

```shell
cmake --build build
```

4. 测试构建软件（可选）

```shell
cmake --build build --target test
```

5. 安装已建文件（可选）。

```shell
sudo cmake --build build --target install
```

安装log：

```shell
[0/1] Install the project...
-- Install configuration: "Debug"
-- Installing: /usr/local/lib/libglogd.so.0.6.0
-- Installing: /usr/local/lib/libglogd.so.1
-- Installing: /usr/local/lib/libglogd.so
-- Installing: /usr/local/include/glog/export.h
-- Installing: /usr/local/include/glog/logging.h
-- Installing: /usr/local/include/glog/raw_logging.h
-- Installing: /usr/local/include/glog/stl_logging.h
-- Installing: /usr/local/include/glog/vlog_is_on.h
-- Installing: /usr/local/include/glog/log_severity.h
-- Installing: /usr/local/lib/pkgconfig/libglog.pc
-- Installing: /usr/local/lib/cmake/glog/glog-modules.cmake
-- Installing: /usr/local/lib/cmake/glog/glog-config.cmake
-- Installing: /usr/local/lib/cmake/glog/glog-config-version.cmake
-- Installing: /usr/local/lib/cmake/glog/glog-targets.cmake
-- Installing: /usr/local/lib/cmake/glog/glog-targets-debug.cmake
```

自己写了一个 `卸载` 的命令：

```shell
sudo rm -rf /usr/local/lib/libglog*
sudo rm -rf /usr/local/include/glog
sudo rm -f /usr/local/lib/pkgconfig/libglog.pc
sudo rm -rf /usr/local/lib/cmake/glog
```

#### 在 Cmake 项目中使用 glog

> 简单使用样例：g++ --std=c++11  -o build/basic basic.cc  -lglog

如果您的系统中安装了 glog，您可以使用 CMake 命令find_package在你的 CMake 项目中构建 glog，具体如下：

```cmake
cmake_minimum_required (VERSION 3.0.2)
project (myproj VERSION 1.0)

find_package (glog 0.6.0 REQUIRED)

add_executable (myapp main.cpp)
target_link_libraries (myapp glog::glog)

```

根据需要，编译定义和选项将自动添加到目标中。

#### 将 glog 纳入 CMake 项目

您还可以使用 CMake 命令`add_subdirectory`，通过将上一示例中的find_package调用替换为add_subdirectory，直接从项目子目录加入 glog。

## User Guide

