#pragma once
#include "Action.hpp"
class Idle_Action : public Action
{
public:
	Idle_Action();
	void Start(Plant* Plant)override;
	void Update(Plant* Plant)override;
	void End(Plant* Plant)override;
};

