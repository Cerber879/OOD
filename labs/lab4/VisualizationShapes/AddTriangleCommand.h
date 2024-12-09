#pragma once
#include "Command.h"

class AddTriangleCommand : public Command
{
public:
	void Execute() override;
};
