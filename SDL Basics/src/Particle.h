/*
 * Particle.h
 *
 *  Created on: Aug 8, 2016
 *      Author: ericso0303
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace explosions {

//structs are just public by default
struct Particle {
	double m_x;
	double m_y;
	double m_xspeed;
	double m_yspeed;
	Particle();
	virtual ~Particle();
	void update();
};

} /* namespace explosions */

#endif /* PARTICLE_H_ */
