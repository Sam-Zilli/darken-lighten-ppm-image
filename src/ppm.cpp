#include "ppm.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

PPM::PPM(std::string filename) {
	std::ifstream inputFile;
	inputFile.open(filename);

	bool foundP3 = false;
	bool foundDimensions = false;
	bool foundRange = false;
	//bool readingPixels = false;

	if(inputFile.is_open()) {
		std::string line;
		
		while(std::getline(inputFile, line)) {
			std::stringstream stream(line);
			std::string chunk_of_data;
			
			while(stream >> chunk_of_data) {
				if(chunk_of_data[0] == '#') {
					break;
				} else if(false == foundP3) {
					if(chunk_of_data=="P3") {
						foundP3=true;
					}
				} else if(false == foundDimensions) {
					mWidth = std::stoi(chunk_of_data);
					stream >> chunk_of_data;
					mHeight = std::stoi(chunk_of_data);
					foundDimensions = true;
				} else if(false == foundRange) {
					mMaxRange = std::stoi(chunk_of_data);
					foundRange = true;
				} else {
					int data = std::stoi(chunk_of_data);
					std::cout << data << std::endl;
					mPixels.push_back(data);
				}
			}
		}

		inputFile.close();
	}
}

PPM::~PPM() {
	std::cout << "PPM::~PPM()" << std::endl;
}

void PPM::savePPM(std::string outFileName) {
	std::ofstream myFile;
	myFile.open(outFileName);
	for (int i = 0; i < mPixels.size(); i++) {
		myFile << mPixels[i] << "\n";
	}
	myFile.close();
}

void PPM::lighten() {
	for (int i = 0; i < mPixels.size(); i++) {
		int data = mPixels[i] * 4;
		mPixels[i] = std::clamp(data, 0, mMaxRange);
	}
}

void PPM::darken() {
	for (int i = 0; i < mPixels.size(); i++) {
		int data = mPixels[i]/4;
		mPixels[i] = std::clamp(data, 0, mMaxRange);
	}
}
