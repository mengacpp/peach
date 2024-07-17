#pragma once

#include "peach/pch/pch.hpp"
#include "peach/core.hpp"


namespace ph::core
{

enum class ErrorType
{
    Ok,

    Fatal,
};
#undef et

/// @brief  Error manager class
class PEACH_API ErrorManager
{
public:
    ErrorManager() : m_err(ErrorType::Ok) {};

    ErrorType get_err() {return m_err; }
    inline void set_err(ErrorType err);
    inline void ok() {m_err = ErrorType::Ok; }

    inline bool is_ok() {return m_err == ErrorType::Ok;}

private:
    ErrorType m_err;
};

/// Error manager
static ErrorManager EM;

}