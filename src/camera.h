#pragma once

#include "hittable.h"
#include "gbeam.h"

class Camera {
    public:
        double aspect_ratio = 1;
        int image_width = 100;

        void render(const Hittable& world);

    private:
        int image_height;
        // Camera center
        Point3 center;
        // Location of pixel 0, 0
        Point3 pixel00_loc;
        // Offset to pixel to the right
        Vec3 pixel_delta_u;
        // Offset to pixel below
        Vec3 pixel_delta_v;

        void initialize();
        Color ray_color(const Ray& r, const Hittable& world) const;
};
