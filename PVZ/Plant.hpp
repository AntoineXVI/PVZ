#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Behaviour.hpp"
#include <iostream>
#include "Entity.h"

class Plant : public Entity
{
    int mAmmoCount, mMaxAmmo;
public:
    Plant();
    Plant(
        sf::Vector2f position,
        Behaviour* plant_behaviour,
        int ammo_count);
    ~Plant();

    int getAmmoCount() const;
    void refillMagazine() ;
    bool shoot();
};
