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
    //  We are not handling errors here, every error should
    //  be handled in the core
    Application app(PH_PROJECT_NAME, 1280, 720);

    app.run();
    
    return 0;
}