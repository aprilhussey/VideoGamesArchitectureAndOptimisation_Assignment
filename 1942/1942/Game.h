#pragma once

// Header Files
#include "Game.h"
#include "Player.h"

class Game
{
public:
	Game(void);
	~Game(void);
	void run(sf::RenderWindow& appWindow, sf::Event& event);
};

