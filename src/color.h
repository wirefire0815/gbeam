#pragma once

#include "vec3.h"

using Color = Vec3;

void write_color(std::ostream& out, const Color& pixel_color);
inline double linear_to_gamma(double linear_component);
