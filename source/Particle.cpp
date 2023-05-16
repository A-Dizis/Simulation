/*
 * Particle.cpp
 *
 *  Created on: 14 Μαΐ 2023
 *      Author: dizisa
 */

#include "Particle.h"
#include <iostream>
#include <random>
#include <chrono>
#include<cstdlib>

int Particle::counter = 0;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
const double k_T = 0.1;
std::gamma_distribution<double> maxwell(3./2., k_T);

Particle::Particle() {
	for (int i = 0; i < REAL_DIMENSIONS; ++i) {
		r[i] = (double)(rand()/(double)RAND_MAX);
		v[i] = maxwell(generator);
	}

	Particle::counter++;

}

Particle::~Particle() {

}

const double* Particle::getR() const {
	return r;
}

const double* Particle::getV() const {
	return v;
}

int Particle::getNo(){
	return Particle::myCounter;
}

void Particle::add(Particle p){
	for (int i = 0;  i < REAL_DIMENSIONS; ++ i) {
		Particle::r[i] = Particle::r[i] + p.r[i];
		Particle::v[i] = Particle::v[i] + p.v[i];
	}
}

std::ostream &operator<<(std::ostream & os, const Particle & p)
{
    os << "pos = " << "(" << p.getR()[0] << ", " << p.getR()[1] << ", " << p.getR()[2] << ")" << " | " &&
    os << "vel = " << "(" << p.getV()[0] << ", " << p.getV()[1] << ", " << p.getV()[2] << ")" << " ";
    return os;
}

void Particle::move(double time) {
	for(int i = 0; i < REAL_DIMENSIONS; ++i) {
		r[i] += v[i]*time;
	}
}
