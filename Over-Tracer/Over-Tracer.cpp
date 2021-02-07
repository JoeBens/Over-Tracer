#include <iostream>
#include "Vector3.h"
#include "Image.h"
#include "Color.h"
#include "core.h"
#include "Ray.h"
#include "Sphere.h"
#include "Object.h"
#include "Camera.h"
#include <iomanip>

struct LightSource {
	Color m_color;
	Vector3 position;

	LightSource() :m_color("e4ff00"), position(1.0f, 1.0f, -5.0f){}
};

struct LightSource ls;




//Color color(const Ray& ray, const HitList& world, int depth) {
//	//std::cout << ray.direction().norm();
//
//
//
//
//	int ns = 50;
//	if (depth <= 0) {
//		return Color("000000");
//	}
//
//	HitRecord rec;
//	if (world.hit(ray, 0.0001f, 100000.0f, rec)) {
//		//return EPIC::Color("FFC107");
//		//return EPIC::Color(((EPIC::Vec3<float>(1.0f, 1.0f, 1.0f) + rec.normal))*0.5f);
//		auto p = rec.position + rec.normal + Vector3::random_unit_vector();
//		auto reflected = rec.position - p;
//		//auto c = color(Ray(rec.position,reflected ), world, depth - 1);
//		auto objColor = Color("fe6060");
//		auto ks = 1.0f;
//		auto kd = 0.5f;
//		auto ka = 0.5f;
//		auto to_light =Ray(rec.position, ls.position - rec.position);
//
//		auto tmp = rec.normal.dot(to_light.direction());
//		//std::cout << tmp << std::endl;
//		auto diffuse = objColor*kd*MAX(tmp, 0);
//		//auto diffuse = Vector3();
//		tmp = pow(rec.normal.dot(to_light.direction()), ns);
//		auto specular = objColor *ks *MAX(tmp, 0);
//		auto specular = Vector3();
//		//to_light.m_origin = to_light.pointAt(1.0f);
//		/*bool intersects = world.hit(to_light, 0.0001f, 100000.0f, rec);
//		return (diffuse + specular)*(1.0f-intersects);*/
//
//		return (diffuse + specular);
//
//	}
//
//	float t = 0.5*(ray.direction()[1] + 1.0);
//	auto white = Color("FFFFFF");
//	auto main = Color("03a9f4");
//
//
//	return main * (1.0 - t) + white * t;
//}

Color color(const Ray& ray, const HitList& world, int depth) {
	//std::cout << ray.direction().norm();

	int ns = 50;
	if (depth <= 0) {
		return Color("000000");
	}

	HitRecord rec;
	if (world.hit(ray, 0.0001f, 100000.0f, rec)) {
		//return EPIC::Color("FFC107");
		//return EPIC::Color(((EPIC::Vec3<float>(1.0f, 1.0f, 1.0f) + rec.normal))*0.5f);
		auto p = rec.position + rec.normal + Vector3::random_unit_vector();
		auto reflected = rec.position - p;
		auto c = color(Ray(rec.position, reflected), world, depth - 1);
		auto objColor = rec.m_c;
		auto ks = 0.0f;
		auto kd = 0.5f;


		auto tmp = rec.normal.dot(reflected);
		//std::cout << tmp << std::endl;
		auto diffuse = c.multElements(objColor[0], objColor[1], objColor[2]);
		auto specular = Vector3();

		return diffuse + specular;

	}

	float t = 0.5*(ray.direction()[1] + 1.0);
	auto white = Color("FFFFFF");
	auto main = Color("958ace");


	return main * (1.0 - t) + white * t;
}



int main()
{
    std::cout << "Hello World!\n";
	// world
	HitList world;
	world.add(std::make_shared<Sphere>(Vector3(0.3f, 0.2f, -1.0f), 0.15f, Color("dbf67a")));
	world.add(std::make_shared<Sphere>(Vector3(0.0f, 0.0f, 0.0f), 0.4f, Color("ff45eb")));
	world.add(std::make_shared<Sphere>(Vector3(-0.3f, 0.2f, -1.0f), 0.15f, Color("ff0b0b")));
	world.add(std::make_shared<Sphere>(Vector3(0.0f, 100.5f, -1.0f), 100.0f, Color("1b172d")));

	Camera camera(WIDTH, HEIGHT);
	Image img(WIDTH, HEIGHT);

	float aspectRatio = ((float)WIDTH) / ((float)HEIGHT);

	float xmin = -1.0f;
	float xmax = +1.0f;
	float deltaX = (float)(xmax - xmin) / (float)(WIDTH - 1);

	float ymin = -1.0f / aspectRatio;
	float ymax = +1.0f / aspectRatio;
	float deltaY = (float)(ymax - ymin) / (float)(HEIGHT - 1);


	size_t steps_completed = 0;
	auto total_steps = HEIGHT * WIDTH;

	#pragma omp parallel for 
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {

			for (int sample = 0; sample < SAMPLES_PER_PIXEL; sample++) {
				auto ray = camera.getRay(i, j);
				*(img.getPixel(i, j)) += color(*ray, world, MAX_DEPTH);
			}
			#pragma omp atomic
			++steps_completed;
			if (steps_completed % 10000 == 1) {
			#pragma omp critical
				std::cout << "Progress: " << steps_completed << " of " << total_steps << " (" << std::fixed << std::setprecision(1) << (100.0*steps_completed / total_steps) << "%)\n";
			}
		}
		


		
	}
	img.save("test.ppm");
	return 0;


}
