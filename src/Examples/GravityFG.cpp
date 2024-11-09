#include "GravityFG.h"

GravityFG::GravityFG(Vector2 gravity)
	: gravity(gravity) {}

void GravityFG::UpdateForce(Particle* particle, real dt) {
	if (particle->HasInfiniteMass()) return;

	particle->AddForce(gravity * particle->GetMass());
}