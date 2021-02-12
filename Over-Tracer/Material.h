#pragma once
#include "Vector3.h"
#include "Color.h"
#include "Ray.h"
class Material
{

	public:
		virtual bool scatter(const Ray& in, const struct HitRecord& rec, Color& attenuation, Ray& out) const = 0;


};
//
//class UniformMaterial : public Material {
//
//
//	virtual void scatter(const Vector3& point) const override {
//		//ht.position = point;
//		//ht.material = this;
//	}
//
//	private:
//		Color albedo;
//};


//class Metal : public Material {
//
//
//public:
//	Metal(const Color& c) : albedo(c) {}
//
//	virtual bool scatter(const Ray& in, const struct HitRecord& rec, Color& attenuation, Ray& out) const override {
//
//		auto reflected = Vector3 reflect(*(*in.direction() * in.norm), *rec.normal);
//		out = *std::make_shared<Ray>(rec.position, reflected);
//		attenuation = albedo;
//
//		auto cond = (*in.direction() * in.norm)->dot(*rec.normal);
//		return cond > 0;
//	}
//
//private:
//	Color albedo;
//};

//class Matte : public Material {
//
//
//	virtual void scatter(const Vector3& point) const override {
//		//ht.position = point;
//		//ht.material = this;
//	}
//
//private:
//	Color albedo;
//};