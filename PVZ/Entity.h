#pragma once
#include <SFML/Graphics.hpp>
#include "Context.hpp"
class Behaviour;

class Entity
{
public:
    Entity(sf::Vector2f position, Behaviour* behaviour);
    sf::CircleShape GetShape();
    virtual ~Entity();

    sf::Color getColor() const;
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f Position);

    void setState(Context::State state);
    Context::State getState() const;

    virtual void Move()=0;
    virtual bool Collide() = 0;
    void TakeDamage();
    int GetLife();
    void Update();

    int getAmmoCount() const;
    void Shoot();
    
protected:
    int mAmmoCount, mMaxAmmo;
    float mSpeed;
    int mLife;
    sf::CircleShape mShape;
    sf::Color mColor;
    sf::Vector2f mPosition;
    std::string mName;
    Context::State mState;
    Behaviour* mBehaviour;
};

