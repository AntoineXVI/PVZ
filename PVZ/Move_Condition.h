#pragma once
#include "Condition.hpp"
class Move_Condition : public Condition
{

public:
	Move_Condition();
	bool Test(Entity* entity) override;
	~Move_Condition();
};

