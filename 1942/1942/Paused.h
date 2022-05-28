#pragma once

//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Paused.h"

class Paused
{
public:
	sf::Clock *deltaClock;

	Paused(sf::Clock *deltaClock);
	~Paused(void);
	bool run(sf::RenderWindow& appWindow, sf::Event& event);
};