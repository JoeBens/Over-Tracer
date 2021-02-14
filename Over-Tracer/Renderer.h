#pragma once
#include "Object.h"
#include "Color.h"
#include "Vector3.h"
#include "Image.h"
#include "Core.h"
#include "Ray.h"
#include "Sphere.h"
#include "Camera.h"
class Renderer
{

public:

	Renderer(HitList& ht) {
		scene = ht;
	}

	//Create a camera and start rendering the scene
	void render() {

		Camera camera(WIDTH, HEIGHT);
		Image img(WIDTH, HEIGHT);

		size_t steps_completed = 0;
		auto total_steps = HEIGHT * WIDTH;

#pragma omp parallel for 
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {

				for (int sample = 0; sample < SAMPLES_PER_PIXEL; sample++) {
					auto ray = camera.pixelToRay(i, j);
					*(img.getPixel(i, j)) += OverTrace(*ray, scene, MAX_DEPTH);
				}
#pragma omp atomic
				++steps_completed;
				if (steps_completed % 10000 == 1) {
#pragma omp critical
					std::cout << "Progress: " << steps_completed << " of " << total_steps << " (" << std::fixed << std::setprecision(1) << (100.0 * steps_completed / total_steps) << "%)\n";
				}
			}
		}
		img.save("test.ppm");

	}
	//This is the recursive function that calculate the color of each pixel 
	//TODO: Optimise this scene as it the reason why the program is slow and consumes a lot of memory
	Color OverTrace(const Ray& ray, const HitList& scene, int depth) {

		if (depth <= 0) {
			return Color("000000");
		}
		HitRecord rec;
		if (scene.hit(ray, 0.0001f, 100000.0f, rec)) {


			//If the object we hit is of material Metal
			if (rec.ty == Metal) {

				auto reflectedRay = Ray(Vector3(), Vector3());

				//std::cout << "I am here" << std::endl;
				auto reflected = Vector3::reflect((ray.direction() * ray.norm), rec.normal);
				reflectedRay = Ray(rec.position, reflected);
				auto objColor = rec.m_c;
				auto r = (ray.direction() * ray.norm).dot(rec.normal);

				if (r > 0) {
					auto c = OverTrace(reflectedRay, scene, depth - 1);
					auto res = c.multElements(objColor[0], objColor[1], objColor[2]);
					return res;
				}

			}
			//If the object we hit is of material Diffuse or Matte (no specular)
			if (rec.ty == Diffuse) {

				auto p = rec.position + rec.normal + Vector3::random_unit_vector();
				auto reflected = rec.position - p;
				auto c = OverTrace(Ray(rec.position, reflected), scene, depth - 1);
				auto objColor = rec.m_c;

				auto diffuse = c.multElements(objColor[0], objColor[1], objColor[2]);
				return diffuse;
			}

			//If the object we hit is of material Light
			if (rec.ty == Luminous) {
				auto objColor = rec.m_c;
				return objColor * 10.0f;
			}

			return Color("111111");
		}

		//if we don't intersect with anything, we color the background with a gradient done by an interpolation from a color to another
		float t = 0.9 * (ray.direction())[0];
		auto white = Color("000000");
		//auto main = Color("0d0d0a");
		auto main = Color("F7FFAD");
		//auto main = Color("e63749");


		return main * (1.0 - t) + white * t;
	}


protected:
	HitList scene;

};

