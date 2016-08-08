/*
 * Particle.cpp
 *
 *  Created on: Aug 8, 2016
 *      Author: ericso0303
 */

#include "Particle.h"
#include <stdlib.h>
namespace explosions {

Particle::Particle() {
	// TODO Auto-generated constructor stub
	m_x = ((2.0 * rand())/RAND_MAX) - 1;
	m_y = ((2.0 * rand())/RAND_MAX) - 1;

	m_xspeed = 0.01 * ((2.0 * rand()/RAND_MAX) - 1);
	m_yspeed = 0.01 * ((2.0 * rand()/RAND_MAX) - 1);
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}
void Particle::update(){


	m_x += m_xspeed;
	m_y += m_yspeed;
}
} /* namespace explosions */
