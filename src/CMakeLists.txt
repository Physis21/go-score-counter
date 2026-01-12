set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Create template executable.
add_executable(example_glfw_vulkan template_main.cpp)
target_link_libraries(example_glfw_vulkan
  PRIVATE
    glfw
    Vulkan::Vulkan
    imgui
)

# Create app.
add_executable(go_score_counter go_score_counter.cpp application.cpp)
target_link_libraries(go_score_counter
  PRIVATE
    glfw
    Vulkan::Vulkan
    imgui
    go_board
)
