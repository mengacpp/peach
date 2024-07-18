#include "peach/core/window.hpp"

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

    std::string glsl_version = "#version 330 core";
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
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(m_glfw_window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    EM.ok();
}

void ph::core::Window::close()
{
    glfwSetWindowShouldClose(m_glfw_window, true);
    EM.ok();
}
