#include "DragFG.h"

DragFG::DragFG(real k1, real k2)
	: k1(k1), k2(k2) {}

void DragFG::UpdateForce(Particle* particle, real dt) {
	if (particle->HasInfiniteMass()) return;

	real speed = particle->velocity.Magnitude();
	Vector2 velocityDir = particle->velocity.Normalize();
	Vector2 dragForce = velocityDir * (-speed * (k1 + k2 * speed));
	particle->AddForce(dragForce);
}