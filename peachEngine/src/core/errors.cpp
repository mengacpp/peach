#include "peach/core/errors.hpp"

inline void ph::core::ErrorManager::set_err(ErrorType err)
{
    #ifdef PH_CORE
        m_err = err; 

        if(err > ErrorType::Fatal)
            exit(-1);
    #else
        //TODO log to not use this function outside of the core
        exit(-1);
    #endif
}