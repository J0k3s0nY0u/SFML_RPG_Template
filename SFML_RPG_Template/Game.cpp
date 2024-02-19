#include "Game.h"

// Static Functions

// Initializer Functions

void Game::initWindow()
{
	this-> window = new sf::RenderWindow(sf::VideoMode(1200, 600), "C++ SFML works!");
}

// Constructors/Destructors

Game::Game()
{

}

Game::~Game()
{
	delete this->window;
}

// Functions

void Game::updateEvents()
{

}

void Game::update()
{

}

void Game::render()
{

}

void Game::run()
{
    while (this->window->isOpen())
    {
        
    }
}

