#pragma once
#include "IShape.h"

class Command
{
    public:
        virtual ~Command() = default;
        virtual void Execute() = 0;
};
