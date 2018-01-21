/**
 * \file Point.cpp
 * \brief Impémentation de la classe Point
 * \author Anthea Mérida, Amina Zhegida
 * \date 06/01/2018
 **/

#include "Point.h"

/*Constructeurs*/
Point::Point(){
	_x = 0;
	_y = 0;
}

Point::Point(int x, int y){
	
	if(x < 0 || x > 50 || y < 0 || y > 50){
		throw "Mauvaises coordonnées";
	}

	_x = x;
	_y = y;
}

Point::Point(const Point & p){
	_x  = p.get_x();
	_y = p.get_y();
}


/*Accesseurs des membres*/
int Point::get_x() const{
	return _x;
}

int Point::get_y() const{
	return _y;
}


/*Opérateurs de comparaison*/
bool operator==(Point const & p1, Point const & p2){
	return (p1.get_x() == p2.get_x() && p1.get_y() == p2.get_y());
}

bool operator!=(Point const & p1, Point const & p2){
	return !(p1 == p2);
}

/*Opérateur de flux*/
std::ostream & operator<<(std::ostream & st, const Point & p){
	//st << "(" << p.get_x() << ", " << p.get_y() << ")";
	st <<  p.get_x() << ", " << p.get_y();
	
	return st;
}

/*Calcul d'un barycentre de paramètre t entre 0 et 1*/
Point barycentre(double t, Point const & p1, Point const & p2){
	int x = p1.get_x() * (1-t) + p2.get_x() * t;
    int y = p1.get_y() * (1-t) + p2.get_y() * t;

    return Point(x, y);
}