#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, 
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), 
	maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
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
const bool MovementComponent::getStates(const short unsigned state) const
{
	switch (state)
	{
	case IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case MOVING:
		if (this->velocity.x != 0.f || this->velocity.y != 0.f)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case MOVING_RIGHT:
		if (this->velocity.x > 0.f)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case MOVING_LEFT:
		if (this->velocity.x < 0.f)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case MOVING_UP:
		if (this->velocity.y < 0.f)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case MOVING_DOWN:
		if (this->velocity.y > 0.f)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	default:

		break;
	}

	return false;
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
	Decelerates the sprite and controls the maximum velocity.
	Moves the sprite.
	*/

	if (this->velocity.x > 0.f) // Check for Right x Axis
	{
		// Max Velocity Check x Positive
		if (this->velocity.x > this->maxVelocity)
		{
			this->velocity.x = this->maxVelocity;
		}

		//Deceleration x Positive
		this->velocity.x -= deceleration;
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

		this->velocity.x += deceleration;
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

		//Deceleration y Positive
		this->velocity.y -= deceleration;
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

		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
		{
			this->velocity.y = 0.f;
		}
	}

	//Final Move
	this->sprite.move(this->velocity * dt); //Uses Velocity
}
