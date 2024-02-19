#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

class Game
{
private:

public:
	Game();
	virtual ~Game();

	//Functions
	void updateEvents();
	void update();
	void render();
	void run();
};

