# Github repository for a Go game score counter

Project of a score counter for the asian game of "Go".
This project is partly created for me to learn C++, DearImGUI and GLFW with Vulkan.

- GLFW uses Vulkan to open windows
- Dear ImGui can create buttons, trees, and general graphics.

To include them, I added GLFW as a git submodule, and just manually added the ImGui files from the `docking` branch.

To clone the submodule as well when cloning this repository, use the command

```
git clone --recursive https://github.com/Physis21/go-score-counter-vulkan.git
```

## About the 3rd party libraries in `vendor/`

- (**not included**) [OpenGL3](https://en.wikipedia.org/wiki/OpenGL) (Open Graphics Library) is an API used to render 2D or 3D graphics. It directly talks to the GPU.
- [Vulkan](https://en.wikipedia.org/wiki/Vulkan) is a cross-platform API and open standard for 3D graphics and computing. It was intended to address the shortcomings of OpenGL, and allow developers more control over the GPU. It is designed to support a wide variety of GPUs, CPUs and operating systems, and modern multi-core CPUs also.
- [GLFW](https://github.com/glfw/glfw) is an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan application development. It provides a simple, platform-independent API for creating windows, contexts and surfaces, reading input, handling events, etc.
- [Dear ImGui](https://github.com/ocornut/imgui) is a bloat-free graphical user interface library for C++. It outputs optimized vertex buffers that you can render anytime in 3D-pipeline-enabled applications. It is fast, portable, renderer agnostic, and self-contained (no external dependencies)
  - I use the docking branch of ImGui in order to enable dockable windows.

## Compiling and running

1. To set the build configuration, first run:

```bash
cmake -S . -B build
```

2. To build the application, run

```bash
cmake --build build
```

3. To run the generated binary file, run:

```bash
./build/bin/go_score_counter
```

Instead, you could sequentially run the `configure.sh`, `build.sh` and `run.sh` bash scripts.

## Unit tests

I use [googletest](https://github.com/google/googletest) to test my `go_board` library. It is also added as a git submodule in `vendor/`.

The unit tests are registered using CMake. To run the tests, run:

```bash
cd build && ctest
```

Instead, run the `./test.sh` script.

## Contact

If you have any questions, contact me at juliendudas[(at)]gmail.com
