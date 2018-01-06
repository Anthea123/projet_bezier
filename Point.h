#ifndef _POINT_H_
#define _POINT_H_

/**
 * \file Point.h
 * \brief Définition de la classe Point
 * \author Anthea, Amina
 * \date 06/01/2018
 **/

#include <iostream>

/**
 * \class Point
 * \brief Classe représentant des points dans un plan
 * 
 * On considère que les points sont répartis dans une grille de taille $100 \times 100$,
 * et cette classe permet de définir des points sur cette grille avec leurs coordonnées x
 * et y.
 * 
 **/
class Point{

	private:
		
		int _x; /*coordonnée sur l'axe des abscisses*/
		int _y; /*coordonnée sur l'axe des ordonnées*/

	public:
		/**
		 * \brief Constructeur
		 * \param x Coordonnée en abscisse
		 * \param y Coordonnée en ordonnée 
		 **/
		Point(int x, int y);

		/**
		 * \brief Constructeur de copie
		 * \param p Point à copier
		 **/
		Point(const Point & p);

		/**
		 * \brief Acceseur pour la coordonnée en abscisse
		 * \return La coordonnée en abscisse
		 **/
		int get_x() const;

		/**
		 * \brief Acceseur pour la coordonnée en ordonnée
		 * \return La coordonnée en ordonnée
		 **/
		int get_y() const;

		/**
		 * \brief Setter pour la coordonée en abscisse
		 * \param new_x La nouvelle coordonée
		 **/
		void set_x(int new_x);
		
		/**
		 * \brief Setter pour la coordonée en ordonnée
		 * \param new_y La nouvelle coordonée
		 **/
		void set_y(int new_y);



};

/**
 * \fn operator<<std::ostream & st, const Point & p)
 * \brief Surcharge de l'opérateur << pour l'affichage
 * \param st Flux dans lequel on veut afficher le point
 * \param p Le point qu'on veut afficher
 * \return Un flux qui contient le point à afficher
 **/
std::ostream & operator<<(std::ostream & st, const Point & p);


#endif