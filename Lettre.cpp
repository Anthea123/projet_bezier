/**
 * \file Bezier.cpp
 * \brief Impémentation de la classe Lettre
 * \author Anthea, Amina
 * \date 17/01/2018
 **/

#include "Lettre.h"

Lettre::Lettre(std::string nom, const Bezier & courbes){
	_nom = std::string(nom);
	_courbes = Bezier(courbes);
	
	_points = new int*[100];
	for(int i = 0; i < 100; i = i+1){
		_points[i] = new int[100];
	}

	if(!_points){
		throw "allocation failed";
	}

	for(int i = 0; i < 100; i = i+1){
		for(int j = 0; j < 100; j = j+1){
			_points[i][j] = 0;
		}
	}


	for(int k = 0; k < courbes.get_points().size(); k = k+1){
		for(int i = 0; i < 100; i = i+1){
			for(int j = 0; j < 100; j = j+1){
				if(courbes.get_points()[k].get_x() == i && courbes.get_points()[k].get_y() == j){
					_points[i][j] = 1;
				}
			}
		}
	}
}

Lettre::Lettre(const Lettre & l) : Lettre(l.get_nom(), l.get_courbes()) { 

}

std::string Lettre::get_nom() const{
	return _nom;
}

		
Bezier Lettre::get_courbes() const{
	return _courbes;
}

void Lettre::get_points(int points[100][100]) const{
	for(int i = 0; i < 100; i = i+1){
		for(int j = 0; j < 100; j = j+1){
			points[i][j] = _points[i][j];
		}
	}
}

std::ostream & operator<<(std::ostream & st, const Lettre & l){

	int points[100][100];

	l.get_points(points);

	for(int i = 0; i < 100; i = i+1){
		for(int j = 0; j < 100; j = j+1){
			if(points[i][j] == 0){
				st << " ";
			}

			if(points[i][j] == 1){
				st << ".";
			}

			if(points[i][j] == 2){
				st << "*";
			}
		}
		st << std::endl;
	}

	return st;
}
