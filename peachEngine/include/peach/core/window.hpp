#pragma once

#include "peach/core.hpp"
#include "peach/pch.hpp"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace ph::core
{

class PEACH_API Window
{
public:
    Window( std::string name, 
            unsigned int width, 
            unsigned int height);
    
    void open();

    void close();
private:
    GLFWwindow *m_glfw_window;

    std::string m_name;

    unsigned int m_width, m_height;
};


}