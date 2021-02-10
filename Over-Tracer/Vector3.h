#pragma once
#include <iostream>
#include "Core.h"

#include <memory>

class Vector3
{
public:

	Vector3() {
		m_coordinates[0] = 0.0f;
		m_coordinates[1] = 0.0f;
		m_coordinates[2] = 0.0f;
	}
	Vector3(float x, float y, float z) {
		m_coordinates[0] = x;
		m_coordinates[1] = y;
		m_coordinates[2] = z;

	}
	Vector3(const Vector3& v) {
		m_coordinates[0] = v[0];
		m_coordinates[1] = v[1];
		m_coordinates[2] = v[2];

	}

	inline const Vector3& operator+(const Vector3& v) const {
		Vector3* res = new Vector3(); // empty

		(*res)[0] = m_coordinates[0] + v[0];
		(*res)[1] = m_coordinates[1] + v[1];
		(*res)[2] = m_coordinates[2] + v[2];

		return *res;
	}
	inline const Vector3& operator-(const Vector3& v) const {
		Vector3* res = new Vector3(); // empty

		(*res)[0] = m_coordinates[0] - v[0];
		(*res)[1] = m_coordinates[1] - v[1];
		(*res)[2] = m_coordinates[2] - v[2];

		return *res;
	}
	inline const Vector3& operator*(const float& k) const {
		Vector3* res = new Vector3(); // empty

		(*res)[0] = m_coordinates[0] * k;
		(*res)[1] = m_coordinates[1] * k;
		(*res)[2] = m_coordinates[2] * k;

		return *res;

	}
	inline const Vector3& operator/(const float& k) const {
		if (k == 0) {
			return *this;
		}

		Vector3* res = new Vector3(); // empty

		(*res)[0] = m_coordinates[0] / k;
		(*res)[1] = m_coordinates[1] / k;
		(*res)[2] = m_coordinates[2] / k;

		return *res;

	}
	inline const Vector3& operator+=(const Vector3& v) {

		m_coordinates[0] += v[0];
		m_coordinates[1] += v[1];
		m_coordinates[2] += v[2];

		return *this;

	}
	inline const Vector3& operator-=(const Vector3& v) {
		m_coordinates[0] -= v[0];
		m_coordinates[1] -= v[1];
		m_coordinates[2] -= v[2];

		return *this;

	}
	inline const Vector3& operator*=(const float& k) {
		m_coordinates[0] *= k;
		m_coordinates[1] *= k;
		m_coordinates[2] *= k;

		return *this;

	}

	inline float& operator[](int index) {
		return m_coordinates[index];

	}
	inline float operator[](int index) const {
		return m_coordinates[index];
	}

	inline const Vector3& multElements(const float& e1, const float& e2, const float& e3) {
		Vector3* res = new Vector3(m_coordinates[0] * e1,
			m_coordinates[1] * e2,
			m_coordinates[2] * e3); // empty

		return *res;

	}

	inline const Vector3& cross(const Vector3& v) const {
		Vector3* res = new Vector3(); // empty

		(*res)[0] = m_coordinates[1] * v[2] - m_coordinates[2] * v[1];
		(*res)[1] = m_coordinates[2] * v[0] - m_coordinates[0] * v[2];
		(*res)[2] = m_coordinates[0] * v[1] - m_coordinates[1] * v[0];

		return *res;

	}

	inline float norm() const {
		return sqrt(m_coordinates[0] * m_coordinates[0] +
			m_coordinates[1] * m_coordinates[1] +
			m_coordinates[2] * m_coordinates[2]);

	}
	inline const Vector3& normalize() const {
		return *this / this->norm();
	}
	inline float dot(const Vector3& v) const {
		return m_coordinates[0] * v[0] +
			m_coordinates[1] * v[1] +
			m_coordinates[2] * v[2];

	}

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

