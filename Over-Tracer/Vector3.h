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


	inline static const Vector3& random();
	inline static std::shared_ptr<Vector3> random(float min, float max);
	inline static std::shared_ptr<Vector3> random_unit_sphere();
	inline static const Vector3& random_unit_vector();





protected:
	float m_coordinates[3];



};

std::ostream& operator<< (std::ostream& out, Vector3& v) {
	out << v[0] << " " << v[1] << " " << v[2] << std::endl;
	return out;
}