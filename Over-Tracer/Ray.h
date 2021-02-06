#pragma once

#include "Vector3.h"
class Ray
{
public:
	Ray(const Vector3& origin, const Vector3& direction) {
		m_direction = direction;
		m_direction = m_direction.normalize();
		m_origin = origin;
	}

	const Vector3& origin() const { return m_origin; }
	const Vector3& direction() const { return m_direction; }

	const Vector3& pointAt(float dist) const {
		return m_direction * dist + m_origin;
	}

private:
	Vector3 m_direction;
	Vector3 m_origin;
};

