#include "Color.h"
#include "Vector3.h"
#include "Vector3.cpp"
#include <string>

//#include "core.h"


int clamp(float c) {
	int o = static_cast<int>(c * 255);
	o = MAX(0, o);
	return MIN(o, 255);
}


Color::Color() :Vector3(0, 0, 0) {}

Color::Color(const Vector3& v) : Vector3(v) {}
Color::Color(const Vector3& v) : Vector3() {
	Vector3::m_coordinates[0] = clamp(v[0]);
	Vector3::m_coordinates[1] = clamp(v[1]);
	Vector3::m_coordinates[2] = clamp(v[2]);
}
Color::Color(int r, int g, int b) : Vector3(r, g, b) {}

	//Color::Color(const std::string& hex) : Vec3<int>(std::stoi(hex.substr(0, 2), 0, 16),
	//	std::stoi(hex.substr(2, 2), 0, 16),
	//	std::stoi(hex.substr(4, 2), 0, 16)) {}