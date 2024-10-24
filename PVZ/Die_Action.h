#pragma once
#include "Action.hpp"
class Die_Action : public Action
{
public:
	Die_Action();
	void Start(Entity* entity)override;
	void Update(Entity* entity)override;
	void End(Entity* entity)override;
};
