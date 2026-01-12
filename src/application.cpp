#include "application.h"
#include "go_board.h"

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

        ImGui::End();
    }
}
