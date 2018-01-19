#ifndef _POLICE_H_
#define _POLICE_H_

/**
 * \file Police.h
 * \brief Définition de la classe Police
 * \author Anthea, Amina
 * \date 19/01/2018
 **/

#include <iostream>
#include <vector>
#include "Lettre.h"


/**
 * \class Police
 * \brief Classe représentant es polices
 * Classe pour définir des polices
 * Une police contient un tableau de lettres
 **/
class Police{

	private:

		Type _type;
		std::vector<Lettre> _lettres;

	public:

		Police(Type t = Plain);

		std::vector<Lettre> get_lettres() const;

};

Lettre A(Type t);

Lettre C(Type t);

/**
 * \fn operator<<std::ostream & st, const Police & p)
 * \brief Surcharge de l'opérateur << pour l'affichage
 * \param st Flux dans lequel on veut afficher les points de la lettre
 * \param p La police dont on veut afficher les lettres
 * \return Un flux qui contient les points à afficher
 **/
std::ostream & operator<<(std::ostream & st, const Police & p);

	









#endif