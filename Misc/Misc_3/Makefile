main: polymain.o poly.o
	cc *.o -Wall -o main -lm
polymain.o: polymain.c poly.h
	cc -c -g polymain.c
poly.o: poly.c poly.h
	cc -c -g poly.c
