#include "Bezier.h"
#include "Lettre.h"


int main(){
	//Point p(1,3);

	std::cout << " " << std::endl;

	Bezier b1 = Bezier(Point(98,2), Point(2, 46));
	Bezier b2 = Bezier(Point(0, 0), Point(100, 100));


	Bezier contour = join(b1, b2); 

	Lettre A("A", contour);

	std::cout << A << std::endl;

	return 0;
}