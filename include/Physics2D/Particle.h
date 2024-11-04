#pragma once

#include <Physics2D/Math/Vector2.h>
#include <Physics2D/Precisions.h>

class Particle {
private:
	Vector2 forceAccum;
	void ClearForceAccumulation();
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
};