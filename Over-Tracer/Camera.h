#pragma once
#include "Vector3.h"
#include "Ray.h"
#include <memory>

//Camera following the pinhole model

class Camera
{
public:


	Camera(int width, int height) {


		origin[0] = 0.0f;
		origin[1] = 0.0f;
		origin[2] = -10.0f;


		viewPortHeight = height;
		viewPortWidth = width;

		float aspectRatio = ((float)width) / ((float)height);

		viewPortX[0] = -1.0f;
		viewPortX[1] = +1.0f;
		viewPortX[2] = (float)(viewPortX[1] - viewPortX[0]) / (float)(width - 1);


		viewPortY[0] = -1.0f / aspectRatio;
		viewPortY[1] = +1.0f / aspectRatio;
		viewPortY[2] = (float)(viewPortY[1] - viewPortY[0]) / (float)(height - 1); 


		fov = 0.0f;

	}


	std::shared_ptr<Ray> pixelToRay(int i, int j) const {

		double y = viewPortY[0] + (i + random_double())*viewPortY[2];
		double x = viewPortX[0] + (j + random_double())*viewPortX[2];
		return std::make_shared<Ray>(origin, Vector3(x, y, fov) - origin);
	}



private:

	float fov;

	Vector3 origin;
	Vector3 lowerLeftCorner;

	int viewPortHeight;
	int viewPortWidth;

	Vector3 viewPortX;
	Vector3 viewPortY;
};

