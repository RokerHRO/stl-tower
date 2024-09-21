#include "curve.hh"

#include <cstdio>
#include <cstdint>

struct RGB
{
	RGB() : r{}, g{}, b{}
	{}
	
	RGB(unsigned _r, unsigned _g, unsigned _b)
	: r(_r), g(_g), b(_b)
	{}
	
	uint8_t r,g,b;
};

const RGB White (255, 255, 255);
const RGB Red   (255,   0,   0);
const RGB Green (  0, 255,   0);
const RGB Blue  (  0,   0, 255);
const RGB Purple(255,   0, 255);

RGB img[1024][1024];

void print_ppm()
{
	printf("P6\n%u %u 255\n", 1024, 1024);
	fwrite(img, 1024, 1024*sizeof(RGB), stdout);
}

void setPixel(unsigned x, unsigned y, RGB color)
{
	if(x<1024 && y<1024)
	{
		img[y][x] = color;
	}
}

void draw(double x, double y, RGB color)
{
	setPixel( 512 + 128*x, 512 - 128*y, color);
}

void circle(double x, double y, double radius, RGB color)
{
	for(double phi=0; phi<2*M_PI; phi += M_PI/180)
	{
		const double c = cos(phi);
		const double s = sin(phi);
		
		draw(x + c*radius, y - s*radius, color);
	}
}

int main(int argc, char** argv)
{
	const int frame = argc>1 ? atoi(argv[1]) : 0;
	const double alpha = M_PI/4 - frame*0.01*(M_PI/4);
	
	Curve c = Curve::from_alpha( alpha );
	
	auto p = c.P();
	auto q = c.Q();
	
	circle(p.x, p.y, 0.1, Red);
	circle(-p.x, p.y, 0.1, Green);

	circle(q.x, +q.y, 0.1, Blue);
	circle(q.x, -q.y, 0.1, Purple);
	
	for(double phi = 0.0; phi<c.length(); phi += M_PI/180/4)
	{
		Point2d p = c(phi);
		draw(p.x, p.y, White);
	}
	
	print_ppm();
}
