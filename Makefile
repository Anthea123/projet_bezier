CC = g++ 
CFLAGS = -std=c++11 -Wall -Wextra -ansi -g

all: bezier

Point.o: Point.cpp Point.h
	${CC} ${CFLAGS} -c Point.cpp

Bezier.o: Bezier.cpp Bezier.h Point.h
	${CC} ${CFLAGS} -c Bezier.cpp

Lettre.o: Lettre.cpp Lettre.h Bezier.h Point.h
	${CC} ${CFLAGS} -c Lettre.cpp

main.o: main.cpp Point.h Bezier.h Lettre.h
	${CC} ${CFLAGS} -c main.cpp

bezier: Lettre.o Bezier.o Point.o main.o
	${CC} ${CFLAGS} $^ -o $@

doc: Doxyfile
	doxygen Doxyfile
clean:
	rm *.o