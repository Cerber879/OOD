#pragma

#include "Command.h";

class NullCommand : public Command
{
public:
    void Execute() override {}

};