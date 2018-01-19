/**
 * \file main.cpp
 * \brief Fichier contenant la fonction main
 * \author Anthea, Amina
 * \date 19/01/2018
 **/


#include "Bezier.h"
#include "Lettre.h"
#include "Police.h"


int main(int arc, char ** argv){
	std::cout << " " << std::endl;


	Police p_plain;

	Police p_outline(Outline);

	//std::cout << p << std::endl;

	p_plain.dessiner();

	p_outline.dessiner();

	return 0;
}