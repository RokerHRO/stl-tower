#include "stl.hh"
#include <cstdint>

#define _BSD_SOURCE
#include <endian.h> // Linux only

namespace
{
	static const uint8_t header[80] = {'\0'};
	
	union FU
	{
		float f;
		uint32_t u;
	};
	
	inline
	uint32_t dtole32(double d)
	{
		FU fu;
		fu.f = d;
		return htole32(fu.u);
	}
	
	void write_point(Point3d p, FILE* f)
	{
		const uint32_t au[3] = { dtole32(p.x), dtole32(p.y), dtole32(p.z) };
		fwrite(au, sizeof(uint32_t), 3, f);
	}
}

void STL::write_binary_stl(FILE* output) const
{
	fwrite(header, sizeof(header), 1, output);
	const uint32_t num_triangles = htole32(d.size());
	fwrite(&num_triangles, sizeof(num_triangles), 1, output);
	for(const Triangle& t : d)
	{
		write_point(t.normal(), output);
		write_point(t.a, output);
		write_point(t.b, output);
		write_point(t.c, output);
		fputc('\0', output);  // dummy uint16_t value
		fputc('\0', output);
	}
	fflush(output);
}
