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
#include <png.h>
#include <stdio.h> 
#include <stdlib.h> 
#include "Bezier.h"


/**
 * \enum Type
 * \brief Type de lettre
 **/
enum Type{
	Plain, /*lettre normale, sans contour rouge ni remplissage*/
	//Filled, /*lettre avec remplissage*/
	Outline, /*lettre avec contour rouge*/
};

/**
 * \class Lettre
 * \brief Classe représentant les lettres
 * Classe pour définir des lettres
 * On construit des lettres en utilisant des points de courbes de Bézier pour leur contour.
 * Chaque lettre est formée par un tableau de points de taille 50*50.
 **/
class Lettre{
	
	private:
		
		std::string _nom; /*Nom de la lettre*/
		Type _type; /*Type de lettre*/
		Bezier _courbes; /*Objet Bezier contenant les courbes qui forment la lettre*/
		int ** _points; /*Tableau d'entiers qui valent 1 si le point appartient à une des courbes et 0 sinon*/

	public:

		/**
		 * \brief Constructeur de base
		 * \param nom Le nom de la lettre
		 * \param type Le type de lettre
		 * \param courbes Les courbes qui définissent le contour de la lettre
		 **/
		Lettre(std::string nom, Type type, const Bezier & courbes);

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
		void get_points(int points[50][50]) const;

		/**
		 * \brief Destructeur de la classe Lettre
		 **/
		~Lettre(){
			for(int i = 0; i < 50; i = i+1){
				delete _points[i];
			}

			delete[] _points;
		}

		void dessiner(const char * nom_fichier);

};

/**
 * \fn operator<<std::ostream & st, const Lettre & l)
 * \brief Surcharge de l'opérateur << pour l'affichage
 * \param st Flux dans lequel on veut afficher les points de la lettre
 * \param l La lettre qu'on veut afficher
 * \return Un flux qui contient les points à afficher
 **/
std::ostream & operator<<(std::ostream & st, const Lettre & l);

/**
 * \fn void outline(int ** tab, int size, int c, int k)
 * \brief Fonction pour calculer le contour autour de la lettre
 * \param tab Tableau de 0, 1 et 2
 * \param size Taille du tableau
 * \param c Le numéro qui représente le bord de la lettre
 * \param k Le numéro qui représente le contour
 **/
void outline(int ** tab, int size, int c, int k);

/**
 * \fn void setPixel(png_byte *ptr, int val)
 * \brief Fonction qui permet d'écrire un pixel selon la valeur passée en paramètre
 * \param ptr Le pointeur du pixel où l'on veut écrire
 * \param val La valeur dont va dépendre l'écriture du pixel
 **/
void setPixel(png_byte *ptr, int val);







#endif