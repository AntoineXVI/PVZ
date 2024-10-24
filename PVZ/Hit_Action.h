#pragma once
#include "Action.hpp"
class Hit_Action :public Action
{
public:
	Hit_Action();
	void Start(Entity* Plant)override;
	void Update(Entity* Plant)override;
	void End(Entity* Plant)override;
};
