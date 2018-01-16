#include "Bezier.h"


int main(){
	//Point p(1,3);

	std::cout << " " << std::endl;

	Point P1(75,17);
	Point C(56,34);
	Point P2(36,77);

	Point P12(76,16);
	Point C2(56,35);
	Point P22(32,77);

	Bezier b(P1, C, P2);

	Bezier b2(P12, C2, P22);

	Bezier b3 = join(b, b2);

	std::cout << b3 << std::endl;

	return 0;
}