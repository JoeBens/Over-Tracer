#pragma once
#include <iostream>
class Vector3
{
public:

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(const Vector3& v);

	Vector3& operator+(const Vector3& v);
	Vector3& operator-(const Vector3& v);
	Vector3& operator*(const float& k);
	Vector3& operator/(const float& k);
	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator*=(const float& v);

	float& operator[](int index);
	float operator[](int index) const;

	Vector3& cross(const Vector3& v);

	float norm();
	Vector3& normalize();
	float dot(const Vector3& v);


private:
	float m_coordinates[3];



};

