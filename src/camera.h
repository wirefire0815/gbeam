#pragma once

#include "hittable.h"
#include "gbeam.h"

class Camera {
    public:
        double aspect_ratio   = 1.0;
        int image_width       = 100;
        int samples_per_pixel = 10;
        int max_depth         = 10;

        void render(const Hittable& world);

    private:
        int image_height;
        // Color scale factor for a sum of pixel samples
        double pixel_samples_scale;
        // Camera center
        Point3 center;
        // Location of pixel 0, 0
        Point3 pixel00_loc;
        // Offset to pixel to the right
        Vec3 pixel_delta_u;
        // Offset to pixel below
        Vec3 pixel_delta_v;

        void initialize();
        Ray get_ray(int x, int y) const;
        Color ray_color(const Ray& r, int depth, const Hittable& world) const;
        Vec3 sample_square() const;
};
