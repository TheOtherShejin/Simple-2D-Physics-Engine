#include "Renderer.h"

sf::RenderWindow* Renderer::window = nullptr;

bool Renderer::CheckError() {
	if (window == nullptr) {
		std::cout << "[Renderer] Window is not given.\n";
		return true;
	}
	return false;
}

void Renderer::UseWindow(sf::RenderWindow* window) {
	Renderer::window = window;
}

void Renderer::Clear(sf::Color color) {
	if (CheckError()) return;
	window->clear(color);
}

void Renderer::DrawParticle(Particle* particle, real radius, sf::Color color) {
	if (CheckError()) return;

	sf::CircleShape shape(radius, 100);
	shape.setFillColor(color);
	shape.setOrigin(radius, radius);
	shape.setPosition(particle->position.x, particle->position.y);
	window->draw(shape);
}

void Renderer::Display() {
	if (CheckError()) return;
	window->display();
}