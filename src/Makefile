.PHONY: all clean

CXX=g++ -Wall -O3 -std=c++17


all: gen_ppm

gen_ppm: gen_ppm.o curve.o
	${CXX} -o $@ $^

%.o : %.cc
	${CXX} -o $@ -c $^

clean:
	rm -v *.o gen_ppm
