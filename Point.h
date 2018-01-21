#ifndef _POINT_H_
#define _POINT_H_

/**
 * \file Point.h
 * \brief Définition de la classe Point
 * \author Anthea Mérida, Amina Zhegida
 * \date 06/01/2018
 **/

#include <iostream>

/**
 * \class Point
 * \brief Classe représentant des points dans un plan
 * 
 * On considère que les points sont répartis dans une grille de taille $50 \times 50$,
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
		 * \brief Constructeur par défaut
		 * \param x Coordonnée en abscisse
		 * \param y Coordonnée en ordonnée 
		 **/
		Point();

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

};

/**
 * \fn bool operator==(Point const & p1, Point const & p2)
 * \brief Surcharge de l'opérateur == pour tester l'égalité de deux points
 * \param p1 Point
 * \param p2 Point
 * \return true si les points ont les mêmes coordonnées
 * 	false sinon
 **/
bool operator==(Point const & p1, Point const & p2);

/**
 * \fn bool operator!=(Point const & p1, Point const & p2)
 * \brief Surcharge de l'opérateur != pour tester la différence entre deux points
 * \param p1 Point
 * \param p2 Point
 * \return true si les points ont des coordonnées différentes
 * 	false sinon
 **/
bool operator!=(Point const & p1, Point const & p2);

/**
 * \fn std::ostream & operator<<std::ostream & st, const Point & p)
 * \brief Surcharge de l'opérateur << pour l'affichage
 * \param st Flux dans lequel on veut afficher le point
 * \param p Le point qu'on veut afficher
 * \return Un flux qui contient le point à afficher
 **/
std::ostream & operator<<(std::ostream & st, const Point & p);

/**
 * \fn Point barycentre(double t, Point const & p1, Point const & p2)
 * \brief Calcul du barycentre de deux points
 * \param t Le paramètre du barycentre
 * \param p1 Point 
 * \param p2 Point
 * \return Le barycentre de paramètre t des points p1 et p2
 **/
Point barycentre(double t, Point const & p1, Point const & p2);

#endif