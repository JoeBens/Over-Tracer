#pragma once
#include <iostream>
#include "Core.h"

#include <memory>

class Vector3
{
public:

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(const Vector3& v);

	const Vector3& operator+(const Vector3& v) const;
	const Vector3& operator-(const Vector3& v) const;
	const Vector3& operator*(const float& k) const;
	const Vector3& operator/(const float& k) const;
	const Vector3& operator+=(const Vector3& v);
	const Vector3& operator-=(const Vector3& v);
	const Vector3& operator*=(const float& v);

	float& operator[](int index);
	float operator[](int index) const;

	const Vector3& multElements(const float& e1, const float& e2, const float& e3);

	const Vector3& cross(const Vector3& v) const;

	float norm() const;
	const Vector3& normalize() const;
	float dot(const Vector3& v) const;

	inline static const Vector3& random() {
		return Vector3((float)random_double(), (float)random_double(), (float)random_double());
	}

	inline static std::shared_ptr<Vector3> random(float min, float max) {
		return std::make_shared<Vector3>(random_double(min, max), random_double(min, max), random_double(min, max));
	}

	inline static std::shared_ptr<Vector3> random_unit_sphere() {
		while (true) {
			auto p = random(-1.0f, 1.0f);
			if (p->norm() >= 1) continue;
			return p;
		}
	}

	inline static const Vector3& random_unit_vector() {
		return random_unit_sphere()->normalize();
	}

	friend std::ostream& operator<< (std::ostream& out, Vector3& v) {
		out << v[0] << " " << v[1] << " " << v[2] << std::endl;
		return out;
	}


protected:
	float m_coordinates[3];



};

