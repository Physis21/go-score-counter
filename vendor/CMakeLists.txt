# GLFW
option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)
add_subdirectory(glfw binary_dir EXCLUDE_FROM_ALL)
include_directories(glfw/include)

# Use vulkan headers from glfw:
# (Maybe I don't need this anymore)
include_directories(glfw/deps)

# Include Google test.
add_subdirectory(googletest)

# Add stb library
add_subdirectory(stb_image)






