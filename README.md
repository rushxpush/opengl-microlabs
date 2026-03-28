# OpenGL Microlabs

Using this repo to study c/c++ and OpenGL.

# Set project

```bash
# Install GLFW
sudo apt install libglfw3 libglfw3-dev libx11-dev libxrandr-dev libxi-dev

# Other libraries
sudo apt install build-essential cmake libgl1-mesa-dev libglu1-mesa-dev

# GLAD
```

# Compiling

```bash
gcc ./src/main.c ./lib/glad.c -Iinclude -o ./bin/main -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
```

## Tutoring

```bash
# 01 - Hello Window
g++ src/open_gl_tutorial/01_hello_window.cpp ./lib/glad.c -Iinclude -o ./bin/main -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

# 02 - Hello Triangle
g++ src/open_gl_tutorial/02_hello_triangle.cpp ./lib/gla
d.c -Iinclude -o ./bin/main -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
```
