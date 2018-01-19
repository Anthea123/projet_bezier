/**
 * \file Lettre.cpp
 * \brief Impémentation de la classe Lettre
 * \author Anthea, Amina
 * \date 17/01/2018
 **/

#include "Lettre.h"

Lettre::Lettre(std::string nom, Type type, const Bezier & courbes){
	_nom = std::string(nom);
	_type = type;
	_courbes = Bezier(courbes);
	
	_points = new int *[50];
	for(int i = 0; i < 50; i = i+1){
		_points[i] = new int[50];
	}

	if(!_points){
		throw "allocation failed";
	}

	for(int i = 0; i < 50; i = i+1){
		for(int j = 0; j < 50; j = j+1){
			_points[i][j] = 0;
		}
	}


	for(int i = 0; i < 50; i = i+1){
		for(int j = 0; j < 50; j = j+1){
			for(int k = 0; k < courbes.get_points().size(); k = k+1){
				if(courbes.get_points()[k].get_x() == j && courbes.get_points()[k].get_y() == 50-i){
					_points[i][j] = 1;
				}
			}
		}
	}
	
	/*if(type == Filled){
		fill_table(_points, 50);
	}*/
	
	if(type == Outline){
		outline(_points, 50, 1, 2);
		outline(_points, 50, 2, 3);
	}
}

Lettre::Lettre(const Lettre & l) : Lettre(l._nom, l._type,l._courbes) { 

}

std::string Lettre::get_nom() const{
	return _nom;
}

		
Bezier Lettre::get_courbes() const{
	return _courbes;
}

void Lettre::get_points(int points[50][50]) const{
	for(int i = 0; i < 50; i = i+1){
		for(int j = 0; j < 50; j = j+1){
			points[i][j] = _points[i][j];
		}
	}
}

std::ostream & operator<<(std::ostream & st, const Lettre & l){

	int points[50][50];

	l.get_points(points);

	for(int i = 0; i < 50; i = i+1){
		for(int j = 0; j < 50; j = j+1){
			if(points[i][j] == 0){
				st << " ";
			}

			if(points[i][j] == 1){
				st << ".";
			}

			if(points[i][j] == 2 || points[i][j] == 3){
				st << "*";
			}
		}
		st << std::endl;
	}

	return st;
}

/*void fill_table(int ** tab, int size){
	int i = 1;
	int j = 1;

	bool test = false;

	while(i < size && test == false){
		while(j < size-1 && test == false){
			if(tab[i][j-1] == 1 && tab[i][j] == 0){

				remplissage(tab, 6, 6, size);
				std::cout << "feeetyjrkt"<< std::endl;
				test = true;
			}

			j = j+1;
		}
		j = 0;
		i = i+1;
	}
}*/

/*void remplissage(int ** tab, int x, int y, int size){
	if(tab[x][y] == 0){
		tab[x][y] = 1;
		if(x-1 >= 0){
			remplissage(tab, x-1, y, size);
		}
		if(y-1 >= 0)
		{
			remplissage(tab, x, y-1, size);
		}
		if(x+1 < size)
		{
			remplissage(tab, x+1, y, size);
		}
		if(y+1 < size)
		{
			remplissage(tab, x, y+1, size);
		}
	}
}*/

void outline(int ** tab, int size, int c, int k){
	for(int i = 1; i < size-1; i = i+1){
		for(int j = 1; j < size-1; j = j+1){
			if(tab[i][j] == 0){
				if(tab[i+1][j] == c || tab[i-1][j] == c || tab[i][j+1] == c || tab[i][j-1] == c){
					tab[i][j] = k;
				}
			}
		}
	}
}
