#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include "Entity.h"

class Plant;
class Projectile;
class Zombie;

class Playground;
namespace
{
	static Playground const* sinstance = nullptr;
}
class Playground
{

private:
	std::vector<Plant*> mPlants;
	std::vector<Zombie*> mZombies;
	//std::vector<Projectile*> mProjectiles;

	Playground();
	void checkCollision(std::vector<Projectile*>& mProjectiles,std::vector<Zombie*>& mEnemies);
public:
	static Playground* instantiate();
	static Playground* getInstance();
	~Playground();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow& window);
};

