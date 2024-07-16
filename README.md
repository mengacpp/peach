# [peach](https://github.com/mengadev/peach)
Peach is a game engine im developing on my own, in the future you will find **Devlogs at my [YouTube channel](https://www.youtube.com/@MengaWasTaken)**.

## Index

1. **[Building](#building)**
2. **About Peach** *⚠️ coming soon*
3. **Getting started** *⚠️ coming soon*

## 1. Building

### 1.1 Dependencies

Libraries you need to install before building the project:
- *[glfw](https://github.com/glfw/glfw)*
- *[GLEW](https://github.com/nigels-com/glew)*

---
Other libraries used in the project but provided by the repostory as submodules:

- *[DearImGui](https://github.com/ocornut/imgui)*
 
### 1.2 Building the project

After making sure you have all the [dependencies required](#dependencies), **clone the repo** on your hard disk *making sure to init the submodules*:

```bash
git clone --recurse-submodules https://github.com/mengadev/peach.git
```

now just `cd` into the directory and **use CMake to build the project**:

```bash
mkdir build
cd build
cmake ..
```

