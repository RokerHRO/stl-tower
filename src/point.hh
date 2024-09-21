#ifndef STL_TOWER_PoINT_HH
#define STL_TOWER_PoINT_HH

template<unsigned DIM>
struct Point;


template<>
struct Point<2>
{
	Point<2>()
	: x{}, y{}
	{}
	
	Point<2>(double ax, double ay)
	: x{ax}, y{ay}
	{}
	
	Point<2>& operator+=(Point<2> p)
	{
		x+=p.x; y+=p.y;
		return *this;
	}
	
	Point<2>& operator-=(Point<2> p)
	{
		x-=p.x; y-=p.y;
		return *this;
	}
	
	Point<2>& operator*=(double d)
	{
		x*=d; y*=d;
		return *this;
	}

	double x,y;
};


template<>
struct Point<3>
{
	Point<3>()
	: x{}, y{}, z{}
	{}
	
	Point<3>(double ax, double ay, double az)
	: x{ax}, y{ay}, z{az}
	{}
	
	Point<3>& operator+=(Point<3> p)
	{
		x+=p.x; y+=p.y; z+=p.z;
		return *this;
	}
	
	Point<3>& operator-=(Point<3> p)
	{
		x-=p.x; y-=p.y; z-=p.z;
		return *this;
	}
	
	Point<3>& operator*=(double d)
	{
		x*=d; y*=d; z*=d;
		return *this;
	}

	double x,y,z;
};


template<unsigned DIM>
inline
Point<DIM> operator+(Point<DIM> p, Point<DIM> q)
{
	return p+=q;
}

template<unsigned DIM>
inline
Point<DIM> operator-(Point<DIM> p, Point<DIM> q)
{
	return p-=q;
}

template<unsigned DIM>
inline
Point<DIM> operator*(Point<DIM> p, double d)
{
	return p*=d;
}

typedef Point<3> Point3d;
typedef Point<2> Point2d;

#endif // STL_TOWER_PoINT_HH
