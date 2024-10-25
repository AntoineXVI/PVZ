#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

#include <iostream>
#include "Entity.h"

class behaviour;

class Plant : public Entity
{
    
public:
    Plant();
    Plant(
        sf::Vector2f position,
        Behaviour* plant_behaviour
        );
    
    void Move() override;
    bool Collide() override;

    
    void refillMagazine() ;
    bool shoot();
    ~Plant();
};
