/*
 * Swarm.h
 *
 *  Created on: Aug 8, 2016
 *      Author: ericso0303
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"
namespace explosions {

class Swarm {
public:
	const static int NPARTICLES = 3000;
private:
	Particle *m_pParticles;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);
	const Particle * const getParticles(){return m_pParticles;};
};

} /* namespace explosions */

#endif /* SWARM_H_ */
