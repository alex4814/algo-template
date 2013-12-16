#include "cg.h"








Vector3 operator + (Vector3 a, Vector3 b) {
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}
Vector3 operator - (Point3 a, Point3 b) {
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}
Vector3 operator * (Vector3 a, double k) {
	return Vector3(a.x * k, a.y * k, a.z * k);
}
Vector3 operator / (Vector3 a, double k) {
	return Vector3(a.x / k, a.y / k, a.z / k);
}
bool operator == (const Point3 &a, const Point3 &b) {
	return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0 && sgn(a.z - b.z) == 0;
}
inline double dot(Vector3 a, Vector3 b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
inline double length(Vector3 a) {
	return sqrt(dot(a, a));
}
inline double angle(Vector3 a, Vector3 b) {
	return acos(dot(a, b) / length(a) / length(b));
}
inline Vector3 cross(Vector3 a, Vector3 b) {
	return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

