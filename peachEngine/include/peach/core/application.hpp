#pragma once

#include "peach/pch.hpp"

#include "peach/core.hpp"
#include "peach/core/errors.hpp"
#include "peach/core/window.hpp"

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

    bool on_window_closed(WindowClosedEvent &e);
    bool on_key_pressed(KeyPressedEvent &e);
    Window m_window;
    bool m_should_close;
};
}