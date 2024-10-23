#include "Playground.h"
#include "Behaviour.hpp"
#include "Plant.hpp"
#include "Zombie.h"
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
    for (int i = 0; i < mZombies.size(); i++) {
        window.draw(mZombies[i]->GetShape());
    }

}

void Playground::update()
{

}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
    Behaviour* ZombieBehaviour = new Behaviour(); 
    if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left))
    {
        sf::Vector2i MousePosition = sf::Mouse::getPosition(window);
        sf::Vector2i MouseFinalPosition = MousePosition;

        if (MousePosition.y < 100.f) //alignement avec plante
        {
            MouseFinalPosition.y = 50.f;
        }
        else if (MousePosition.y < 200.f)
        {
            MouseFinalPosition.y = 150.f;
        }
        else if (MousePosition.y < 300.f)
        {
            MouseFinalPosition.y = 250.f;
        }
        else
        {
            MouseFinalPosition.y = 350.f;
        }
        if (MousePosition.x < 100.f) //pour ne pas apparaitre trop pres de la plante
        {
            MouseFinalPosition.x = 100.f;
        }
        mZombies.push_back(new Zombie(sf::Vector2f(MouseFinalPosition.x, MouseFinalPosition.y), ZombieBehaviour));
    }
}
