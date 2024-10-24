#pragma once
#include "Condition.hpp"
class Die_Condition :public Condition
{
public:
	Die_Condition();
	bool Test(Entity* entity) override;
	~Die_Condition();
};
