#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Physics2D/Core.h>

class TestExampleApp {
private:
	const int WIDTH = 600, HEIGHT = 600;
	const int FPS = 60;

	sf::RenderWindow window;

	void Init();
	void Update();
public:
	void Run();
};