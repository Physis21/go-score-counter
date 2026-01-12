# Example usage:
#  mkdir build
#  cd build
#  cmake -g "Visual Studio 14 2015" ..

cmake_minimum_required(VERSION 3.22)
project(imgui_example_glfw_vulkan C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DVK_PROTOTYPES") # I don't know what that means
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES") # Same

add_subdirectory(vendor)
add_subdirectory(imgui)
add_subdirectory(lib)
add_subdirectory(src)

# 3rd party code is in vendor.
# add_subdirectory(vendor)

# # GLFW
# if(NOT GLFW_DIR)
#    set(GLFW_DIR vendor/glfw) # Set this to point to an up-to-date GLFW repo
# endif()
# option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
# option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
# option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
# option(GLFW_INSTALL "Generate installation target" OFF)
# option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)
# add_subdirectory(${GLFW_DIR} binary_dir EXCLUDE_FROM_ALL)
# include_directories(${GLFW_DIR}/include)
#
# Dear ImGui
# set(IMGUI_DIR imgui/)
# include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends ..) # ImGui example adds ..
# include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends)
# add_subdirectory(imgui)

#
# # Libraries
# find_package(Vulkan REQUIRED)
# #find_library(VULKAN_LIBRARY
#   #NAMES vulkan vulkan-1)
# #set(LIBRARIES "glfw;${VULKAN_LIBRARY}")
# # set(LIBRARIES "glfw;Vulkan::Vulkan") # Removed because unused.
#
# # Use vulkan headers from glfw:
# include_directories(${GLFW_DIR}/deps)
#
# # file(GLOB sources src/*.cpp) #  Removed because unused.
#
# # Include Google test using FetchContent.
# add_subdirectory(vendor/googletest)

# Finally, my own libraries.
# add_subdirectory(lib)

# Here, imgui is not implemented as a library. Instead, imgui files are simply listed as source files.


