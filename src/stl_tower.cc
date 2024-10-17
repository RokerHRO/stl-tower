#include "curve.hh"
#include "stl.hh"
#include "triangle.hh"

const unsigned Steps = 20;

STL stl;

void ground_plane(const Curve& c)
{
	const Point2d p = c.P();
	const double dx = (2*p.x)/(Steps-1);
	const double db = (c.length()/2)/(Steps-1);
	
	const Point3d PP{ c.P().x, 0, 0.5};
	const Point3d MP{-c.P().x, 0, 0.5};
	
	double b = 0;
	double x = p.x;
	
	Point3d b0{c(0.0).x, 0, 0};
	
	for(unsigned step=1; step<=Steps; ++step, b+=db, x-=dx)
	{
		const Point2d q = c(b);
		const Point3d b1{q.x, q.y, 0};
		
		if(q.x > c.P().x)
		{
			stl.add(PP, b0, b1);
		}else if(q.x < -c.P().x)
		{
			stl.add(MP, b0, b1);
		}else{
			const Point3d p1{ q.x, 0, 0};
			const Point3d p0{b0.x, 0, 0};
			
			stl.add(p1, p0, b0);
			stl.add(p1, b0, b1);
			fprintf(stderr, "#%03u : p1:<%f %f %f>  b1:<%f %f %f>\n",
				step,
				p1.x, p1.y, p1.z,
				b1.x, b1.y, b1.z);
		}
		
		b0=b1;
	}
	
	const unsigned num = stl.size();
	for(unsigned n=0; n<num; ++n)
	{
		const Triangle& t = stl[n];
		stl.add(-t.a, -t.c, -t.b);
	}
}

int main()
{
	// ground plane
	Curve c0 = Curve::from_alpha(M_PI/4);
	ground_plane(c0);
	fprintf(stderr, "STL contains %zu triangles.\n", stl.size());
	stl.write_binary_stl(stdout);
}