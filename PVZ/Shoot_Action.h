#pragma once
#include "Action.hpp"
class Shoot_Action : public Action
{
public:
	Shoot_Action();
	void Start(Entity* Entity)override;
	void Update(Entity* Entity)override;
	void End(Entity* Entity)override;
};
