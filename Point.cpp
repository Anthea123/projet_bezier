/**
 * \file Point.cpp
 * \brief Impémentation de la classe Point
 * \author Anthea, Amina
 * \date 06/01/2018
 **/

#include "Point.h"

Point::Point(int x, int y){
	
	if(x < 0 || x > 100 || y < 0 || y > 100){
		throw "Mauvaises coordonnées";
	}

	_x = x;
	_y = y;
}

Point::Point(const Point & p){
	_x  = p.get_x();
	_y = p.get_y();
}

int Point::get_x() const{
	return _x;
}

int Point::get_y() const{
	return _y;
}

void Point::set_x(int new_x){
	_x  = new_x;
}

void Point::set_y(int new_y){
	_y  = new_y;
}

std::ostream & operator<<(std::ostream & st, const Point & p){
	st << "(" << p.get_x() << ", " << p.get_y() << ")";
	
	return st;
}