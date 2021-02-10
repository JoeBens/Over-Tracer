
#include <math.h>
#include <iostream>
#include "Core.h"
//Empty Constructor
Vector3::Vector3() {
	
}

//Constructor
Vector3::Vector3(float x, float y, float z) {
	
}

//Constructor copy
Vector3::Vector3(const Vector3& v) {

}


#pragma region Operators
const Vector3& Vector3::operator+(const Vector3& v) const {

	
}


const Vector3& Vector3::operator-(const Vector3& v) const {
	

	
}

const Vector3& Vector3::operator*(const float& k) const {



}

const Vector3& Vector3::operator/(const float& k) const {


}

const Vector3& Vector3::operator+=(const Vector3& v) {


}


const Vector3& Vector3::operator-=(const Vector3& v) {



}


const Vector3& Vector3::operator*=(const float& k) {


}

float& Vector3::operator[](int index) {
	
}

float Vector3::operator[](int index) const {
	
}

#pragma endregion



//Cross product
const Vector3& Vector3::cross(const Vector3& v) const {

	
}



//Dot product
float Vector3::dot(const Vector3& v) const {

}




//Normalize
float Vector3::norm() const{

}

const Vector3& Vector3::normalize() const{

}

const Vector3& Vector3::multElements(const float& e1, const float& e2, const float& e3) {
	


}


