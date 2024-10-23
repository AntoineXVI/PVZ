#include "Playground.h"
#include "Behaviour.hpp"
#include "Plant.hpp"
namespace
{
    static Playground * sInstance = nullptr;
};

Playground::Playground() 
{
    Behaviour* behaviour = new Behaviour();
    mPlants.push_back(new Plant(sf::Vector2f(10.f,50.f), behaviour,5));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 150.f), behaviour, 5));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 250.f), behaviour, 5));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 350.f), behaviour, 5));
}

void Playground::checkCollision(std::vector<Projectile*>& mProjectiles, std::vector<Zombie*>& mEnemies)
{
}

Playground* Playground::instantiate()
{
    if(!sInstance)
    {
        sInstance = new Playground();
        return sInstance;
    }
    return nullptr;
}

Playground* Playground::getInstance()
{
    return sInstance;
}


Playground::~Playground()
{

}

void Playground::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < mPlants.size(); i++) {
        window.draw(mPlants[i]->GetShape());
    }

}

void Playground::update()
{

}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
}
