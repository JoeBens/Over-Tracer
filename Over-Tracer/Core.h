#pragma once
#include <string>
#define DEFAULT_COLOR std::string("7B1FA2")
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define HEIGHT 480
#define WIDTH 640
#define MAX_DEPTH 15
#define SAMPLES_PER_PIXEL 3

#include <random>

static std::uniform_real_distribution<float> distribution(0.0, 1.0);
static std::mt19937 generator;


inline double random_double() {
	return distribution(generator);
}

inline double random_double(float min, float max) {
	return min + (max - min)*distribution(generator);//random_double();
}