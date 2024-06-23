#include "Player.h"

//Initializer Functions
void Player::initVariables()
{
}

void Player::initComponents()
{
	this->createMovementComponent(250.f, 15.f, 5.f);
}

//Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();
	this->initComponents();

	this->setTexture(texture_sheet);
	this->setPosition(x, y);
}

Player::~Player()
{
}
