#pragma once
#include <string>
#define DEFAULT_COLOR std::string("7B1FA2")
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


//Here you can define the image size and how many samples per pixel you want
//WARNING : Since this code runs terribly, I'd suggest you choose low values for Samples_Per_Pixel if you define a high resolution; For example : 10
#define HEIGHT 480
#define WIDTH 640
#define MAX_DEPTH 30
#define SAMPLES_PER_PIXEL 100




#include <random>

static std::uniform_real_distribution<float> distribution(0.0, 1.0);
static std::mt19937 generator;


inline double random_double() {
	return distribution(generator);
}

inline double random_double(float min, float max) {
	return min + (max - min)*distribution(generator);
}