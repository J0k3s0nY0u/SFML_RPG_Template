#include "Player.h"

//Initializer Functions
void Player::initVariables()
{
}

void Player::initComponents()
{
	
}

//Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 10.f, 10.f, 50.f, 60.f);
	this->createMovementComponent(250.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 1, 5, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 8.f, 0, 11, 7, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_LEFT", 10.f, 0, 9, 8, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_UP", 10.f, 0, 8, 8, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_DOWN", 10.f, 0, 10, 8, 0, 64, 64);
	this->animationComponent->addAnimation("ATTACK", 6.f, 0, 24, 7 , 24, 96, 96);
}

Player::~Player()
{
}

//Functions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	if (this->movementComponent->getStates(IDLE))
	{
		this->animationComponent->play("IDLE_LEFT", dt);
	}
	else if (this->movementComponent->getStates(MOVING))
	{
		if (this->movementComponent->getStates(MOVING_RIGHT))
		{
			this->animationComponent->play("WALK_RIGHT", dt); 
		}
		else if (this->movementComponent->getStates(MOVING_LEFT))
		{
			this->animationComponent->play("WALK_LEFT", dt);
		}
		else if (this->movementComponent->getStates(MOVING_UP))
		{
			this->animationComponent->play("WALK_UP", dt);
		}
		else if (this->movementComponent->getStates(MOVING_DOWN))
		{
			this->animationComponent->play("WALK_DOWN", dt);
		}
	}

	this->hitboxComponent->update();
}
