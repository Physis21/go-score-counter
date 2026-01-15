#include "application.h"
#include "go_board.h"
#include "imgui.h"

namespace MyApp {

void RenderUI() {
    static float f = 0.0f;
    static int counter = 0;
    GoBoard b0(4);
    b0.set_val_in_sgrid(WHITE, 2, 3);
    std::string b0_sgrid_string = sgrid2d_tostring(b0.get_sgrid());
    char *cstr = b0_sgrid_string.data(); // printf-style formatting doesn't support std::string, but rather char *.

    ImGui::Begin("Go score counter, by Physis21.");
    ImGui::Text("Below is an example string conversion of a GoBoard.get_sgrid().");
    ImGui::Text("%s", cstr); // ImGui::Text uses printf() style formatting.

    if (ImGui::Button("Button"))  // Buttons return true when clicked (most widgets return true when edited/activated)
        counter++;
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    DisplayGoBoard(b0);

    ImGui::End();
}

void DisplayGoBoard(GoBoard b) {
    // Define my own textures
    std::string black_stone_img_filename = "./assets/go-stone-black.png";
    std::string white_stone_img_filename = "./assets/go-stone-white.png";


    // TODO: Continue by reading https://github.com/ocornut/imgui/wiki/Image-Loading-and-Displaying-Examples
    ImGuiIO& io = ImGui::GetIO();
    // Grab the current texture identifier used by the font atlas.
    ImTextureRef my_tex_id = io.Fonts->TexRef;

    // Regular user code should never have to care about TexData-> fields, but since we want to display the entire texture here, we pull Width/Height from it.
    float my_tex_w = (float)io.Fonts->TexData->Width;
    float my_tex_h = (float)io.Fonts->TexData->Height;

    ImGui::Text("my_tex_w = %f", my_tex_w);
    ImGui::Text("my_tex_h = %f", my_tex_h);

    ImGui::TextWrapped("A row of Go stones");
    static int pressed_count = 0;
    for (int i = 0; i < 8; i++)
    {
        // UV coordinates are often (0.0f, 0.0f) and (1.0f, 1.0f) to display an entire textures.
        // Here are trying to display only a 32x32 pixels area of the texture, hence the UV computation.
        // Read about UV coordinates here: https://github.com/ocornut/imgui/wiki/Image-Loading-and-Displaying-Examples
        ImGui::PushID(i);
        if (i > 0)
            ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(i - 1.0f, i - 1.0f));
        ImVec2 size = ImVec2(32.0f, 32.0f);                         // Size of the image we want to make visible
        ImVec2 uv0 = ImVec2(0.0f, 0.0f);                            // UV coordinates for lower-left
        // ImVec2 uv1 = ImVec2(32.0f / my_tex_w, 32.0f / my_tex_h);    // UV coordinates for (32,32) in our texture
        ImVec2 uv1 = ImVec2(1.0f, 1.0f);    // UV coordinates for (32,32) in our texture
        // ImVec4 bg_col = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);             // Black background
        ImVec4 bg_col = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);             // transparent background
        ImVec4 tint_col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);           // No tint
        if (ImGui::ImageButton("", my_tex_id, size, uv0, uv1, bg_col, tint_col))
            pressed_count += 1;
        if (i > 0)
            ImGui::PopStyleVar();
        ImGui::PopID();
        ImGui::SameLine();
    }
    ImGui::NewLine();
    ImGui::Text("Pressed %d times.", pressed_count);
}

}
