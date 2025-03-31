#include "Zombie.h"

Zombie::Zombie()
{
	ZombieTex.loadFromFile("gfx/animZombie.png");
	setSize(sf::Vector2f(55, 108));

	setPosition(300, 100);

	setTexture(&ZombieTex);
	// Setup walk animation.
	Walk.addFrame(sf::IntRect(0, 0, 55, 108));
	Walk.addFrame(sf::IntRect(55, 0, 55, 108));
	Walk.addFrame(sf::IntRect(110, 0, 55, 108));
	Walk.addFrame(sf::IntRect(165, 0, 55, 108));
	Walk.addFrame(sf::IntRect(220, 0, 55, 108));
	Walk.addFrame(sf::IntRect(275, 0, 55, 108));
	Walk.addFrame(sf::IntRect(330, 0, 55, 108));
	Walk.addFrame(sf::IntRect(385, 0, 55, 108));

	Walk.setFrameSpeed(1.f / 10.f);

	//setCollisionBox(0, 0, 55, 100);
}

Zombie::~Zombie()
{
}

void Zombie::handleInput(float dt)
{
	velocity.x = 0;

	if (input->isKeyDown(sf::Keyboard::A)) {
		Walk.animate(dt);
		Walk.setFlipped(true);
		velocity.x = -200;
	}
	if (input->isKeyDown(sf::Keyboard::D)) {
		Walk.animate(dt);
		Walk.setFlipped(false);
		velocity.x = 200;
	}
}

void Zombie::update(float dt)
{
	//Walk.animate(dt);
	setTextureRect(Walk.getCurrentFrame());
}


