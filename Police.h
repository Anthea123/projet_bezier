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

		Type _type;/*type de lettre*/

		std::vector<Lettre> _lettres; /*lettres de la police*/

	public:

		/**
		 * \brief Constructeur
		 * \param t le type de lettre dans la police
		 **/		
		Police(Type t = Plain);

		/**
		 * \brief Accesseur pour les lettres
		 * \return un vecteur contenant les lettres
		 **/
		std::vector<Lettre> get_lettres() const;

		/**
		 * \brief fonction pour créer les images png des lettres
		 **/
		void dessiner();

};

/**
 * \fn Lettre A(Type t)
 * \brief Fonction pour définir le contour de la lettre A
 * \param t Le type de lettre A qu'on veut obtenir
 * \return Une instance de lettre avec le contour de la lettre A
 **/
Lettre A(Type t);

/**
 * \fn Lettre C(Type t)
 * \brief Fonction pour définir le contour de la lettre C
 * \param t Le type de lettre C qu'on veut obtenir
 * \return Une instance de lettre avec le contour de la lettre C
 **/
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