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

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window->clear();

    // Render items

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

