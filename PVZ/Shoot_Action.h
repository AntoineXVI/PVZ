#pragma once
#include "Action.hpp"
class Shoot_Action : public Action
{
public:
	Shoot_Action();
	void Start(Entity* entity)override;
	void Update(Entity* entity)override;
	void End(Entity* entity)override;
	~Shoot_Action();
};
