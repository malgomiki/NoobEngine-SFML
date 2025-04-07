#pragma once
#include "framework/GameObject.h"
class Background : public GameObject
{
	sf::Texture bgTex;
public:
	Background();
	~Background();

	void update(float dt) override;
};

