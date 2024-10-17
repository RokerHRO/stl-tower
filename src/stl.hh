#ifndef STL_TOWER_STL_HH
#define STL_TOWER_STL_HH

#include "triangle.hh"
#include <deque>
#include <cstdio>

class STL
{
public:
	STL() = default;
	
	size_t size() const { return d.size(); }
	
	void add(Point3d a, Point3d b, Point3d c) { d.emplace_back(a,b,c); }
	void push_back(const Triangle& t) { d.push_back(t); }
	
	const Triangle& operator[](size_t n) const { return d[n]; }
	
	void write_binary_stl(FILE* output) const;

private:
	std::deque<Triangle> d;
};

#endif // STL_TOWER_STL_HH
