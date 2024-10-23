#pragma once
#include "Entity.h"
class Zombie : public Entity
{
public:
    Zombie(sf::Vector2f position,Behaviour* zombie_behaviour); 
    ~Zombie();
};

