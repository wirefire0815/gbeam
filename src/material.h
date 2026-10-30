#pragma once

#include "color.h"
#include "hittable.h"
#include "ray.h"
#include "vec3.h"
class Material {
    public:
        virtual ~Material() = default;
        virtual bool scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered) const = 0;
};

class Lambertian : public Material {
    public:
        Lambertian(const Color& albedo) : albedo(albedo) {}
        bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override;

    private:
        Color albedo;
};


class Metal : public Material {
    public:
        Metal(const Color& albedo) : albedo(albedo) {}
        bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override;

    private:
        Color albedo;
};
