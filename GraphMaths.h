#pragma once
#include <stdexcept>
#include <math.h>
#include "Vector3D.h"
#include "Poligon.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define ASPECT_RATIO SCREEN_WIDTH / SCREEN_HEIGHT
#define Z_NEAR 0.1f
#define Z_FAR 1000.0f
#define FOV 90

//Prototipos
void InitProyectionMatrix(float screenWidth, float screenHeight, float zNear, float zFar, float fov);
Vector3D CalcProjection(Vector3D& vecInput, float matrix[4][4]);
void RotateX(float elapsedTime, Poligon* poligonInput);
void RotateY(float elapsedTime, Poligon* poligonInput);
void RotateZ(float elapsedTime, Poligon *poligonInput);



//PROYECCIONES
bool initializedPM = false;
float proyectionMatrix[4][4] = {0};
void InitProyectionMatrix(float screenWidth, float screenHeight, float zNear, float zFar, float fov) {
	float FovRadians = 1.0f / tanf(fov * 0.5f / 180.0f * 3.14159f);
	float aspectRatio = screenWidth / screenHeight;

	//Calculos de PROYECCIÓN
    proyectionMatrix[0][0] = ASPECT_RATIO * FovRadians;
    proyectionMatrix[1][1] = FovRadians;
    proyectionMatrix[2][2] = Z_FAR / (Z_FAR - Z_NEAR);
    proyectionMatrix[3][2] = (-Z_FAR * Z_NEAR) / (Z_FAR - Z_NEAR);
    proyectionMatrix[2][3] = 1.0f;
	initializedPM = true;
}

//!IMPORTANT! First you have to initialize the projection matrix with the InitProyectionMatrix function that you have in this library
Vector3D CalcProjection(Vector3D& vecInput, float matrix[4][4]){
	if (!initializedPM) {
		throw std::runtime_error("Before using CalcProjection you must initialize the projection matrix with the InitProyectionMatrix function that you have in this library");
	}

	Vector3D vecResult;
    vecResult.x = vecInput.x * matrix[0][0] + vecInput.y * matrix[1][0] + vecInput.z * matrix[2][0] + matrix[3][0];
    vecResult.y = vecInput.x * matrix[0][1] + vecInput.y * matrix[1][1] + vecInput.z * matrix[2][1] + matrix[3][1];
    vecResult.z = vecInput.x * matrix[0][2] + vecInput.y * matrix[1][2] + vecInput.z * matrix[2][2] + matrix[3][2];
    float w = vecInput.x * matrix[0][3] + vecInput.y * matrix[1][3] + vecInput.z * matrix[2][3] + matrix[3][3];

    if (w != 0) {
        vecResult.x /= w;
        vecResult.y /= w;
        vecResult.z /= w;
    }

    return vecResult;
}

//ROTACIONES
//https://en.wikipedia.org/wiki/Rotation_matrix
void RotateX(float elapsedTime, Poligon* poligonInput) {
    float RotationMatrix[4][4] = { 0 };
    //Calculos de ROTACION X
    float theta = 1.0f * elapsedTime;
    RotationMatrix[0][0] = 1;
    RotationMatrix[1][1] = cosf(theta * 0.5f);//0.5f
    RotationMatrix[1][2] = sinf(theta * 0.5f);//0.5f
    RotationMatrix[2][1] = -sinf(theta * 0.5f);//0.5f
    RotationMatrix[2][2] = cosf(theta * 0.5f);//0.5f
    RotationMatrix[3][3] = 1;//Evitamos que afecte a w en MultiplyMatrixVector
    poligonInput->a = CalcProjection(poligonInput->a, RotationMatrix);
    poligonInput->b = CalcProjection(poligonInput->b, RotationMatrix);
    poligonInput->c = CalcProjection(poligonInput->c, RotationMatrix);
}
void RotateY(float elapsedTime, Poligon* poligonInput) {
    float RotationMatrix[4][4] = { 0 };
    //Calculos de ROTACION Y
    float theta = 1.0f * elapsedTime;
    RotationMatrix[0][0] = cosf(theta);
    RotationMatrix[0][2] = -sinf(theta);
    RotationMatrix[1][1] = 1;
    RotationMatrix[2][0] = sinf(theta);
    RotationMatrix[2][2] = cosf(theta);
    RotationMatrix[3][3] = 1;//Evitamos que afecte a w en MultiplyMatrixVector
    poligonInput->a = CalcProjection(poligonInput->a, RotationMatrix);
    poligonInput->b = CalcProjection(poligonInput->b, RotationMatrix);
    poligonInput->c = CalcProjection(poligonInput->c, RotationMatrix);
}
void RotateZ(float elapsedTime, Poligon *poligonInput) {
    float RotationMatrix[4][4] = { 0 };
    //Calculos de ROTACION Z
    float theta = 1.0f * elapsedTime;
    RotationMatrix[0][0] = cosf(theta);
    RotationMatrix[0][1] = sinf(theta);
    RotationMatrix[1][0] = -sinf(theta);
    RotationMatrix[1][1] = cosf(theta);
    RotationMatrix[2][2] = 1;
    RotationMatrix[3][3] = 1;//Evitamos que afecte a w en MultiplyMatrixVector
    poligonInput->a = CalcProjection(poligonInput->a, RotationMatrix);
    poligonInput->b = CalcProjection(poligonInput->b, RotationMatrix);
    poligonInput->c = CalcProjection(poligonInput->c, RotationMatrix);
}