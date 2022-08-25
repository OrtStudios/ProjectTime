#pragma once

#include "src/Base/Error/ErrorBase.h"

namespace Core
{
    namespace Error
    {
        class SyntaxError : public Base
        {
            // Constructor
            SyntaxError() : Base("SyntaxError", "Wrong") {}
        };
    }
}
