#include "Player.h"

//Initializer Functions
void Player::initVariables()
{
}

void Player::initComponents()
{
	
}

//Constructors / Destructors
Player::Player(float x, float y, sf::Texture* texture)
{
	this->createSprite(texture);
}

Player::~Player()
{
}
