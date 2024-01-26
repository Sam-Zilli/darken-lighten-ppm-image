# darken-lighten-ppm-image

Use this file to darken or lighten PPM images, photoshop style!

To compile: g++ -std=c++20 -I include/ src/*.cpp -o prog
To run: ./prog "<pathToInputFile>"

Your edited file will be saved in the assets folder.

For now, the lighten and darken paramters are set at 4* or /4 the original pixel value.
