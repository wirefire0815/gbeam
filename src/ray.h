#include "vec3.h"

class Ray {
    public:
        Ray() {}

        Ray(const Point3& origin, const Vec3& direction) : orig(origin), dir(direction) {}

        const Point3& origin() const { return orig; }
        const Point3& direction() const { return dir; }

        Point3 at(double t) const;

    private:
        Point3 orig;
        Vec3 dir;
};
