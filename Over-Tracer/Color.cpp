#include "Color.h"
#include "Vector3.h"
#include <string>

#include "Core.h"


//float clamp(float c) {
//	float o = static_cast<int>(c * 255);
//	o = MAX(0, o);
//	return MIN(o, 255);
//
//	/*
//	
//	if(c > max){
//	return max
//
//	if(c < min){
//	return min
//	}
//
//	return c:
//	*/
//}


float clamp(float c, float min, float max) {
	/*float o = static_cast<int>(c * 255);
	o = MAX(0, o);
	return MIN(o, 255);*/


	if(c > max)
		return max;
	if(c < min)
		return min;
	return c;
	
}


Color::Color() :Vector3(0, 0, 0) {}

Color::Color(const Vector3& v) : Vector3(v[0], v[1], v[2]) {}
Color::Color(float r, float g, float b) : Vector3(r, g, b) {}

Color::Color(const std::string& hex) : Vector3(std::stoi(hex.substr(0, 2), 0, 16)/256.0f,
		std::stoi(hex.substr(2, 2), 0, 16)/256.0f,
		std::stoi(hex.substr(4, 2), 0, 16)/256.0f) {}