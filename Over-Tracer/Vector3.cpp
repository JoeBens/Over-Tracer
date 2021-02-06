#include "Vector3.h"
#include <math.h>
#include <iostream>


//Empty Constructor
Vector3::Vector3() {
	m_coordinates[0] = 0.0f;
	m_coordinates[1] = 0.0f;
	m_coordinates[2] = 0.0f;
}

//Constructor
Vector3::Vector3(float x, float y, float z) {
	m_coordinates[0] = x;
	m_coordinates[1] = y;
	m_coordinates[2] = z;
}

//Constructor copy
Vector3::Vector3(const Vector3& v) {
	m_coordinates[0] = v[0];
	m_coordinates[1] = v[1];
	m_coordinates[2] = v[2];
}


#pragma region Operators
Vector3& Vector3::operator+(const Vector3& v) {

	Vector3* res = new Vector3(); // empty

	(*res)[0] = m_coordinates[0] + v[0];
	(*res)[1] = m_coordinates[1] + v[1];
	(*res)[2] = m_coordinates[2] + v[2];

	return *res;
}


Vector3& Vector3::operator-(const Vector3& v) {
	Vector3* res = new Vector3(); // empty

	(*res)[0] = m_coordinates[0] - v[0];
	(*res)[1] = m_coordinates[1] - v[1];
	(*res)[2] = m_coordinates[2] - v[2];

	return *res;
}

Vector3& Vector3::operator*(const float& k) {

	Vector3* res = new Vector3(); // empty

	(*res)[0] = m_coordinates[0] * k;
	(*res)[1] = m_coordinates[1] * k;
	(*res)[2] = m_coordinates[2] * k;

	return *res;

}

Vector3& Vector3::operator/(const float& k) {

	if (k == 0) {
		return *this;
	}

	Vector3* res = new Vector3(); // empty

	(*res)[0] = m_coordinates[0] / k;
	(*res)[1] = m_coordinates[1] / k;
	(*res)[2] = m_coordinates[2] / k;

	return *res;
}

Vector3& Vector3::operator+=(const Vector3& v) {

	m_coordinates[0] += v[0];
	m_coordinates[1] += v[1];
	m_coordinates[2] += v[2];

	return *this;

}


Vector3& Vector3::operator-=(const Vector3& v) {

	m_coordinates[0] -= v[0];
	m_coordinates[1] -= v[1];
	m_coordinates[2] -= v[2];

	return *this;

}


Vector3& Vector3::operator*=(const float& k) {

	m_coordinates[0] *= k;
	m_coordinates[1] *= k;
	m_coordinates[2] *= k;

	return *this;
}

float& Vector3::operator[](int index) {
	return m_coordinates[index];
}

float Vector3::operator[](int index) const {
	return m_coordinates[index];
}

#pragma endregion



//Cross product
Vector3& Vector3::cross(const Vector3& v) {

	Vector3* res = new Vector3(); // empty

	(*res)[0] = m_coordinates[1] * v[2] - m_coordinates[2] * v[1];
	(*res)[1] = m_coordinates[2] * v[0] - m_coordinates[0] * v[2];
	(*res)[2] = m_coordinates[0] * v[1] - m_coordinates[1] * v[0];

	return *res;
}



//Dot product
float Vector3::dot(const Vector3& v) {
	return m_coordinates[0] * v[0] +
		m_coordinates[1] * v[1] +
		m_coordinates[2] * v[2];
}





float Vector3::norm() {
	return sqrt(m_coordinates[0] * m_coordinates[0] +
		m_coordinates[1] * m_coordinates[1] +
		m_coordinates[2] * m_coordinates[2]);
}

Vector3& Vector3::normalize() {
	return *this / this->norm();
}
