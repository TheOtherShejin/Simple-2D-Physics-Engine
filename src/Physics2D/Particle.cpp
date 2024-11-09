#include <Physics2D/Particle.h>

Particle::Particle(Vector2 position, Vector2 velocity, real mass) : position(position), velocity(velocity) {
	SetMass(mass);
}

void Particle::SetMass(real mass) {
	inverseMass = ((real)1) / mass;
}
real Particle::GetMass() const {
	return ((real)1) / inverseMass;
}
bool Particle::HasInfiniteMass() const {
	return (inverseMass <= (real)0);
}

void Particle::Integrate(real dt) {
	if (inverseMass <= (real)0) return;

	acceleration = forceAccum * inverseMass;
	position += velocity * dt + acceleration * 0.5 * dt * dt;
	velocity += acceleration * dt;
	ClearForceAccumulation();
}
void Particle::AddForce(Vector2 force) {
	forceAccum += force;
}
void Particle::ClearForceAccumulation() {
	forceAccum.SetZero();
}