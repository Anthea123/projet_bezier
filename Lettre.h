#ifndef _LETTRE_H_
#define _LETTRE_H_

/**
 * \file Lettre.h
 * \brief Définition de la classe Lettre
 * \author Anthea, Amina
 * \date 17/01/2018
 **/

#include <iostream>
#include <vector>
#include "Bezier.h"


/**
 * \class Lettre
 * \brief Classe représentant les lettres
 * Classe pour définir des lettres
 * On construit des lettres en utilisant des points de courbes de Bézier pour leur contour.
 * Chaque lettre est formée par un tableau de points de taille 100*100.
 **/
class Lettre{
	
	private:
		
		std::string _nom; /*Nom de la lettre*/
		//static const std::string type;
		Bezier _courbes; /*Objet Bezier contenant les courbes qui forment la lettre*/
		int ** _points; /*Tableau d'entiers qui valent 1 si le point appartient à une des courbes et 0 sinon*/

	public:

		/**
		 * \brief Constructeur de base
		 * \param nom Le nom de la lettre
		 * \param courbes Les courbes qui définissent le contour de la lettre
		 **/
		Lettre(std::string nom, const Bezier & courbes);

		/**
		 * \brief Constructeur de copie
		 * \param l lettre à copier
		 **/
		Lettre(const Lettre & l);

		/**
		 * \brief Acceseur pour le nom de la lettre
		 * \return Le nom de la lettre
		 **/
		std::string get_nom() const;

		/**
		 * \brief Acceseur pour les courbes de Bézier de la lettre
		 * \return Les courbes de Bézier de la lettre
		 **/
		Bezier  get_courbes() const;

		/**
		 * \brief Acceseur pour les points de la lettre
		 * \param points le tableau où stocker les points de la lettre
		 **/
		void get_points(int points[100][100]) const;

};

/**
 * \fn operator<<std::ostream & st, const Lettre & l)
 * \brief Surcharge de l'opérateur << pour l'affichage
 * \param st Flux dans lequel on veut afficher les points de la lettre
 * \param b La courbe dont on veut afficher les points
 * \return Un flux qui contient les points à afficher
 **/
std::ostream & operator<<(std::ostream & st, const Lettre & l);










#endif