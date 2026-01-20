set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenGL REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Create template executable.
add_executable(example_glfw_opengl template_main.cpp)
target_link_libraries(example_glfw_opengl
  PRIVATE
    glfw
    OpenGL::OpenGL
    imgui
)

# Create app.
add_executable(go_score_counter go_score_counter.cpp application.cpp)
target_sources(go_score_counter
  PRIVATE
    go_score_counter.cpp
    application.cpp
)
target_link_libraries(go_score_counter
  PRIVATE
    glfw
    OpenGL::OpenGL
    stb_image
    imgui
    go_board
)
