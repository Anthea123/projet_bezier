/**
 * \file Police.cpp
 * \brief Impémentation de la classe Police
 * \author Anthea, Amina
 * \date 19/01/2018
 **/

#include "Police.h"

/*fonction pour créer une lettre A de type t*/
Lettre A(Type t){
	Bezier b1 = Bezier(Point(5, 5), Point(8*2.5, 18*2.5));
	Bezier b2 = Bezier(Point(8*2.5, 18*2.5), Point(12*2.5, 18*2.5));
	Bezier b3 = Bezier(Point(12*2.5, 18*2.5), Point(18*2.5, 2*2.5));
	Bezier b4 = Bezier(Point(18*2.5, 2*2.5), Point(14*2.5, 2*2.5));
	Bezier b5 = Bezier(Point(14*2.5, 2*2.5), Point(12*2.5, 6*2.5));
	Bezier b6 = Bezier(Point(12*2.5, 6*2.5), Point(8*2.5, 6*2.5));
	Bezier b7 = Bezier(Point(8*2.5, 6*2.5), Point(6*2.5, 2*2.5));
	Bezier b8 = Bezier(Point(6*2.5, 2*2.5), Point(2*2.5, 2*2.5));
	Bezier b9 = Bezier(Point(8*2.5, 8*2.5), Point(10*2.5, 14*2.5));
	Bezier b10 = Bezier(Point(10*2.5, 14*2.5), Point(12*2.5, 8*2.5));
	Bezier b11 = Bezier(Point(12*2.5, 8*2.5), Point(8*2.5, 8*2.5));

	Bezier contour = join(b1, b2); 
	contour  = join(contour, b3);
	contour  = join(contour, b4);
	contour  = join(contour, b5);
	contour  = join(contour, b6);	
	contour  = join(contour, b7);
	contour  = join(contour, b8);
	contour  = join(contour, b9);
	contour  = join(contour, b10);
	contour  = join(contour, b11);
	

	Lettre A("A", t, contour);

	return A;
}

/*fonction pour créer une lettre C de type t*/
Lettre C(Type t){
	Bezier b1 = Bezier(Point(40, 35), Point(40, 43));
	Bezier b2 = Bezier(Point(40, 43), Point(22, 46), Point(17, 35));
	Bezier b3 = Bezier(Point(17, 35), Point(16, 31), Point(16, 25));
	Bezier b4 = Bezier(Point(16, 25), Point(16, 19), Point(17, 15));
	Bezier b5 = Bezier(Point(17, 15), Point(22, 4), Point(40, 7));
	Bezier b6 = Bezier(Point(40, 7), Point(40, 15));
	Bezier b7 = Bezier(Point(40, 15), Point(32, 10), Point(25, 15));
	Bezier b8 = Bezier(Point(25, 15), Point(22, 18), Point(22, 25));
	Bezier b9 = Bezier(Point(22, 25), Point(22, 32), Point(25, 35));
	Bezier b10 = Bezier(Point(25, 35), Point(32, 40), Point(40, 35));

	Bezier contour = join(b1, b2); 
	contour  = join(contour, b3);
	contour  = join(contour, b4);
	contour  = join(contour, b5);
	contour  = join(contour, b6);	
	contour  = join(contour, b7);
	contour  = join(contour, b8);
	contour  = join(contour, b9);
	contour  = join(contour, b10);
	

	Lettre C("C", t, contour);

	return C;
}

/*Constructeur*/
Police::Police(Type t){
	_type = t;
	_lettres = std::vector<Lettre>();

	_lettres.push_back(A(t));
	_lettres.push_back(C(t));
}

/*Accesseur*/
std::vector<Lettre> Police::get_lettres() const{
	return _lettres;
}

/*opérateur de flux*/
std::ostream & operator<<(std::ostream & st, const Police & p){
	for(int i = 0; i < p.get_lettres().size(); i = i+1){
		st << p.get_lettres()[i].get_nom() << std::endl;
		st << p.get_lettres()[i] << std::endl;
	}

	return st;
}

/*fonction qui appelle la méthode dessiner de chache lettre*/
void Police::dessiner(){
	for(int i = 0; i < _lettres.size(); i = i+1){
		std::string tmp = _lettres[i].get_nom();
		
		if(_type == Plain){
			tmp = tmp+"_plain";
		}
		
		if(_type == Outline){
			tmp = tmp+"_outline";
		}

		tmp = tmp+".png";

		const char * nom_fichier = tmp.c_str();

		_lettres[i].dessiner(nom_fichier);
	}	
}
