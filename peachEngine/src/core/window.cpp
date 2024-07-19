#include "peach/core/window.hpp"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "peach/core/errors.hpp"

#include "peach/log.hpp"

#include "peach/events/window_events.hpp"
#include "peach/events/input_events.hpp"

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

    glfwSetWindowUserPointer(m_glfw_window, this);

    #pragma region callbacks

    // Unusued callbacks:
    // * Monitor
    // * Char
    // Remember to call ImGui's callbacks when setting one

    //TODO: Converts all GLFW_ parameters to peach using modern C++,
    // so its easier for the user

    #define GET_WINDOW_PTR(identifier) Window &identifier = *(Window*)glfwGetWindowUserPointer(window)

    #define CALL_EVENT_CB\
        {\
        GET_WINDOW_PTR(data);\
        WindowEventCallback cb = data.get_event_callback();\
        cb(e);\
        }

    glfwSetWindowPosCallback(m_glfw_window, [](GLFWwindow *window, int x, int y){
        WindowRepositionedEvent e(x, y);
        CALL_EVENT_CB
    });

    glfwSetWindowSizeCallback(m_glfw_window, [](GLFWwindow *window, int w, int h){
        WindowResizedEvent e(w, h);
        CALL_EVENT_CB
    });

    glfwSetWindowCloseCallback(m_glfw_window, [](GLFWwindow *window){
        WindowClosedEvent e;
        CALL_EVENT_CB
    });

    glfwSetWindowRefreshCallback(m_glfw_window, [](GLFWwindow *window){
        WindowRefreshedEvent e;
        CALL_EVENT_CB
    });

    glfwSetWindowFocusCallback(m_glfw_window, [](GLFWwindow *window, int focused){
        ImGui_ImplGlfw_WindowFocusCallback(window, focused);
        WindowFocusedEvent e(focused == GLFW_TRUE ? true : false);
        CALL_EVENT_CB
    });

    glfwSetWindowIconifyCallback(m_glfw_window, [](GLFWwindow *window, int iconified){
        WindowMinimizedEvent e(iconified == GLFW_TRUE ? true : false);
        CALL_EVENT_CB
    });

    glfwSetFramebufferSizeCallback(m_glfw_window, [](GLFWwindow *window, int w, int h){
        WindowFrameBufferResizedEvent e(w, h);
        CALL_EVENT_CB
    });

    glfwSetWindowContentScaleCallback(m_glfw_window, [](GLFWwindow *window, float x, float y){
        WindowContentScaledEvent e(x, y);
        CALL_EVENT_CB
    });

    glfwSetMouseButtonCallback(m_glfw_window, [](GLFWwindow *window, int button, int action, int mods){
        ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
        MouseButtonPressedEvent e(button, action, mods);
        CALL_EVENT_CB
    });

    glfwSetCursorPosCallback(m_glfw_window, [](GLFWwindow *window, double x, double y){
        ImGui_ImplGlfw_CursorPosCallback(window, x, y);
        MouseMovedEvent e(x, y);
        CALL_EVENT_CB
    });

    glfwSetCursorEnterCallback(m_glfw_window, [](GLFWwindow *window, int entered){
        ImGui_ImplGlfw_CursorEnterCallback(window, entered);
        MouseEnteredEvent e(entered == GLFW_TRUE ? true : false);
        CALL_EVENT_CB
    });

    glfwSetScrollCallback(m_glfw_window, [](GLFWwindow *window, double x, double y){
        ImGui_ImplGlfw_ScrollCallback(window, x, y);
        MouseScrolledEvent e(x, y);
        CALL_EVENT_CB
    });

    glfwSetKeyCallback(m_glfw_window, [](GLFWwindow *window, int key, int scancode, int action, int mods){
        ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
        KeyPressedEvent e(key, scancode, action, mods);
        CALL_EVENT_CB
    });

    glfwSetCharModsCallback(m_glfw_window, [](GLFWwindow *window, unsigned int codepoint, int mods){
        CharPressedEvent e(codepoint, mods);
        CALL_EVENT_CB
    });

    glfwSetDropCallback(m_glfw_window, [](GLFWwindow *window, int count, const char** paths){
        WindowFileDroppedEvent e(count, paths);
        CALL_EVENT_CB
    });

    #pragma endregion

    EM.ok();
}

void ph::core::Window::poll_events()
{
    glfwPollEvents();

    glfwGetFramebufferSize(m_glfw_window, &m_width, &m_height);
    glViewport(0, 0, m_width, m_height);

    EM.ok();

}
void ph::core::Window::swap_buffers()
{
    glfwSwapBuffers(m_glfw_window);

    EM.ok();

}

void ph::core::Window::set_event_callback(WindowEventCallback cb)
{
    m_event_callback = cb;
    EM.ok();
}
void ph::core::Window::close()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(m_glfw_window);
    glfwTerminate();
    EM.ok();
}
