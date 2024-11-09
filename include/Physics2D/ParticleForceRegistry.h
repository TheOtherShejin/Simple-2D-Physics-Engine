#pragma once

#include <Physics2D/Particle.h>
#include <Physics2D/ParticleForceGenerator.h>
#include <vector>

class ParticleForceRegistry {
protected:
	struct ParticleForceRegistration {
		Particle* particle;
		ParticleForceGenerator* forceGenerator;
	};

	typedef std::vector<ParticleForceRegistration> Registry;
	Registry registrations;

public:
	void Add(Particle* particle, ParticleForceGenerator* forceGenerator);
	void Remove(Particle* particle, ParticleForceGenerator* forceGenerator);
	void Clear();
	void UpdateAllForce(real dt);
};