#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Zombie : public GameObject
{
	sf::Texture ZombieTex;
	Animation Walk;

public:
	Zombie();
	~Zombie();

	void update(float dt) override;
	void handleInput(float dt) override;
};

