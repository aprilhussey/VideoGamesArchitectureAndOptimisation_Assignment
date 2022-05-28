#pragma once

// Header Files
#include "Game.h"
#include "MainMenu.h"
#include "Player.h"

class Game
{
public:
	sf::Clock *deltaClock;

	Game(sf::Clock *deltaClock);
	~Game(void);
	int getRandomNum();
	void run(sf::RenderWindow& appWindow, sf::Event& event);
};

