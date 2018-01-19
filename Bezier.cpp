/**
 * \file Bezier.cpp
 * \brief Impémentation de la classe Bezier
 * \author Anthea, Amina
 * \date 08/01/2018
 **/

#include "Bezier.h"


std::vector<Point> casteljau(std::vector<Point> vp){
	/*bool test_egalite = true;
	
	for(int i = 0; i < vp.size()-1; i = i+1){
		if(vp[i] != vp[i+1]){
			test_egalite = false;
		}
	}

	if(test_egalite){
		return vp;
	}
	else{
		std::vector<Point> res = vp;
		std::vector<Point> tmp1 = vp;
		
		while(tmp1.size() > 1){
			std::vector<Point> tmp2;
			
			for(int i = 0; i < vp.size()-1; i = i+1){
				tmp2[i] = barycentre(tmp1[i], tmp1[i+1]);	
			}
			
			tmp1 = tmp2;
		}

		res.push_back(tmp1[0]);

		return res;
	}
	*/
	std::vector<Point> res;
	//res.push_back(vp[0]);

	for(double t = 0; t < 1; t = t+0.1){ //t+0.02
		std::vector<Point> tmp1 = vp;

		while(tmp1.size() > 1){
			std::vector<Point> tmp2;

			for(int i = 0 ; i < tmp1.size()-1 ; i = i+1)
            {
                Point p1 = tmp1[i];
                Point p2 = tmp1[i+1];

                tmp2.push_back(barycentre(t, p1, p2));
            }

            tmp1 = tmp2;

		}

		res.push_back(tmp1[0]);

	}

	return res;
}

Bezier::Bezier(Point P1, Point C, Point P2){
	_P1 = Point(P1);
	_C = Point(C);
	_P2 = Point(P2);

	std::vector<Point> p;

	p.push_back(P1);
	p.push_back(C);
	p.push_back(P2);

	points = casteljau(p);
}

Bezier::Bezier(Point P1, Point P2): Bezier(P1, barycentre(0.5, P1, P2), P2){
	
}

Bezier::Bezier(Point P1, Point P2, std::vector<Point> vp){
	_P1 = Point(P1);
	_C = Point(barycentre(0.5, P1, P2));
	_P2 = Point(P2);

	points = std::vector<Point>(vp);
}

Bezier::Bezier(const Bezier & b){
	_P1 = b.get_P1();
	_C = b.get_C();
	_P2 = b.get_P2();
	points = b.get_points();
}


/*Bezier::~Bezier(){
	points.~vector();
}*/

Point Bezier::get_P1() const{
	return _P1;
}

Point Bezier::get_C() const{
	return _C;
}

Point Bezier::get_P2() const{
	return _P2;
}

std::vector<Point> Bezier::get_points() const{
	return points;
}

std::ostream & operator<<(std::ostream & st, const Bezier & b){
	//st << " -- ";

	for(int i = 0; i < b.get_points().size(); i = i+1){
		st << b.get_points()[i] << std::endl;
	}

	return st;
}

Bezier join(Bezier const & b1, Bezier const & b2){

	std::vector<Point> p = b1.get_points();
	for(int i = 0; i < b2.get_points().size(); i = i+1){
		p.push_back(b2.get_points()[i]);
	}
	

	Bezier res(b1.get_P1(), b2.get_P2(), p);

	return res;
}