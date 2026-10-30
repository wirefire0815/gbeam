#pragma once

#include "hittable.h"
#include "ray.h"
#include <cmath>
#include <memory>

class Sphere : public Hittable {
public:
    Sphere(const Point3& center, double radius, std::shared_ptr<Material> mat) : center(center), radius(std::fmax(0, radius)), mat(mat) {}

    bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;

    private:
        Point3 center;
        double radius;
        std::shared_ptr<Material> mat;
};
