#pragma once
#include <algorithm>
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

    void SetIlumination(float intensiti) {
        float lightIntensity = std::max(0.0f, intensiti);
        r *= lightIntensity;
        g *= lightIntensity;
        b *= lightIntensity;
    }

};