#pragma once

#include <Physics2D/ParticleForceGenerator.h>

class GravityFG : public ParticleForceGenerator {
private:
	Vector2 gravity; // Gravity acceleration
public:
	GravityFG(Vector2 gravity);
	virtual void UpdateForce(Particle* particle, real dt);
};