#include "Particle.h"

Particle::Particle(Vector2 position, Vector2 velocity, real mass) : position(position), velocity(velocity) {
	SetMass(mass);
}

void Particle::SetMass(real mass) {
	inverseMass = ((real)1) / mass;
}
real Particle::GetMass() const {
	return ((real)1) / inverseMass;
}

void Particle::Integrate(real dt) {
	position += velocity * dt + acceleration * 0.5 * dt * dt;
	velocity += acceleration * dt;
	acceleration.SetZero();
}
void Particle::ApplyForce(Vector2 force) {
	acceleration += force * inverseMass;
}
void Particle::AddAcceleration(Vector2 acceleration) {
	this->acceleration += acceleration;
}