#include <iostream>
#include "Particle.cpp"

int main(){

	Particle p[5];

	for (int i = 0; i < 5; i++) {
		std::cout << p[i] << " | Particle No: " << p[i].getNo() << std::endl;
	}

	int steps = 5;
	for(int i=0; i<steps; i++){
		std::cout << "step | " << i << std::endl;
		for(int j=0; j<5; j++){
			p[j].move(0.1);
			std::cout << p[j] << " | Particle No: " << p[j].getNo() << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}
