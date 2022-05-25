#pragma once

//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Win.h"
#include "Game.h"

class Win
{
public:
	//sf::Clock *deltaClock;

	Win(void);
	~Win(void);
	void run(sf::RenderWindow& appWindow, sf::Event& event);
};