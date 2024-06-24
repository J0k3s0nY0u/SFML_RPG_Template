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
const bool MovementComponent::idle() const
{
	if (this->velocity.x == 0.f && this->velocity.y == 0.f)
	{
		return true;
	}
	else 
	{
		return false;
	}
	
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	/* Accelerating a sprite until it reaches its max velocity */
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float& dt)
{
	/*
	Deccelerates the sprite and controls the maximum velocity.
	Moves the sprite.
	*/

	if (this->velocity.x > 0.f) // Check for Right x Axis
	{
		// Max Velocity Check x Positive
		if (this->velocity.x > this->maxVelocity)
		{
			this->velocity.x = this->maxVelocity;
		}

		//Decceleration x Positive
		this->velocity.x -= decceleration;
		if (this->velocity.x < 0.f)
		{
			this->velocity.x = 0.f;
		}
	}
	else if (this->velocity.x < 0.f) // Check for Left x Axis
	{
		//Max Velocity Check x Negative
		if (this->velocity.x < -this->maxVelocity)
		{
			this->velocity.x = -this->maxVelocity;
		}

		this->velocity.x += decceleration;
		if (this->velocity.x > 0.f)
		{
			this->velocity.x = 0.f;
		}
	}
	if (this->velocity.y > 0.f) // Check for Right y Axis
	{
		// Max Velocity Check y Positive
		if (this->velocity.y > this->maxVelocity)
		{
			this->velocity.y = this->maxVelocity;
		}

		//Decceleration y Positive
		this->velocity.y -= decceleration;
		if (this->velocity.y < 0.f)
		{
			this->velocity.y = 0.f;
		}
	}
	else if (this->velocity.y < 0.f) // Check for Left y Axis
	{
		//Max Velocity Check y Negative
		if (this->velocity.y < -this->maxVelocity)
		{
			this->velocity.y = -this->maxVelocity;
		}

		this->velocity.y += decceleration;
		if (this->velocity.y > 0.f)
		{
			this->velocity.y = 0.f;
		}
	}

	//Final Move
	this->sprite.move(this->velocity * dt); //Uses Velocity
}
