#pragma once

#include "peach/pch/pch.hpp"

#include "peach/core.hpp"
#include "peach/core/errors.hpp"


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