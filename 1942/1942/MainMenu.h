#pragma once

// Header Files
#include "MainMenu.h"
#include "Game.h"

class MainMenu
{
public:
	sf::Clock *deltaClock;

	MainMenu(sf::Clock *deltaClock);
	~MainMenu(void);
	void run(sf::RenderWindow& appWindow, sf::Event& event);
};

