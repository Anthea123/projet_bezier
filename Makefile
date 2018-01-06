CC = g++ 
CFLAGS = -std=c++11 -Wall -Wextra -ansi -g

all: bezier

Point.o: Point.cpp Point.h
	${CC} ${CFLAGS} -c Point.cpp

main.o: main.cpp Point.h
	${CC} ${CFLAGS} -c main.cpp

bezier: Point.o main.o
	${CC} ${CFLAGS} $^ -o $@

doc: Doxyfile
	doxygen Doxyfile
