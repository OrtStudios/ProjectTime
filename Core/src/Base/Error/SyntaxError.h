#pragma once

#include "src/Base/Error/ErrorBase.h"

namespace Core
{
    namespace Error
    {
        class SyntaxError : public Base
        {
            // (Con/De)structors
            SyntaxError() : Base("TypeError", "you have written something wrong") {}
        };
    }
}
