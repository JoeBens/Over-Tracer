#pragma once
#include "Vector3.h"
#include "Color.h"
#include "Ray.h"
#include "Object.h"




class Sphere : virtual public Object, public Hitable
{
public:
	Sphere(const Vector3& origin, float radius, const Color &c , Type t){
		Object::m_position = origin;
		m_radius = radius;
		m_c = c;
		type = t;
	}


	virtual const Vector3& normalAt(const Vector3& point) const {
		return (Object::m_position - point).normalize();
	}


	virtual const Vector3& scatter(const Vector3& point) const {
		return point;
	}


	virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& record) const {

		Vector3 sphereToRay = ray.origin() - m_position;
		//std::cout<<"Sphere to ray: " << sphereToRay;
		float b = sphereToRay.dot(ray.direction())*2.0;
		//std::cout<<"b = "<<b<<std::endl;
		float c = sphereToRay.dot(sphereToRay) - m_radius * m_radius;
		//std::cout<<"c = "<<c<<std::endl;
		float delta = b * b - 4 * c;
		//std::cout<<"delta = "<<delta<<std::endl;
		if (delta < 0)
			return false;

		auto sqrt_d = sqrt(delta);
		auto root = (float)(-b - sqrt_d) / 2.0f;

		if (root < t_min || root > t_max) {
			root = (float)(-b + sqrt_d) / 2.0f;
			if (root < t_min || root > t_max) {
				return false;
			}
		}

		record.t = root;
		record.position = ray.pointAt(root);
		record.normal = normalAt(record.position);
		record.m_c = m_c;
		record.ty = type;

		return true;
	}


private:
	float m_radius;
	Color m_c;
	Type type;

};

