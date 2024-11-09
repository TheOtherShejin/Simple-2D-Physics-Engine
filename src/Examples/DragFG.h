#pragma once

#include <Physics2D/ParticleForceGenerator.h>

class DragFG : public ParticleForceGenerator {
private:
	// Drag Coefficients
	real k1;
	real k2;
public:
	DragFG(real k1, real k2);
	virtual void UpdateForce(Particle* particle, real dt);
};