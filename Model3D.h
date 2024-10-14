#pragma once
#include <vector>
#include "Poligon.h"
#include "GraphMaths.h"

class Model3D {
public:
    std::vector<Poligon> poligons;
    Model3D() {}

    void Draw(float elapsedTime, bool rotateX = false, bool rotateY = false, bool rotateZ = false) {
        for (int i = 0; i < poligons.size(); i++)
        {
            Poligon polCopy = poligons[i];
            Poligon triProjected, triTranslated;

            if(rotateX)
                RotateX(elapsedTime, &polCopy);
            if (rotateY)
                RotateY(elapsedTime, &polCopy);
            if (rotateZ)
                RotateZ(elapsedTime, &polCopy);
            

            polCopy.a.z = polCopy.a.z + 2.0f;
            polCopy.b.z = polCopy.b.z + 2.0f;
            polCopy.c.z = polCopy.c.z + 2.0f;

            triProjected.a = CalcProjection(polCopy.a, proyectionMatrix);
            triProjected.b = CalcProjection(polCopy.b, proyectionMatrix);
            triProjected.c = CalcProjection(polCopy.c, proyectionMatrix);

            triProjected.Draw(polCopy.color);
        }
    }

    static Model3D BuildCube() {
        Model3D cube;
        Rgb red(1.0f, 0.0f, 0.0f);
        Rgb green(0.0f, 1.0f, 0.0f);
        Rgb blue(0.0f, 0.0f, 1.0f);
        Rgb pink(1.0f, 0.0f, 1.0f);
        Rgb cian(0.0f, 1.0f, 1.0f);
        Rgb yellow(1.0f, 1.0f, 0.0f);
        cube.poligons = {
            //South
            Poligon(Vector3D(-0.5, -0.5, -0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(0.5, 0.5, -0.5), red),
            Poligon(Vector3D(-0.5, -0.5, -0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(0.5, -0.5, -0.5), red),

            //East
            Poligon(Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(0.5, 0.5, 0.5), green),
            Poligon(Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, 0.5, 0.5), Vector3D(0.5, -0.5, 0.5), green),

            //North
            Poligon(Vector3D(0.5, -0.5, 0.5), Vector3D(0.5, 0.5, 0.5), Vector3D(-0.5, 0.5, 0.5), blue),
            Poligon(Vector3D(0.5, -0.5, 0.5), Vector3D(-0.5, 0.5, 0.5), Vector3D(-0.5, -0.5, 0.5), blue),

            //Weast
            Poligon(Vector3D(-0.5, -0.5, 0.5), Vector3D(-0.5, 0.5, 0.5), Vector3D(-0.5, 0.5, -0.5), pink),
            Poligon(Vector3D(-0.5, -0.5, 0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, -0.5, -0.5), pink),

            //Top
            Poligon(Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, 0.5, 0.5), Vector3D(0.5, 0.5, 0.5), cian),
            Poligon(Vector3D(-0.5, 0.5, -0.5), Vector3D(0.5, 0.5, 0.5), Vector3D(0.5, 0.5, -0.5), cian),

            //Bottom
            Poligon(Vector3D(-0.5, -0.5, -0.5), Vector3D(-0.5, -0.5, 0.5), Vector3D(0.5, -0.5, 0.5), yellow),
            Poligon(Vector3D(-0.5, -0.5, -0.5), Vector3D(0.5, -0.5, 0.5), Vector3D(0.5, -0.5, -0.5), yellow)
        };

        return cube;
    }
};