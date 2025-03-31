#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Italian : public GameObject
{
	sf::Texture italianSPRSH;
	Animation Walk;
	Animation Duck;
	Animation Swim;
	Animation* curAni;

public:
	Italian();
	~Italian();

	void handleInput(float dt) override;
};

