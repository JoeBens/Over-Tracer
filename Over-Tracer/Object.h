#pragma once
#include "Vector3.h"
#include "Ray.h"
class Object
{
public:

	virtual const Vector3& normalAt(const Vector3& point) const { return point; };
	virtual const Vector3& scatter(const Vector3& point) const { return point; };

	void move(const Vector3& position) {
		m_position = position;
	}


protected:
	Vector3 m_position;
};
struct HitRecord {
	Vector3 position;
	Vector3 normal;
	float t;
};


class Hitable {
public:
	virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& record) const { return false; };
};


class HitList : Hitable {

public:
	void add(std::shared_ptr<Hitable> obj) {
		objects.push_back(obj);
	}

	virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& record) const {

		bool hit_something = false;
		auto closest_so_far = t_max;
		HitRecord temp_rec;

		for (auto object : objects) {
			if (object->hit(ray, t_min, t_max, temp_rec)) {
				hit_something = true;
				if (closest_so_far > temp_rec.t) {
					closest_so_far = temp_rec.t;
					record = temp_rec;
				}
			}
		}

		return hit_something;
	}

private:
	std::vector<std::shared_ptr<Hitable>> objects;
};

