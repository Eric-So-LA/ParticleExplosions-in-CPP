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
	const static int NPARTICLES = 5000;
private:
	Particle *m_pParticles;
public:
	Swarm();
	virtual ~Swarm();
	void update();
	const Particle * const getParticles(){return m_pParticles;};
};

} /* namespace explosions */

#endif /* SWARM_H_ */
