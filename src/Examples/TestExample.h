#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Physics2D/Core.h>
#include "GravityFG.h"
#include "DragFG.h"

class TestExampleApp {
private:
	const int WIDTH = 600, HEIGHT = 600;
	const int FPS = 60;
	const std::string TITLE = "Simple 2D Physics Engine";

	sf::RenderWindow window;

	void Init();
	void Update();
public:
	void Run();
};