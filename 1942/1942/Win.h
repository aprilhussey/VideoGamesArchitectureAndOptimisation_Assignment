#pragma once

//Header Files
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Win.h"

class Win
{
public:
	sf::Clock *deltaClock;

	Win(sf::Clock *deltaClock);
	~Win(void);
	void run(sf::RenderWindow& appWindow, sf::Event& event);
};