/*
 * Swarm.cpp
 *
 *  Created on: Aug 8, 2016
 *      Author: ericso0303
 */

#include "Swarm.h"

namespace explosions {

Swarm::Swarm() {
	// TODO Auto-generated constructor stub
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	// TODO Auto-generated destructor stub
	delete [] m_pParticles;
}
void Swarm::update(){
	for(int i = 0; i < Swarm::NPARTICLES; i++){
		m_pParticles[i].update();
	}
}
} /* namespace explosions */
