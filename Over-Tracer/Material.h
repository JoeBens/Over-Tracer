#pragma once
#include "Vector3.h"
#include "Color.h"
class Material
{

	virtual void scatter(const Vector3& point) const = 0;


};

class UniformMaterial : public Material {


	virtual void scatter(const Vector3& point) const override {
		//ht.position = point;
		//ht.material = this;
	}

	private:
		Color albedo;
};