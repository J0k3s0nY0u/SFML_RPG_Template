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
	//Acceleration

	this->velocity.x = this->maxVelocity * dir_x;
	this->velocity.y = this->maxVelocity * dir_y;
}

void MovementComponent::update(const float& dt)
{
	//Decceleration

	//Final Move
	this->sprite.move(this->velocity * dt); //Uses Velocity
}
