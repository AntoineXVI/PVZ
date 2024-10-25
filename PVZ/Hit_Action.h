#pragma once
#include "Action.hpp"
class Hit_Action :public Action
{
public:
	Hit_Action();
	void Start(Entity* entity)override;
	void Update(Entity* entity)override;
	void End(Entity* entity)override;
};
