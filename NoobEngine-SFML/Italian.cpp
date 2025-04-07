#include "Italian.h"

Italian::Italian()
{
	italianSPRSH.loadFromFile("gfx/MarioSheetT.png");
	setSize(sf::Vector2f(15 * 4, 21 * 4));
	setPosition(450, 500);
	setTexture(&italianSPRSH);

	Walk.addFrame(sf::IntRect(0, 0, 15, 21));
	Walk.addFrame(sf::IntRect(15, 0, 15, 21));
	Walk.addFrame(sf::IntRect(30, 0, 15, 21));
	Walk.addFrame(sf::IntRect(45, 0, 15, 21));
	Walk.setFrameSpeed(1.f / 10.f);

	Swim.addFrame(sf::IntRect(0, 21, 16, 20));
	Swim.addFrame(sf::IntRect(16, 21, 16, 20));
	Swim.addFrame(sf::IntRect(32, 21, 16, 20));
	Swim.setFrameSpeed(1.f / 4.f);

	Duck.addFrame(sf::IntRect(0, 44, 17, 17));
	Duck.setFrameSpeed(1.f / 2.f);
	curAni = &Walk;

	setTag("Player");
}

Italian::~Italian()
{
}

void Italian::handleInput(float dt)
{
	velocity.x = 0.f;
	setTextureRect(curAni->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::Left)) {
		curAni = &Walk;
		curAni->setFlipped(true);
		velocity.x = -200;
	}
	else if (input->isKeyDown(sf::Keyboard::Right)) {
		curAni = &Walk;
		curAni->setFlipped(false);
		velocity.x = 200;
	}
	else if (input->isKeyDown(sf::Keyboard::Down)) {
		curAni = &Duck;
	}
	else if (input->isKeyDown(sf::Keyboard::Up)) {
		curAni = &Swim;
	}
	else {
		curAni->reset();
		curAni = &Walk;
	}
	if (input->isKeyDown(sf::Keyboard::Space)) {
		Jump(160.f);
		audio->playSoundbyName("jump");
	}
	curAni->animate(dt);
}
