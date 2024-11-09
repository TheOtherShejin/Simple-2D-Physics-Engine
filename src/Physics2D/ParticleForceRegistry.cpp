#include <Physics2D/ParticleForceRegistry.h>

void ParticleForceRegistry::Add(Particle* particle, ParticleForceGenerator* forceGenerator) {
	registrations.push_back({ particle, forceGenerator });
}
void ParticleForceRegistry::Remove(Particle* particle, ParticleForceGenerator* forceGenerator) {
	for (Registry::iterator iter = registrations.begin(); iter != registrations.end(); iter++) {
		if (iter->particle == particle && iter->forceGenerator == forceGenerator) {
			registrations.erase(iter);
			break;
		}
	}
}
void ParticleForceRegistry::Clear() {
	registrations.clear();
}
void ParticleForceRegistry::UpdateAllForce(real dt) {
	for (auto& registry : registrations) {
		registry.forceGenerator->UpdateForce(registry.particle, dt);
	}
}