#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Player : public GameObject
{
	int speed;
	Animation walk;
	Animation swim;
	Animation duck;
	Animation idle;
	Animation jump;
	Animation attack;

	Animation* currentAnimation;

	sf::Texture playerSpriteSheet;

	int scale;

	sf::Vector2f defaultScale;

public:
	Player();
	void handleInput(float dt) override;
	void updateSpriteSize();
	bool isMoving  ;
};

