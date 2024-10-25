#pragma once
#include "Condition.hpp"
class Hit_Condition : public Condition
{

public:
	Hit_Condition();
	bool Test(Entity* entity) override;
	~Hit_Condition();
};