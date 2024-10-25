#pragma once
#include "Action.hpp"
#include "Entity.h"
class Move_Action : public Action
{
	
public:
	Move_Action();
	void Start(Entity* entity)override;
	void Update(Entity* entity)override;
	void End(Entity* entity)override;
};
