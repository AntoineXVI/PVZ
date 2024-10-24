#include "Playground.h"
#include "Behaviour.hpp"
#include "Plant.hpp"

#include "Zombie.h"
#include "Projectile.h"
#include "Transition.hpp"
#include "Condition.hpp"
#include "Shoot_Condition.h"
#include "Shoot_Action.h"
#include "Die_Condition.h"
#include "Die_Action.h"
namespace
{
    static Playground * sInstance = nullptr;
};

Playground::Playground() 
{
    //plant
    Behaviour* behaviour = new Behaviour(); 

    Transition* shoot_Transition = new Transition();
    shoot_Transition->setTargetState(Context::State::SHOOT);
    //shoot_Transition->addCondition(new Shoot_Condition());


    Action* shoot_Action = new Shoot_Action();

    behaviour->AddAction(Context::State::SHOOT, shoot_Action);
    behaviour->AddTransition(Context::State::IDLE, shoot_Transition);

    //behaviour->AddAction(Context::State::SHOOT, shoot_Action);

    mPlants.push_back(new Plant(sf::Vector2f(10.f,50.f), behaviour,5));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 150.f), behaviour, 5));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 250.f), behaviour, 5));
    mPlants.push_back(new Plant(sf::Vector2f(10.f, 350.f), behaviour, 5));

    //zombie
    ZombieBehaviour = new Behaviour();

    Transition* die_Transition = new Transition();
    die_Transition->setTargetState(Context::State::DIE);
    die_Transition->addCondition(new Die_Condition());

    /*Action* die_Action = new Die_Action(); 

    ZombieBehaviour->AddAction(Context::State::DIE, die_Action); */
}

void Playground::checkCollisionPlant(std::vector<Plant*>& plants, std::vector<Zombie*>& mEnemies) //check si zombie tue plante
{
    for (int i = 0; i < plants.size(); ++i)
    {
        sf::FloatRect plantBounds = plants[i]->GetShape().getGlobalBounds();

        // Parcours de chaque zombie
        for (int j = 0; j < mEnemies.size(); ++j)
        {
            sf::FloatRect zombieBounds = mEnemies[j]->GetShape().getGlobalBounds();

            // Vérifie si la plante est touché par un zombie
            if (plantBounds.intersects(zombieBounds))
            {
                //collision
                plants[i]->setState(Context::State::HIT);
                mEnemies[j]->setState(Context::State::DIE);
            }
        }
    }
}void Playground::checkCollisionProjectile(std::vector<Projectile*>& projectiles, std::vector<Zombie*>& mEnemies) //check si zombie tue plante
{
    for (int i = 0; i < projectiles.size(); ++i)
    {
        sf::FloatRect plantBounds = projectiles[i]->GetShape().getGlobalBounds();

        // Parcours de chaque zombie
        for (int j = 0; j < mEnemies.size(); ++j)
        {
            sf::FloatRect zombieBounds = mEnemies[j]->GetShape().getGlobalBounds();

            // Vérifie si le projectile touche un zombie
            if (plantBounds.intersects(zombieBounds))
            {
                //collision
                projectiles[i]->setState(Context::State::DIE);
                mEnemies[j]->setState(Context::State::DIE);
            }
        }
    }
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

const std::vector<Zombie*>& Playground::getZombies() const
{
    return mZombies;
}


const std::vector<Projectile*>& Playground::getProjectile() const
{
    return mProjectiles;
}

const std::vector<Plant*>& Playground::getPlant() const
{
    return mPlants;
}



Playground::~Playground()
{

}

void Playground::addProjectiles(Projectile* proj )
{
    mProjectiles.push_back(proj);
}

void Playground::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < mPlants.size(); i++) {
        window.draw(mPlants[i]->GetShape());
    }
    for (int i = 0; i < mZombies.size(); i++) {
        window.draw(mZombies[i]->GetShape());
    }

    for (int i = 0; i < mProjectiles.size(); i++) {
        window.draw(mProjectiles[i]->GetShape());
    }

}

void Playground::update()
{
    for (int i = 0; i < mPlants.size(); i++) {
        mPlants[i]->Update();
    }
    for (int i = 0; i < mZombies.size(); i++) {
        mZombies[i]->Update();
    }
    for (int i = 0; i < mProjectiles.size(); i++) {
        mProjectiles[i]->Update();
    }
    checkCollisionPlant(mPlants, mZombies); 
    checkCollisionProjectile(mProjectiles, mZombies);

}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
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
