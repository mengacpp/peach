#pragma once

#include "peach/pch.hpp"

#include "peach/core.hpp"


namespace ph::core
{

enum class ErrorType
{
    Ok,

    Fatal,

    window_glfw_NotInit,
    window_glfw_WindowNotCreated,
    window_glew_NotInit,
    window_glfw_OpenWithoutWindow,
    window_EventCbNotSet,

};
#undef et

/// @brief  Error manager class
class PEACH_API ErrorManager
{
public:
    ErrorManager() : m_err(ErrorType::Ok) {};

    ErrorType get_err() {return m_err; }
    void set_err(ErrorType err);
    inline void ok() {m_err = ErrorType::Ok; }

    inline bool is_ok() {return m_err == ErrorType::Ok;}

private:
    ErrorType m_err;
};

/// Error manager
static ErrorManager EM;

}