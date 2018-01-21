#ifndef _BEZIER_H_
#define _BEZIER_H_

/**
 * \file Bezier.h
 * \brief Définition de la classe Bezier
 * \author Anthea Mérida, Amina Zhegida
 * \date 08/01/2018
 **/

#include <iostream>
#include <vector>
#include "Point.h"

/**
 * \class Bezier
 * \brief Classe représentant des points dans un plan
 * Classe pour définir des courbes de Bézier
 * On implémente l'algorithme de Casteljau pour calculer les points d'une courbe de
 * Bézier quadratique à partir de deux ou trois points de contrôle.
 **/
class Bezier{

	private:
		
		Point _P1; /*Premier point de la courbe*/
		Point _C; /*Point de contrôle*/
		Point _P2; /*Dernier point de la courbe*/

		std::vector<Point> points; /*vecteur contenant les points de la courbe*/

	public:

		/**
		 * \brief Constructeur de base
		 * \param P1 Le premier point de la courbe
		 * \param C Point de contrôle
		 * \param P2 Le dernier point de la courbe
		 **/
		Bezier(){
			_P1 = Point();
			_C = Point();
			_P2 = Point();

			points = std::vector<Point>();
		}

		/**
		 * \brief Constructeur de base
		 * \param P1 Le premier point de la courbe
		 * \param C Point de contrôle
		 * \param P2 Le dernier point de la courbe
		 **/
		Bezier(Point P1, Point C, Point P2);

		/**
		 * \brief Constructeur de base
		 * \param P1 Le premier point de la courbe
		 * \param P2 Le dernier point de la courbe
		 **/
		Bezier(Point P1, Point P2);

		/**
		 * \brief Constructeur de base
		 * \param P1 Le premier point de la courbe
		 * \param P2 Le dernier point de la courbe
		 * \param vp Les points de la courbe
		 **/
		Bezier(Point P1, Point P2, std::vector<Point> vp);


		/**
		 * \brief Constructeur de copie
		 * \param b courbe à copier
		 **/
		Bezier(const Bezier & b);

		
		/**
		 * \brief Acceseur pour la coordonnée en abscisse
		 * \return La coordonnée en abscisse
		 **/
		Point get_P1() const;

		/**
		 * \brief Acceseur pour la coordonnée en ordonnée
		 * \return La coordonnée en ordonnée
		 **/
		Point get_C() const;

		/**
		 * \brief Acceseur pour la coordonnée en abscisse
		 * \return La coordonnée en abscisse
		 **/
		Point get_P2() const;

		/**
		 * \brief Acceseur pour les points de la courbe
		 * \return Un vecteur contenant les points de la courbe
		 **/
		std::vector<Point> get_points() const;
		
};

/**
 * \fn operator<<std::ostream & st,const Bezier & b)
 * \brief Surcharge de l'opérateur << pour l'affichage
 * \param st Flux dans lequel on veut afficher le point
 * \param b La courbe dont on veut afficher les points
 * \return Un flux qui contient les points à afficher
 **/
std::ostream & operator<<(std::ostream & st, const Bezier & b);

/**
 * \fn std::vector<Point> casteljau(std::vector<Point> vp)
 * \brief Implémentation de l'algorithme de Casteljau
 * \param vp Vector contenant les points nécessaires au calcul
 * \return Un Vector contenant les points de la courbe calculée
 **/
std::vector<Point> casteljau(std::vector<Point> vp);

/**
 * \fn Bezier join(Bezier const & b1, Bezier const & b2)
 * \brief Concaténer deux courbes de Bézier
 * \param b1 Une courbe de Bézier
 * \param b2 Une autre courbe de Bézier
 * \return Une courbe de bézier contenant les points des deux courbes
 **/
Bezier join(Bezier const & b1, Bezier const & b2);

#endif