#include "peach/core/window.hpp"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "peach/core/errors.hpp"

#include "peach/log.hpp"

void glfwErrorCallback(int error, const char* description) {
    PH_LOG_ERR("GLFW Error #" << error << ": " << description);
}

ph::core::Window::Window(std::string name, unsigned int width, unsigned int height)
: m_glfw_window(nullptr), m_height(height), m_width(width), m_name(name)
{
    // Init glfw
    glfwSetErrorCallback(glfwErrorCallback);

    if(!glfwInit())
    {
        PH_LOG_ERR("GLFW not initialized!");
        EM.set_err(ErrorType::window_glfw_NotInit);
        return;
    }

    std::string glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac

    m_glfw_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), NULL, NULL);
    if (!m_glfw_window)
    {
        glfwTerminate();
        PH_LOG_ERR("GLFW window not created!");
        EM.set_err(ErrorType::window_glfw_WindowNotCreated);
        return;
    }

    glfwMakeContextCurrent(m_glfw_window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(m_glfw_window, true);
    ImGui_ImplOpenGL3_Init(glsl_version.c_str());

    if(glewInit() != GLEW_OK)
    {
        glfwTerminate();
        PH_LOG_ERR("GLEW not initialized!");
        EM.set_err(ErrorType::window_glew_NotInit);
        return;
    }

    // Query GPU information
    const GLubyte* renderer = glGetString(GL_RENDERER); // Get renderer string
    const GLubyte* vendor = glGetString(GL_VENDOR); // Get vendor string
    const GLubyte* version = glGetString(GL_VERSION); // Version as a string
    const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION); // GLSL version

    PH_LOG_DBG_INFO(vendor << " - " << renderer);
    PH_LOG_DBG_INFO("GL " << version << " - GLSL " << glslVersion);

    EM.ok();
}

void ph::core::Window::open()
{
    if(!m_glfw_window)
    {
        EM.set_err(ErrorType::window_glfw_OpenWithoutWindow);
        return;
    }

    while (!glfwWindowShouldClose(m_glfw_window))
    {
        /* Poll for and process events */
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::ShowDemoWindow();
        }

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(m_glfw_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(m_glfw_window);

    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(m_glfw_window);
    glfwTerminate();
    EM.ok();
}

void ph::core::Window::close()
{
    glfwSetWindowShouldClose(m_glfw_window, true);
    EM.ok();
}
