#pragma once
#include "Rgb.h"
#include "Vector3D.h"

class Poligon {
public:
    Vector3D a;
    Vector3D b;
    Vector3D c;
    Rgb color;
    Poligon() : a(Vector3D()), b(Vector3D()), c(Vector3D()), color(Rgb()) {}
    Poligon(Vector3D a, Vector3D b, Vector3D c, Rgb color) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->color = color;
    }

    void Draw() {
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_TRIANGLES);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
        glEnd();
    }

    void Draw(Rgb color) {
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_TRIANGLES);
        glVertex3f(a.x, a.y, a.z);
        glVertex3f(b.x, b.y, b.z);
        glVertex3f(c.x, c.y, c.z);
        glEnd();
    }
};