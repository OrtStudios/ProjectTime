#pragma once

#include "src/Base/Error/ErrorBase.h"

namespace Core
{
    namespace Error
    {
        class TypeError : public Base
        {
            // (Con/De)structors
            TypeError();
            ~TypeError();
        };
    }
}
