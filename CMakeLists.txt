cmake_minimum_required(VERSION 3.10)
project(MusicPlayer)

set(CMAKE_CXX_STANDARD 17)

# Add Dear ImGui directory
add_subdirectory(extern/imgui)
add_subdirectory(extern/glfw)
add_library(glad STATIC extern/glad/src/glad.c)
target_include_directories(glad PUBLIC extern/glad/include)
# add_library(imgui_impl_glfw STATIC
#     extern/imgui/backends/imgui_impl_glfw.cpp
# )
# target_include_directories(imgui_impl_glfw PUBLIC extern/imgui/backends)

# add_library(imgui_impl_opengl3 STATIC
#     extern/imgui/backends/imgui_impl_opengl3.cpp
# )
# target_include_directories(imgui_impl_opengl3 PUBLIC extern/imgui/backends)
add_library(imgui STATIC
    extern/imgui/imgui.cpp
    extern/imgui/imgui_demo.cpp
    extern/imgui/imgui_draw.cpp
    extern/imgui/imgui_tables.cpp
    extern/imgui/imgui_widgets.cpp
    extern/imgui/backends/imgui_impl_glfw.cpp
    extern/imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC extern/imgui)


find_package(SFML 2.5 REQUIRED graphics window system)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
# Define the target executable
add_executable(${PROJECT_NAME}
    source/main.cpp
    source/MusicPlayerUI.cpp
    source/AudioService.cpp
    source/PlaylistManager.cpp
)

# Set include directories for the target
target_include_directories(${PROJECT_NAME} PRIVATE
    extern/imgui
    extern/imgui/backends
    extern/glfw/include
    extern/glad/include
    ${SFML_INCLUDE_DIR}
    inc
)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    glad
    imgui
    # imgui_impl_glfw
    # imgui_impl_opengl3
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    glfw
    OpenGL::OpenGL
    dl
)

