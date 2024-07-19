#pragma once

#include "peach/pch.hpp"

#include "peach/core.hpp"

namespace ph::core
{

enum class EventType
{
    window_Repositioned,
    window_Resized,
    window_Closed,
    window_Refreshed,
    window_Focused,
    window_Minimized,
    window_Maximized,
    window_FrameBufferResized,
    window_ContentScaled,
    window_FileDropped,

    mouse_ButtonPressed,
    mouse_Moved,
    mouse_EnteredWindow,
    mouse_Scrolled,

    keyboard_KeyPressed,
    keyboard_CharPressed,


};

#define CATEGORY(name, x) EventCategory_##name = 0 << x,
enum EventCategory
{
    CATEGORY(Window, 0)
    CATEGORY(Input, 1)
    CATEGORY(Keyboard, 2)
    CATEGORY(Mouse, 3)
};
#undef CATEGORY

template<typename T>
using EventFunction = std::function<bool(T&)>;

class PEACH_API Event
{
    friend class EventDispatcher;
public:
    virtual EventType get_type() const = 0;
    virtual int get_category() const = 0;

    virtual std::string get_name() const = 0;
    virtual std::string to_string() {return get_name(); }

    inline bool is_in_category(EventCategory category) const
    {
        return get_category() & category;
    }

protected:
    bool m_handled = false;
};
class PEACH_API EventDispatcher
{
public:
    EventDispatcher(Event &e) : m_event(e) {}

    template<typename T>
    bool dispatch(EventFunction<T> fn){
        if(m_event.get_type() == T::get_type_s())
        {
            m_event.m_handled = fn(*(T*)&m_event);
            return true;
        }
        
        return false;
    }
private:
    Event& m_event;
};



#define PH_SET_EVENT_TYPE(t)\
    std::string get_name() const override{ return #t;}\
    EventType get_type() const override { return EventType:: t; }\
    static EventType get_type_s() { return EventType:: t; }

#define PH_SET_EVENT_CATEGORY(c)\
    int get_category() const override {return c; }
}