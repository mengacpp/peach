#include "peach/core/errors.hpp"

#include "peach/log.hpp"

void ph::core::ErrorManager::set_err(ErrorType err)
{
    #ifdef PH_CORE
        m_err = err; 
    #else
        PH_LOG_ERR("You cant use this function!");
        exit(-1);
    #endif
}