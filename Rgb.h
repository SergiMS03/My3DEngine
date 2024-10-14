#pragma once
class Rgb {
public:
    float r;
    float g;
    float b;
    Rgb() : r(0), g(0), b(0) {};
    Rgb(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
};