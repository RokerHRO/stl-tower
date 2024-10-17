#ifndef STL_TOWER_TRIANGLE_HH
#define STL_TOWER_TRIANGLE_HH

#include "point.hh"

struct Triangle
{
	Triangle() = default;
	
	Triangle(Point3d _a, Point3d _b, Point3d _c)
	: a{_a}, b{_b}, c{_c}
	{}
	
	Point3d a,b,c;
	
	Point3d normal() const
	{
		const Point3d u = b-a;
		const Point3d v = c-a;
		
		return normalize( Point3d(u.y*v.z - u.z*v.y,  u.z*v.x - u.x*v.z,  u.x*v.y - u.y*v.x) );
	}
};

#endif //  STL_TOWER_TRIANGLE_HH
