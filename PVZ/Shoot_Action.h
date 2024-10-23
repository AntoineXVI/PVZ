#pragma once
#include "Action.hpp"
class Shoot_Action : public Action
{
public:
	Shoot_Action();
	void Start(Plant* Plant)override;
	void Update(Plant* Plant)override;
	void End(Plant* Plant)override;
	~Shoot_Action();
};
