#include "cg.h"
#include "pv.h"
#include "position.h"
#include "circle.h"





inline double area_of_triangle(Point a, Point b, Point c) {
    return length(cross(b - a, c - a)) / 2;
}
