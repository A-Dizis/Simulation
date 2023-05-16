#include <iostream>
#include "Particle.cpp"

int main(){

	Particle p[500];

	for (int i = 0; i < 500; i++) {
		std::cout << p[i] << " | Particle No: " << p[i].getNo() << std::endl;
	}

	return 0;
}
