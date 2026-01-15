#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#include "go_board.h"

namespace MyApp {
    // Render the full UI
    void RenderUI();
    // Display the Go board
    void DisplayGoBoard(GoBoard b);
}
