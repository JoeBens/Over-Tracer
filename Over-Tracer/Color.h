#pragma once

#include "Vector3.h"
#include <string>
#include <iostream>

float clamp(float c, float min ,float max);

class Color: public Vector3
{
public:
	Color();
	Color(float r, float g, float b);
	Color(const Vector3& v);
	Color(const std::string& hex);

	
	friend std::ostream& operator<< (std::ostream& out, const Color& color) {

		float scale = 1.0f / SAMPLES_PER_PIXEL;

		//Gamma correct
		float r = sqrt(scale*color[0]);
		float g = sqrt(scale*color[1]);
		float b = sqrt(scale*color[2]);



		out << static_cast<int>(255.0f*clamp(r, 0.0f, 0.999f)) << " "<<
			   static_cast<int>(255.0f*clamp(g, 0.0f, 0.999f)) << " "<<
			   static_cast<int>(255.0f*clamp(b, 0.0f, 0.999f)) << " ";


		return out;
	}
};

