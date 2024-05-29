#include <imgui-cocos.hpp>

$execute {
    ImGuiCocos::get().setup([] {
        
    }).draw([] {
        ImGui::Begin("My awesome window");
        ImGui::Button("Awesome button");
        ImGui::End();
    });
}
