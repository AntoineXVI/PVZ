#pragma once
#include "Action.hpp"
class Hit_Action :public Action
{
public:
	Hit_Action();
	void Start(Plant* Plant)override;
	void Update(Plant* Plant)override;
	void End(Plant* Plant)override;
};
