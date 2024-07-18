# [peach](https://github.com/mengadev/peach)
Peach is a game engine im developing on my own, in the future you will find **Devlogs on my [YouTube channel](https://www.youtube.com/@MengaWasTaken)**.

## Index

1. **[Building Peach](#1-building)**
2. **[About Peach](#2-about-peach)** *
3. **[Getting started](#3-getting-started)** *

## 1. Building

### 1.1 Dependencies

To build the project, ensure you have **[CMake](https://cmake.org)** and **[make](https://www.gnu.org/software/make/)** installed on your device.

You'll also need to install the following libraries:

- *[glfw](https://github.com/glfw/glfw)*
- *[GLEW](https://github.com/nigels-com/glew)*

Other required libraries are provided by the repository as submodules:

- *[Dear ImGui](https://github.com/ocornut/imgui)*

You don't need to install these separately.
 
### 1.2 Building the project

After ensuring you have all the [required dependencies](#11-dependencies), clone the repository on your hard disk. Make sure to initialize the submodules:

```bash
git clone --recurse-submodules https://github.com/mengadev/peach.git
```

Next, navigate to the project directory **and use CMake and make to build and install Peach** on your device. It will look something like this:

```bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make install
```
This will compile and build the Peach game engine library aswell as Peachtree, the editor.

## 2. About Peach

Not much to say yet

## 3. Getting started

Not much to say yet