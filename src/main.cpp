// main.cpp

#include <iostream>
#include "ppm.hpp"


void test1(std::string filename) {
	PPM myPPM("./assets/myppm_p3.ppm");
	myPPM.lighten();
	myPPM.savePPM("./assets/lighten.ppm");
	std::cout << "Test one ran successfully" << std::endl;
}

void test2(std::string filename) {
	PPM myPPM("./assets/myppm_p3.ppm");
	myPPM.darken();
	myPPM.savePPM("./assets/darken.ppm");
	std::cout << "Test two ran successfully" << std::endl;
}

int main(int argc, char* argv[]) {
	if(argc < 2) {
		std::cout << "Cannot run program" << std::endl;
	}

	std::cout << "argument count: " << argc << std::endl;
	std::cout << "argv[0] is " << argv[0] << std::endl;
	std::cout << "argv[1] is " << argv[1] << std::endl;

	test1(argv[1]);
	test2(argv[2]);
	return 0;
}





