#pragma once

#include <Physics2D/Particle.h>

class ParticleForceGenerator {
public:
	virtual void UpdateForce(Particle* particle, real dt) = 0;
};