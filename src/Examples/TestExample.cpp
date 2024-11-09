#include "TestExample.h"

void TestExampleApp::Run() {
	Init();
	Update();
}

void TestExampleApp::Init() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Simple 2D Physics Engine", 7U, settings);
	window.setFramerateLimit(FPS);
	Renderer::UseWindow(&window);

	sf::View view(sf::FloatRect(0.0f, 0.0f, 100.0f, 100.0f));
	window.setView(view);
}

void TestExampleApp::Update() {
	ParticleForceRegistry forceRegistry;
	GravityFG gravityFG({ 0.0f, 25.0f });
	DragFG dragFG(0.8f, 0.9f);

	Particle particle(Vector2(25, 10), Vector2(), 20);
	Particle particle2(Vector2(75, 10), Vector2(-10, -5), 20);

	forceRegistry.Add(&particle, &gravityFG);
	forceRegistry.Add(&particle, &dragFG);
	forceRegistry.Add(&particle2, &gravityFG);

	sf::Clock clock;
	real dt;
	while (window.isOpen()) {
		dt = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
				window.close();
				break;
			}
		}

		forceRegistry.UpdateAllForce(dt);
		particle.Integrate(dt);
		particle2.Integrate(dt);

		Renderer::Clear();
		Renderer::DrawCircle(particle.position, 5, sf::Color::Red);
		Renderer::DrawCircle(particle2.position, 5, sf::Color::Blue);
		Renderer::Display();
	}
}