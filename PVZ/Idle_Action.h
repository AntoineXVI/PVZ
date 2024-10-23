#pragma once
#include "Action.hpp"
class Idle_Action : public Action
{
public:
	Idle_Action();
	void Start(Entity* Entity)override;
	void Update(Entity* Entity)override;
	void End(Entity* Entity)override;
};

