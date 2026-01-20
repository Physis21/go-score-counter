#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#include "go_board.h"
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

#define _CRT_SECURE_NO_WARNINGS
#include "stb_image.h"

namespace MyApp {
    // Render the full UI
    void RenderUI();
    // Display the Go board
    void DisplayGoBoard(GoBoard b);
}
