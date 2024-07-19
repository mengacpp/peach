#pragma once

#include "peach/core.hpp"
#include "peach/pch.hpp"

#include "peach/events/event.hpp"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace ph::core
{

using WindowEventCallback = std::function<void(Event&)>;

class PEACH_API Window
{
public:
    Window( std::string name, 
            unsigned int width, 
            unsigned int height);
    
    void update();

    void set_event_callback(WindowEventCallback cb);
    inline WindowEventCallback get_event_callback() const 
        {return m_event_callback; }
    
    void close();
private:
    GLFWwindow *m_glfw_window;

    std::string m_name;
    
    WindowEventCallback m_event_callback;
    int m_width, m_height;
};


}