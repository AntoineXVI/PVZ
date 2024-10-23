#pragma once
#include "Action.hpp"
class Move_Action : public Action
{
public:
	Move_Action();
	void Start(Plant* Plant)override;
	void Update(Plant* Plant)override;
	void End(Plant* Plant)override;
};
