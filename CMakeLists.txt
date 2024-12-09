cmake_minimum_required(VERSION 3.29)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled2 src/main.cpp
        src/render/Window.cpp
        src/input/key_input.cpp
        src/input/mouse_input.cpp
        include/key_input.h
        include/mouse_input.h
        include/Window.h
        src/render/mesh/circle.cpp
        include/circle.h
        src/render/shader/shader.cpp
        include/shader.h
        include/structs.h
)

target_link_libraries(untitled2 glfw3 glm glad freetype z)
