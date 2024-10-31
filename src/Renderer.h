#pragma once

#include <SFML/Graphics.hpp>
#include "Particle.h"
#include <iostream>

class Renderer {
private:
	Renderer() {}
	static bool CheckError();
public:
	static sf::RenderWindow* window;

	static void UseWindow(sf::RenderWindow* window);
	static void Clear(sf::Color color = sf::Color::Black);
	static void DrawParticle(Particle* particle, real radius, sf::Color color);
	static void Display();
};