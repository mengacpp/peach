#include "peach/core/application.hpp"

#include "peach/log.hpp"

namespace ph::core
{

Application::Application(   std::string name,
                            unsigned int scr_width,
                            unsigned int scr_height)
    : m_window(name, scr_width, scr_height)
{
    // checking window constructor
    if(!EM.is_ok())
    {
        exit(-1);
    }

    EM.ok();
}
void Application::run()
{
    m_window.open();

    if(!EM.is_ok())
    {
        exit(-1);
    }

    EM.ok();
}

}