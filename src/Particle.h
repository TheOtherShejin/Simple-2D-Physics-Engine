#pragma once

#include "Vector2.h"
#include "Precisions.h"

class Particle {
public:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	real inverseMass;

	Particle(Vector2 position, Vector2 velocity, real mass);
	void SetMass(real mass);
	real GetMass() const;

	void Integrate(real dt);
	void ApplyForce(Vector2 force);
	void AddAcceleration(Vector2 acceleration);
};