#pragma once

#include "event.hpp"

namespace ph::core
{
class PEACH_API MouseButtonPressedEvent : public Event
{
public:
    MouseButtonPressedEvent(int button, int action, int mods)
    : button(button), action(action), mods(mods) {}

    PH_SET_EVENT_TYPE(mouse_ButtonPressed)
    PH_SET_EVENT_CATEGORY(EventCategory_Input | EventCategory_Mouse) 

    int button, action, mods;
};

class PEACH_API MouseMovedEvent : public Event
{
public:
    MouseMovedEvent(double x, double y)
    : x(x), y(y) {}

    PH_SET_EVENT_TYPE(mouse_Moved)
    PH_SET_EVENT_CATEGORY(EventCategory_Input | EventCategory_Mouse) 

    double x, y;
};

class PEACH_API MouseEnteredEvent : public Event
{
public:
    MouseEnteredEvent(bool entered)
    : entered(entered) {}

    PH_SET_EVENT_TYPE(mouse_EnteredWindow)
    PH_SET_EVENT_CATEGORY(EventCategory_Input | EventCategory_Mouse) 

    bool entered;
};

class PEACH_API MouseScrolledEvent : public Event
{
public:
    MouseScrolledEvent(double x, double y)
    : x(x), y(y) {}

    PH_SET_EVENT_TYPE(mouse_Scrolled)
    PH_SET_EVENT_CATEGORY(EventCategory_Input | EventCategory_Mouse) 

    double x, y;
};

class PEACH_API KeyPressedEvent : public Event
{
public:
    KeyPressedEvent(int key, int scancode, int action, int mods)
    : key(key), scancode(scancode), action(action), mods(mods) {}

    PH_SET_EVENT_TYPE(keyboard_KeyPressed)
    PH_SET_EVENT_CATEGORY(EventCategory_Input | EventCategory_Keyboard) 

    int key, scancode, action, mods;
};

class PEACH_API CharPressedEvent : public Event
{
public:
    CharPressedEvent(unsigned int codepoint, int mods)
    : codepoint(codepoint), mods(mods) {}

    PH_SET_EVENT_TYPE(keyboard_CharPressed)
    PH_SET_EVENT_CATEGORY(EventCategory_Input | EventCategory_Keyboard) 

    unsigned int codepoint;
    int mods;
};
}