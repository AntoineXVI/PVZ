#pragma once
#include "Condition.hpp"
class Shoot_Condition : public Condition
{
public:
	Shoot_Condition() {};
	bool Test(Entity* Plant) override;
	~Shoot_Condition();
};

