#pragma once

// Header Files
#include "MainMenu.h"
#include "Game.h"

class MainMenu
{
public:
	MainMenu(void);
	~MainMenu(void);
	void run(sf::RenderWindow& appWindow, sf::Event& event);
};

