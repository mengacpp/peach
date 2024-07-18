#pragma once

#include "peach/pch.hpp"

#include "peach/core.hpp"
#include "peach/core/errors.hpp"
#include "peach/core/window.hpp"


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
    Window m_window;
};
}