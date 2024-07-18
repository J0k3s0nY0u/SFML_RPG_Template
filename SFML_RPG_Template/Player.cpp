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

	this->createHitboxComponent(this->sprite, 40.f, 70.f, 50.f, 60.f);
	this->createMovementComponent(250.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 5, 12, 5, 128, 128);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 0, 2, 7, 2, 128, 128);
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
			this->sprite.setOrigin(0.f, 0.f);
			this->sprite.setScale(1.f, 1.f);
			this->animationComponent->play("WALK_RIGHT", dt);
		}
		else if (this->movementComponent->getStates(MOVING_LEFT))
		{
			this->sprite.setOrigin(120.f, 0.f);
			this->sprite.setScale(-1.f, 1.f);
			this->animationComponent->play("WALK_RIGHT", dt);
		}
		else if (this->movementComponent->getStates(MOVING_UP))
		{
			this->animationComponent->play("WALK_RIGHT", dt);
		}
		else if (this->movementComponent->getStates(MOVING_DOWN))
		{
			this->animationComponent->play("WALK_RIGHT", dt);
		}
	}

	this->hitboxComponent->update();
}
