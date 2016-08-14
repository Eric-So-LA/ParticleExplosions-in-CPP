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
private:
	double m_speed;
	double m_direction;
private:
	void init();
public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace explosions */

#endif /* PARTICLE_H_ */
