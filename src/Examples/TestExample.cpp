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
	Particle particle(Vector2(50, 10), Vector2(), 20);

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

		particle.ApplyForce(Vector2(0, 500));
		particle.Integrate(dt);

		Renderer::Clear();
		Renderer::DrawParticle(&particle, 5, sf::Color::Red);
		Renderer::Display();
	}
}