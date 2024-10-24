#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include "Entity.h"
#include "Projectile.h"

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
	std::vector<Projectile*> mProjectiles;


	Behaviour* ZombieBehaviour;


	Playground();
public:
	static Playground* instantiate();
	static Playground* getInstance();
	void checkCollisionPlant(std::vector<Plant*>& mProjectiles,std::vector<Zombie*>& mEnemies); 
	void checkCollisionProjectile(std::vector<Projectile*>& mProjectiles,std::vector<Zombie*>& mEnemies); 


	const std::vector<Zombie*>& getZombies() const ; 
	const std::vector<Projectile*>& getProjectile() const ;
	const std::vector<Plant*>& getPlant() const ; 


	void addProjectiles(Projectile* proj);

	~Playground();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow& window);
};

