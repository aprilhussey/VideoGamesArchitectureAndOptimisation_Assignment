#pragma once

//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Lose.h"
#include "Game.h"

class Lose
{
public:
	//sf::Clock *deltaClock;

	Lose(void);
	~Lose(void);
	void run(sf::RenderWindow& appWindow, sf::Event& event);
};