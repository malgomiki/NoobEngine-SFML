#include "Player.h"


/*
Right now the size is 128x128
and each frame is scaled up accordingly, 
for animation frame that are of size 32x32 
this scalling works fine cause there initial size is 32x32 
but for frames whose initial size isn't 32x32 this messes up those frames
it squishes those frames to fit in the size of 128x128

maybe I could check if the getCurrentFrame->width is not of the ratio 32x32, then increase the size 
if it is the size we dont do shit 

*/

Player::Player()
{
	speed = 200;
	scale = 32*4;
	playerSpriteSheet.loadFromFile("gfx/DarkSamuraiAssets/DarkSamurai (64x64).png");
	setSize(sf::Vector2f(scale, scale));
	setPosition(100, 100);
	setCollisionBox(scale, scale);
	setTexture(&playerSpriteSheet);

	idle.addFrame(sf::IntRect(16, 16, 32, 32));
	idle.addFrame(sf::IntRect(80, 16, 32, 32));
	idle.addFrame(sf::IntRect(144, 16, 32, 32));
	idle.addFrame(sf::IntRect(208, 16, 32, 32));
	idle.addFrame(sf::IntRect(272, 16, 32, 32));
	idle.addFrame(sf::IntRect(336, 16, 32, 32));
	idle.addFrame(sf::IntRect(400, 16, 32, 32));
	idle.addFrame(sf::IntRect(464, 16, 32, 32));

	idle.setFrameSpeed(1.f / 8.f);


	walk.addFrame(sf::IntRect(16, 80, 32, 32));
	walk.addFrame(sf::IntRect(80, 80, 32, 32));
	walk.addFrame(sf::IntRect(144, 80, 32, 32));
	walk.addFrame(sf::IntRect(208, 80, 32, 32));
	walk.addFrame(sf::IntRect(272, 80, 32, 32));
	walk.addFrame(sf::IntRect(336, 80, 32, 32));
	walk.addFrame(sf::IntRect(400, 80, 32, 32));
	walk.addFrame(sf::IntRect(464, 80, 32, 32));

	walk.setFrameSpeed(1.f / 10.f);

	jump.addFrame(sf::IntRect(16, 272, 32, 32));
	jump.addFrame(sf::IntRect(80, 272, 32, 32));
	jump.addFrame(sf::IntRect(144, 272, 32, 32));
	jump.addFrame(sf::IntRect(208, 272, 32, 32));
	jump.addFrame(sf::IntRect(16, 336, 32, 32));
	jump.addFrame(sf::IntRect(80, 336, 32, 32));
	jump.addFrame(sf::IntRect(144, 336, 32, 32));
	jump.addFrame(sf::IntRect(208, 336, 32, 32));

	jump.setFrameSpeed(1.f / 6.f);

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 4.f);

	//Attack animations
	attack.addFrame(sf::IntRect(16, 142, 32, 32));
	attack.addFrame(sf::IntRect(75, 153, 50, 25));
	attack.addFrame(sf::IntRect(134, 150, 35, 26));
	attack.setFrameSpeed(1.f / 2.f);


	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());

	duck.addFrame(sf::IntRect(0, 44, 17, 17));
	duck.setFrameSpeed(1.f / 2.f);


	defaultScale = getSize();
}



void Player::updateSpriteSize()
{
	auto frame = currentAnimation->getCurrentFrame();
	float originalBaseSize = 32; // The base size for frames that don't need adjustment
	float scaleFactor = 4; // Your existing scale factor to achieve 128x128 size

	// Calculate current scale factors based on the frame dimensions
	float currentScaleX = static_cast<float>(getSize().x) / frame.width;
	float currentScaleY = static_cast<float>(getSize().y) / frame.height;

	// Check if the current frame dimensions are not in the ratio of the original base size
	if (frame.width % static_cast<int>(originalBaseSize) != 0 || frame.height % static_cast<int>(originalBaseSize) != 0)
	{
		// Calculate new dimensions by finding the closest multiple of 32 and apply the scale factor
		int newWidth = (int)((frame.width / originalBaseSize) * originalBaseSize * scaleFactor);
		int newHeight = (int)((frame.height / originalBaseSize) * originalBaseSize * scaleFactor);
		setSize(sf::Vector2f(newWidth, defaultScale.y)); // Set the new size to maintain the aspect ratio
		//setCollisionBox(newWidth, newHeight); // Adjust collision box size accordingly
	}
	else
	{
		setSize(defaultScale);
	}
}



void Player::handleInput(float dt)
{

	isMoving = false;
	velocity.x = 0;

	if (input->isKeyDown(sf::Keyboard::A)) {
		velocity.x = -speed;
		currentAnimation = &walk;
		currentAnimation->setFlipped(true);
		idle.setFlipped(true);
		jump.setFlipped(true);
		isMoving = true;

	}

	else if (input->isKeyDown(sf::Keyboard::D)) {
		velocity.x = speed;
		currentAnimation = &walk;
		currentAnimation->setFlipped(false);
		idle.setFlipped(false);
		jump.setFlipped(false);
		isMoving = true;
	}

	else if (input->isKeyDown(sf::Keyboard::S)) {
		currentAnimation = &duck;
	}


	else {
		//currentAnimation->reset();
		currentAnimation = &idle;
	}

	if (input->isKeyDown(sf::Keyboard::Space) && canJump) {
		Jump(200.f);
		//audio->playSoundbyName("jump");
	}

	if (!canJump)
	{
		currentAnimation = &jump;
	}
	else
	{
		jump.reset();
	}

	if (input->isLeftMouseDown())
	{
		currentAnimation = &attack;
	}

	updateSpriteSize();
	setTextureRect(currentAnimation->getCurrentFrame());
	currentAnimation->animate(dt);

}
