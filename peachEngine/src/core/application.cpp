#include "peach/core/application.hpp"

#include "peach/log.hpp"

namespace ph::core
{

Application::Application(   std::string name,
                            unsigned int scr_width,
                            unsigned int scr_height)
    : m_window(name, scr_width, scr_height), m_should_close(false)
{
    // checking window constructor
    if(!EM.is_ok())
    {
        exit(-1);
    }
    WindowEventCallback cb = [this](Event& e){this->on_event(e);};
    m_window.set_event_callback(cb);

    EM.ok();
}
void Application::run()
{
    while(!m_should_close)
    {
        m_window.update();
    }

    m_window.close();

    EM.ok();
}
#define BIND_FN(x) std::bind(&Application::x, this, std::placeholders::_1);

#define DISPATCH(type, receiver_fn)\
{\
    EventFunction<type> fn = BIND_FN(receiver_fn);\
    if(dispatcher.dispatch(fn)) return;\
}
void Application::on_event(Event &e)
{
    EventDispatcher dispatcher(e);
    
    DISPATCH(WindowClosedEvent, on_window_closed);
    DISPATCH(KeyPressedEvent, on_key_pressed);

}

#undef BIND_FN
#undef DISPATCH

bool Application::on_window_closed(WindowClosedEvent &e)
{
    m_should_close = true;
    return true;
}

bool Application::on_key_pressed(KeyPressedEvent &e)
{
    return true;
}
}
