#include <iostream>

#include "peach/core/application.hpp"
#include "peach/core/errors.hpp"

#include "peach/peach.hpp"

#ifndef PH_PROJECT_NAME
#define PH_PROJECT_NAME "unknown"
#endif

using namespace ph;
using namespace ph::core;

int main()
{
    Application application(PH_PROJECT_NAME);

    if(!EM.is_ok())
    {
        // handle not fatal errors
    }
    
    application.run();

    if(!EM.is_ok())
    {
        // handle not fatal errors
    }

    
    return 0;
}