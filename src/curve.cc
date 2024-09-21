#include "curve.hh"
#include <cmath>

Point2d rotate(Point2d m, double phi)
{
	const double s = sin(phi);
	const double c = cos(phi);
	
	return Point2d(m.x + c, m.y + s);
}


Curve Curve::from_x(double x)
{
	const double y = sqrt(4.0 - x*x);
	return Curve(x, y, atan(x/y) );
}


Curve Curve::from_y(double y)
{
	const double x = sqrt(4.0 - y*y);
	return Curve(x, y, atan(x/y) );
}


Curve Curve::from_alpha(double alpha)
{
	const double x = sin(alpha)*2;
	const double y = cos(alpha)*2;
	return Curve(x,y, alpha);
}


Point2d Curve::operator()(double phi) const
{
	while(phi<0)
		phi += u[5];
	
	while(phi>u[5])
		phi -= u[5];
	
	if(phi<u[1])
		return rotate( Point2d(px,0), phi);
	else if(phi<u[2])
		return rotate( Point2d(0,qy), 3*pi/2 + alpha - (phi-u[1]));
	else if(phi<u[3])
		return rotate( Point2d(-px,0), phi-u[2] + (pi/2-alpha));
	else if(phi<u[4])
		return rotate( Point2d(0,-qy), pi/2 + alpha - (phi-u[3]));
	else
		return rotate( Point2d(px,0), -pi/2-alpha + phi-u[4]);
}
