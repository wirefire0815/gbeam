#include <iostream>
#include "color.h"
#include "vec3.h"
#include "ray.h"

bool hit_sphere(const Point3& center, double radius, const Ray& r) {
    Vec3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b*b - 4*a*c;
    return discriminant >= 0;
}

Color ray_color(const Ray& r) {
    if (hit_sphere(Point3(0,0,-1), 0.5, r))
        return Color(1,0,0);

    Vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*Color(1.0,1.0,1.0) + a * Color(0.5, 0.7, 1.0);
}

int main() {

    auto aspect_ration = 16.0 / 9.0;
    int image_width = 1920;

    int image_height = int(image_width / aspect_ration);
    image_height = (image_height < 1) ? 1 : image_height;

    // distance from viewport to camera center point
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
    auto camera_center = Point3(0, 0, 0);

    auto viewport_u = Vec3(viewport_width, 0, 0);
    auto viewport_v = Vec3(0, -viewport_height, 0);

    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    auto viewport_upper_left = camera_center - Vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int x = 0; x < image_height; ++x) {
        std::clog << "\rScanlines remaining : " << (image_height - x) << ' ' << std::flush;
        for (int y = 0; y <  image_width; ++y) {
            auto pixel_center = pixel00_loc + (y * pixel_delta_u) + (x * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            Ray r(camera_center, ray_direction);

            Color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.                   \n";
}
