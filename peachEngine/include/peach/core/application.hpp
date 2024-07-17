#pragma once

#include "peach/core.hpp"
#include "peach/core/errors.hpp"

#include "peach/pch/pch.hpp"

namespace ph::core
{
class PEACH_API Application
{
public:
    Application(std::string name);

    void run();
private:
};
}