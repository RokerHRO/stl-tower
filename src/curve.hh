#ifndef STL_TOWER_CURVE_HH
#define STL_TOWER_CURVE_HH

#include "point.hh"
#include <cmath>

class Curve
{
public:
	static Curve from_x(double x);
	static Curve from_y(double y);
	static Curve from_alpha(double alpha);
	
	Point2d operator()(double phi) const;
	
	static constexpr double pi = M_PI;
	
private:
	Curve(double ax, double ay, double aa)
	: px{ax}, qy{ay}, alpha{aa}
	, u{0.0,
	    pi/2 + aa,
	    pi/2 + 3*aa,
	    3*pi/2 + 5*aa,
	    3*pi/2 + 7*aa,
	    pi + 8*aa}
	{}
	
	const double px, qy, alpha;
	const double u[6];
};

#endif // STL_TOWER_CURVE_HH
