#pragma once

#include "hittable.h"
#include "ray.h"
#include <cmath>

class Sphere : public Hittable {
public:
    Sphere(const Point3& center, double radius) : center(center), radius(std::fmax(0, radius)) {}

    bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;

    private:
        Point3 center;
        double radius;
};
