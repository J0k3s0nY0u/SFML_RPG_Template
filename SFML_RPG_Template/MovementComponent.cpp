#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, 
	float maxVelocity, float acceleration, float decceleration)
	: sprite(sprite), 
	maxVelocity(maxVelocity), acceleration(acceleration), decceleration(decceleration)
{
}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

//Functions
void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	/* Accelerating a sprite until it reaches its max velocity */

	//Acceleration

	this->velocity.x += this->acceleration * dir_x;

	if (this->velocity.x > 0.f) // Check for Right
	{
		if (this->velocity.x > this->maxVelocity)
		{
			this->velocity.x = this->maxVelocity;
		}
	}
	else if (this->velocity.x < 0.f) // Check for Left
	{
		if (this->velocity.x < -this->maxVelocity)
		{
			this->velocity.x = -this->maxVelocity;
		}
	}
	
	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float& dt)
{
	//Decceleration
	if (this->velocity.x > 0.f) // Check for Right
	{
		this->velocity.x -= decceleration;
		if (this->velocity.x < 0.f)
		{
			this->velocity.x = 0.f;
		}
	}
	else if (this->velocity.x < 0.f) // Check for Left
	{
		this->velocity.x += decceleration;
		if (this->velocity.x > 0.f)
		{
			this->velocity.x = 0.f;
		}
	}

	//Final Move
	this->sprite.move(this->velocity * dt); //Uses Velocity
}
