#pragma once

#include "Vector3.h"
#include <string>
#include <iostream>
int clamp(float c);

class Color: public Vector3
{
public:
	Color();
	Color(int r, int g, int b);
	Color(const Vector3& v);
	Color(const Vector3& v);
	Color(const std::string& hex);

	inline Color* gammaCorrect() {
		return new Color(clamp(sqrt((float)m_coordinates[0] / (256.0f*SAMPLES_PER_PIXEL))),
			clamp(sqrt((float)m_coordinates[1] / (256.0f*SAMPLES_PER_PIXEL))),
			clamp(sqrt((float)m_coordinates[2] / (256.0f*SAMPLES_PER_PIXEL))));;
	}
};

