#include "Background.h"

Background::Background()
{
	bgTex.loadFromFile("gfx/fish.jpg");
	bgTex.setRepeated(true);
	setTexture(&bgTex);
	setSize(sf::Vector2f(1920, 1200));
	//setScale(2, 2);
}

Background::~Background()
{
}

void Background::update(float dt) {
	static float offsetX = 0.0f;
	float scrollSpeed = 100.f;

	offsetX += scrollSpeed * dt;

	if (offsetX>bgTex.getSize().x)
	{
		offsetX -= bgTex.getSize().x;
	}
	setTextureRect(sf::IntRect(static_cast<int>(offsetX), 0, 1920, 1200));
}
