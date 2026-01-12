add_library(imgui)

target_include_directories(
    imgui
    PUBLIC
        backends
)

target_sources(
    imgui
    PRIVATE
        imgui.cpp
        imgui_demo.cpp
        imgui_draw.cpp
        imgui_tables.cpp
        imgui_widgets.cpp
        backends/imgui_impl_glfw.cpp
        backends/imgui_impl_vulkan.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            imconfig.h
            imgui.h
            imgui_internal.h
            imstb_rectpack.h
            imstb_textedit.h
            imstb_truetype.h
            backends/imgui_impl_glfw.h
            backends/imgui_impl_vulkan.h
)

target_link_libraries(imgui
    PUBLIC
        glfw
)
