#pragma once

//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Quit.h"

class Quit
{
public:
	sf::Clock *deltaClock;

	Quit(sf::Clock *deltaClock);
	~Quit(void);
	void run(sf::RenderWindow& appWindow, sf::Event& event);
};