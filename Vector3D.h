#pragma once
class Vector3D {
public:
	float x;
	float y;
	float z;
	Vector3D() : x(0), y(0), z(0) {}
	Vector3D(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};