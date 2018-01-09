#include "Bezier.h"


int main(){
	//Point p(1,3);

	std::cout << " " << std::endl;

	Point P1(75,17);
	Point C(56,34);
	Point P2(36,77);

	Bezier b(P1, C, P2);

	std::cout << b << std::endl;

	return 0;
}