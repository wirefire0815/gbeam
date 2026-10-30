#pragma once

#include "interval.h"
#include "ray.h"
#include "vec3.h"
#include <memory>

class Material;

class HitRecord {
    public:
        Point3 p;
        Vec3 normal;
        double t;
        bool front_face;
        std::shared_ptr<Material> mat;

        void set_face_normal(const Ray& r, const Vec3& outward_normal);
};

class Hittable {
    public:
        virtual ~Hittable() = default;

        virtual bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const = 0;
};
