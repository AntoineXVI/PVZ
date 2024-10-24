#pragma once
#include "Action.hpp"
class Die_Action : public Action
{
public:
	Die_Action();
	void Start(Entity* Plant)override;
	void Update(Entity* Plant)override;
	void End(Entity* Plant)override;
};
