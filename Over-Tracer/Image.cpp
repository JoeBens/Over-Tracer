#include "Image.h"
#include <fstream>
#include "Vector3.h"
#include "Color.h"
#include "Vector3.cpp"


Image::Image(int width, int height) :m_width(width),
m_height(height),
m_pixels(width*height) {}

Image::Image(const Image& img) : m_height(img.m_height),
m_width(img.m_width),
m_pixels(img.m_pixels) {}


bool Image::save(const char* filepath) {

	std::ofstream file(filepath);

	file << "P3" << std::endl;
	file << m_width << " " << m_height << std::endl;
	file << MAX_PIXEL_VALUE << std::endl;


	for (auto& c : m_pixels) {
		file << *(c.gammaCorrect()) << std::endl;
	}

	return true;
}



Color* Image::getPixel(int row, int col) {
	return &m_pixels[m_width*row + col];
} 