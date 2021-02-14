
/*
Things to improve/Add :
* Code performance
* Material class instead of doing everything in OverTrace function
* Light system (right now I'm pretending that there is only one source of light
* More shapes like triangles and cubes
* More materials such as glass material
* More Camera Model (to add Depth of Field for instance)
* 3D models
* Camera movement (user input)
*/


#include <iostream>
#include "Vector3.h"
#include "Image.h"
#include "Color.h"
#include "Core.h"
#include "Ray.h"
#include "Sphere.h"
#include "Object.h"
#include "Camera.h"
#include <iomanip>
#include "Renderer.h"


//You can add and mess around with spheres here
//To change the size of the image and the quality, change the parameters in Core.h
int main()
{
    std::cout << "Good Morning Vietnaaaaaaaaaaaaam!\n";

	HitList scene;
	scene.add(std::make_shared<Sphere>(Vector3(0.3f, 0.2f, -1.0f), 0.15f, Color("ff0b0b"), Diffuse));
	scene.add(std::make_shared<Sphere>(Vector3(-0.3f, -0.2f, -1.0f), 0.15f, Color("ff0b0b"), Diffuse));
	scene.add(std::make_shared<Sphere>(Vector3(0.3f, -0.2f, -1.0f), 0.15f, Color("ff0b0b"), Diffuse));
	scene.add(std::make_shared<Sphere>(Vector3(0.0f, 0.0f, 0.0f), 0.4f, Color("f9fc5b"), Metal));
	scene.add(std::make_shared<Sphere>(Vector3(-0.3f, 0.2f, -1.0f), 0.15f, Color("ff0b0b"), Diffuse));
	//scene.add(std::make_shared<Sphere>(Vector3(0.6f, 0.5f, -1.0f), 0.15f, Color("dbf67a"), Luminous));
	//scene.add(std::make_shared<Sphere>(Vector3(-0.6f, 0.5f, -1.0f), 0.15f, Color("dbf67a"), Luminous));
	//scene.add(std::make_shared<Sphere>(Vector3(0.6f, -0.7f, -1.0f), 0.15f, Color("dbf67a"), Luminous));
	//scene.add(std::make_shared<Sphere>(Vector3(-0.6f, -0.7f, -1.0f), 0.15f, Color("dbf67a"), Luminous));
	scene.add(std::make_shared<Sphere>(Vector3(0.0f, 100.5f, -1.0f), 100.0f, Color("1b172d"), Diffuse));
	//scene.add(std::make_shared<Sphere>(Vector3(0.3f, 0.2f, -1.0f), 0.15f, Color("dbf67a"), Metal));
	//scene.add(std::make_shared<Sphere>(Vector3(0.0f, 0.0f, 0.0f), 0.4f, Color("ff45eb"), Metal));
	//scene.add(std::make_shared<Sphere>(Vector3(0.0f, -0.2f, 20.0f), 10.0f, Color("46676a"), Metal));
	//scene.add(std::make_shared<Sphere>(Vector3(-0.3f, 0.2f, -1.0f), 0.15f, Color("ff0b0b"), Metal));
	//scene.add(std::make_shared<Sphere>(Vector3(0.0f, 100.5f, -1.0f), 100.0f, Color("1b172d"), Diffuse));


	Renderer renderer(scene);
	renderer.render();
	
	return 0;

}

