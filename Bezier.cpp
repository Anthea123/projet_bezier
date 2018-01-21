/**
 * \file Bezier.cpp
 * \brief Impémentation de la classe Bezier
 * \author Anthea Mérida, Amina Zhegida
 * \date 08/01/2018
 **/

#include "Bezier.h"

/*implémentation de l'algorithme de Casteljau*/
std::vector<Point> casteljau(std::vector<Point> vp){
	
	std::vector<Point> res;

	/*le paramètre t représente le pas avec lequel on va calculer 
	des barycentres entres les points de la courbe, plus il
	est proche de 0, mieux la courbe est définie*/
	for(double t = 0; t < 1; t = t+0.05){ //t+0.02
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

/*Constructeurs*/
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

/*Accesseurs*/
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

/*Opérateur de flux*/
std::ostream & operator<<(std::ostream & st, const Bezier & b){
	//st << " -- ";

	for(int i = 0; i < b.get_points().size(); i = i+1){
		st << b.get_points()[i] << std::endl;
	}

	return st;
}

/*fonction pour concaténer les vectors de deux courbes de Bézier*/
Bezier join(Bezier const & b1, Bezier const & b2){

	std::vector<Point> p = b1.get_points();
	for(int i = 0; i < b2.get_points().size(); i = i+1){
		p.push_back(b2.get_points()[i]);
	}
	

	Bezier res(b1.get_P1(), b2.get_P2(), p);

	return res;
}