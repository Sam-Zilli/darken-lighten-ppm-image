// ppm.hpp
#pragma once

#include <string>
#include <vector>
#include "pixel.hpp"

class PPM {
	public:
		PPM(std::string filename); // constructor

		~PPM(); // destructor 

		void savePPM(std::string outFileName);
		void lighten();
		void darken();

	private:
		std::vector<int> mPixels;
		int mWidth;
		int mHeight;
		int mMaxRange;
};
