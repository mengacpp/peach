#pragma once

#include "event.hpp"

#include "peach/log.hpp"

namespace ph::core
{
class PEACH_API WindowRepositionedEvent : public Event
{
public:
    WindowRepositionedEvent(int x, int y)
    : x(x), y(y) {}

    PH_SET_EVENT_TYPE(window_Repositioned)
    PH_SET_EVENT_CATEGORY(EventCategory_Window) 

    int x, y;
};

class PEACH_API WindowResizedEvent : public Event
{
public:
    WindowResizedEvent(int width, int height)
    : width(width), height(height) 
    {}

    PH_SET_EVENT_TYPE(window_Resized)
    PH_SET_EVENT_CATEGORY(EventCategory_Window) 

    int width, height;
};

class PEACH_API WindowClosedEvent : public Event
{
public:
    WindowClosedEvent()
    {}

    PH_SET_EVENT_TYPE(window_Closed)
    PH_SET_EVENT_CATEGORY(EventCategory_Window) 
};

class PEACH_API WindowRefreshedEvent : public Event
{
public:
    WindowRefreshedEvent()
    {}

    PH_SET_EVENT_TYPE(window_Refreshed)
    PH_SET_EVENT_CATEGORY(EventCategory_Window) 
};

class PEACH_API WindowFocusedEvent : public Event
{
public:
    WindowFocusedEvent(bool focused) : focused(focused)
    {}

    PH_SET_EVENT_TYPE(window_Focused)
    PH_SET_EVENT_CATEGORY(EventCategory_Window) 

    bool focused;
};

class PEACH_API WindowMinimizedEvent : public Event
{
public:
    WindowMinimizedEvent(bool focused) : focused(focused)
    {}

    PH_SET_EVENT_TYPE(window_Minimized)
    PH_SET_EVENT_CATEGORY(EventCategory_Window) 

    bool focused;
};

class PEACH_API WindowMaximizedEvent : public Event
{
public:
    WindowMaximizedEvent(bool focused) : focused(focused)
    {}

    PH_SET_EVENT_TYPE(window_Maximized)
    PH_SET_EVENT_CATEGORY(EventCategory_Window) 

    bool focused;
};

class PEACH_API WindowFrameBufferResizedEvent : public Event
{
public:
    WindowFrameBufferResizedEvent(int x, int y)
    : x(x), y(y) {}

    PH_SET_EVENT_TYPE(window_FrameBufferResized)
    PH_SET_EVENT_CATEGORY(EventCategory_Window) 

    int x, y;
};

class PEACH_API WindowContentScaledEvent : public Event
{
public:
    WindowContentScaledEvent(float x_scale, float y_scale)
    : x_scale(x_scale), y_scale(y_scale) {}

    PH_SET_EVENT_TYPE(window_ContentScaled)
    PH_SET_EVENT_CATEGORY(EventCategory_Window) 

    float x_scale, y_scale;
};

class PEACH_API WindowFileDroppedEvent : public Event
{
public:
    WindowFileDroppedEvent(int count, const char** paths)
    : count(count), paths(paths) {}

    //TODO add file event category maybe
    PH_SET_EVENT_TYPE(window_FileDropped)
    PH_SET_EVENT_CATEGORY(EventCategory_Window) 

    int count;
    const char **paths;
};



}
