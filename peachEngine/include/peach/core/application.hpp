#pragma once

#include "peach/pch.hpp"

#include "peach/core.hpp"
#include "peach/core/errors.hpp"
#include "peach/core/window.hpp"
#include "peach/core/renderer.hpp"

#include "peach/events/event.hpp"
#include "peach/events/window_events.hpp"
#include "peach/events/input_events.hpp"


namespace ph::core
{
class PEACH_API Application
{
public:
    Application(std::string name,
                unsigned int scr_width = 720,
                unsigned int scr_height = 480);

    void run();

private:
    void on_event(Event &e);

private:
    Window m_window;
    Renderer m_renderer;
    
    bool on_window_closed(WindowClosedEvent &e);
    bool on_key_pressed(KeyPressedEvent &e);
    bool m_should_close;
};
}