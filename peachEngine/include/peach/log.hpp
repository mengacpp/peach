#pragma once

#include "pch/pch.hpp"

// Reset
#define PH_ANSI_RESET "\033[0m"

// Regular Colors
#define PH_ANSI_BLACK "\033[0;30m"
#define PH_ANSI_RED "\033[0;31m"
#define PH_ANSI_GREEN "\033[0;32m"
#define PH_ANSI_YELLOW "\033[0;33m"
#define PH_ANSI_BLUE "\033[0;34m"
#define PH_ANSI_PURPLE "\033[0;35m"
#define PH_ANSI_CYAN "\033[0;36m"
#define PH_ANSI_WHITE "\033[0;37m"

// Bold
#define PH_ANSI_BOLD_BLACK "\033[1;30m"
#define PH_ANSI_BOLD_RED "\033[1;31m"
#define PH_ANSI_BOLD_GREEN "\033[1;32m"
#define PH_ANSI_BOLD_YELLOW "\033[1;33m"
#define PH_ANSI_BOLD_BLUE "\033[1;34m"
#define PH_ANSI_BOLD_PURPLE "\033[1;35m"
#define PH_ANSI_BOLD_CYAN "\033[1;36m"
#define PH_ANSI_BOLD_WHITE "\033[1;37m"

// Underline
#define PH_ANSI_UNDERLINE_BLACK "\033[4;30m"
#define PH_ANSI_UNDERLINE_RED "\033[4;31m"
#define PH_ANSI_UNDERLINE_GREEN "\033[4;32m"
#define PH_ANSI_UNDERLINE_YELLOW "\033[4;33m"
#define PH_ANSI_UNDERLINE_BLUE "\033[4;34m"
#define PH_ANSI_UNDERLINE_PURPLE "\033[4;35m"
#define PH_ANSI_UNDERLINE_CYAN "\033[4;36m"
#define PH_ANSI_UNDERLINE_WHITE "\033[4;37m"

// Background
#define PH_ANSI_BG_BLACK "\033[40m"
#define PH_ANSI_BG_RED "\033[41m"
#define PH_ANSI_BG_GREEN "\033[42m"
#define PH_ANSI_BG_YELLOW "\033[43m"
#define PH_ANSI_BG_BLUE "\033[44m"
#define PH_ANSI_BG_PURPLE "\033[45m"
#define PH_ANSI_BG_CYAN "\033[46m"
#define PH_ANSI_BG_WHITE "\033[47m"

// High Intensity
#define PH_ANSI_INTENSE_BLACK "\033[0;90m"
#define PH_ANSI_INTENSE_RED "\033[0;91m"
#define PH_ANSI_INTENSE_GREEN "\033[0;92m"
#define PH_ANSI_INTENSE_YELLOW "\033[0;93m"
#define PH_ANSI_INTENSE_BLUE "\033[0;94m"
#define PH_ANSI_INTENSE_PURPLE "\033[0;95m"
#define PH_ANSI_INTENSE_CYAN "\033[0;96m"
#define PH_ANSI_INTENSE_WHITE "\033[0;97m"

// Bold High Intensity
#define PH_ANSI_BOLD_INTENSE_BLACK "\033[1;90m"
#define PH_ANSI_BOLD_INTENSE_RED "\033[1;91m"
#define PH_ANSI_BOLD_INTENSE_GREEN "\033[1;92m"
#define PH_ANSI_BOLD_INTENSE_YELLOW "\033[1;93m"
#define PH_ANSI_BOLD_INTENSE_BLUE "\033[1;94m"
#define PH_ANSI_BOLD_INTENSE_PURPLE "\033[1;95m"
#define PH_ANSI_BOLD_INTENSE_CYAN "\033[1;96m"
#define PH_ANSI_BOLD_INTENSE_WHITE "\033[1;97m"

// High Intensity backgrounds
#define PH_ANSI_BG_INTENSE_BLACK "\033[0;100m"
#define PH_ANSI_BG_INTENSE_RED "\033[0;101m"
#define PH_ANSI_BG_INTENSE_GREEN "\033[0;102m"
#define PH_ANSI_BG_INTENSE_YELLOW "\033[0;103m"
#define PH_ANSI_BG_INTENSE_BLUE "\033[0;104m"
#define PH_ANSI_BG_INTENSE_PURPLE "\033[0;105m"
#define PH_ANSI_BG_INTENSE_CYAN "\033[0;106m"
#define PH_ANSI_BG_INTENSE_WHITE "\033[0;107m"

#define PH_LOG(message)\
    std::cout <<\
        PH_ANSI_INTENSE_WHITE PH_ANSI_UNDERLINE_WHITE PH_ANSI_BOLD_WHITE\
        __FILE__ ":" << __LINE__ << ":" PH_ANSI_RESET " " << message << PH_ANSI_RESET "\n"
#define PH_LOG_WARN(message)\
    PH_LOG(PH_ANSI_BOLD_INTENSE_YELLOW "Warning: " PH_ANSI_RESET << message)

#ifdef PH_CORE
#define PH_LOG_ERR(message)\
    PH_LOG(PH_ANSI_BOLD_INTENSE_PURPLE "Core error: " PH_ANSI_RESET << message)
#else
#define PH_LOG_ERR(message)\
    PH_LOG(PH_ANSI_BOLD_INTENSE_RED "Error: " PH_ANSI_RESET << message)
#endif

#ifdef PH_DEBUG
#define PH_LOG_DBG(message)\
    PH_LOG(PH_ANSI_BOLD_INTENSE_CYAN "Debug: " PH_ANSI_RESET << message)
#else
#define PH_LOG_DBG(message)
#endif