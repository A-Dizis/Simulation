/*
 * Particle.h
 *
 *  Created on: 14 Μαΐ 2023
 *      Author: dizisa
 */
#include "Constants.h"
#include <iostream>

#ifndef SOURCE_PARTICLE_H_
#define SOURCE_PARTICLE_H_

class Particle {
	friend std::ostream &operator<<(std::ostream &, const Particle&);
private:
	static int counter;
	int myCounter = counter;
	double r[REAL_DIMENSIONS];
	double v[REAL_DIMENSIONS];

public:
	Particle();
	virtual ~Particle();
	const double* getR() const;
	const double* getV() const;
	void add(Particle p);
	int getNo();
	void move(double time);
};



#endif /* SOURCE_PARTICLE_H_ */
