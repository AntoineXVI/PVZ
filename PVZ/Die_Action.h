#pragma once
#include "Action.hpp"
class Die_Action : public Action
{
public:
	Die_Action();
	void Start(Plant* Plant)override;
	void Update(Plant* Plant)override;
	void End(Plant* Plant)override;
};
