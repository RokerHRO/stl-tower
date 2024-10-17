.PHONY: all clean

CXX=g++ -Wall -O3 -std=c++17


all: gen_ppm stl_tower

gen_ppm: gen_ppm.o curve.o
	${CXX} -o $@ $^

stl_tower: stl_tower.o curve.o stl.o
	${CXX} -o $@ $^

%.o : %.cc %.hh
	${CXX} -o $@ -c $<

clean:
	rm -v *.o gen_ppm
