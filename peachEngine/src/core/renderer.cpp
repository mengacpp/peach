#include "peach/core/renderer.hpp"

#include "peach/core/errors.hpp"

#include "GL/glew.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

ph::core::Renderer::Renderer()
{
}
void ph::core::Renderer::render()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    {
        ImGui::ShowDemoWindow();
    }


    ImGui::Render();
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
    EM.ok();
}