#include "Game.h"

// Static Functions

// Initializer Functions

void Game::initWindow()
{
    /*Create an SFML window using options from a window.ini File.*/
	this-> window = new sf::RenderWindow(sf::VideoMode(1200, 600), "C++ SFML works!");
}

// Constructors/Destructors

Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::updateDt()
{
    /*Update the dt variable with the time it takes to update and render one frame.*/

    this->dt = this->dtClock.restart().asSeconds();

    system("cls");
    std::cout << this->dt << "\n";
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
        this->updateDt();
        this->update();
        this->render();
    }
}

