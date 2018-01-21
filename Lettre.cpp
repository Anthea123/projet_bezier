/**
 * \file Lettre.cpp
 * \brief Impémentation de la classe Lettre
 * \author Anthea Mérida, Amina Zhegida
 * \date 17/01/2018
 **/

#include "Lettre.h"


/*Constructeurs*/
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

/*Accesseurs*/
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

/*opérateur de flux*/
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

/*fonction ajoutant un contour de valeur k autour des 
points de valeur c*/
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

/*fonction qui gère l'écriture d'un fichier .png contenant
les informations contenues dans _points*/
void Lettre::dessiner(const char * nom_fichier){
	
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_bytep row = NULL;

	char * title = (char *) nom_fichier;

	// Open file for writing (binary mode)
	FILE *fp = fopen(nom_fichier, "wb");
	if (fp == NULL) {
		throw "Fichier non ouvert\n";
	}

	// Initialize write structure
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		throw "Could not allocate write struct\n";
	}

	// Initialize info structure
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		throw "Could not allocate info struct\n";
	}

	// Setup Exception handling
	if (setjmp(png_jmpbuf(png_ptr))) {
		throw "Error during png creation\n";
	}

	png_init_io(png_ptr, fp);

	// Write header (8 bit colour depth)
	png_set_IHDR(png_ptr, info_ptr, 50, 50,
			8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	// Set title
	png_text title_text;
	title_text.compression = PNG_TEXT_COMPRESSION_NONE;
	title_text.key = "Title";
	title_text.text = title;
	png_set_text(png_ptr, info_ptr, &title_text, 1);

	png_write_info(png_ptr, info_ptr);

	// Allocate memory for one row (3 bytes per pixel - RGB)
	row = (png_bytep) malloc(3 * 50 * sizeof(png_byte));

	// Write image data
	for (int i = 0 ; i < 50 ; i = i+1) {
		for (int j = 0 ; j < 50 ; j = j+1) {
			setPixel(&(row[j*3]), _points[i][j]);
		}
		png_write_row(png_ptr, row);
	}

	// End write
	png_write_end(png_ptr, NULL);

	if (fp != NULL) fclose(fp);
	if (info_ptr != NULL) png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
	if (png_ptr != NULL) png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
	if (row != NULL) free(row);	

}

/*fonction qui détermine la couleur des pixels selon la valeur
de val*/
void setPixel(png_byte *ptr, int val){

	if(val != 0 && val != 1 && val != 2 && val != 3){
		throw "Mauvaise valeur";
	}
	
	if (val == 0) {
		ptr[0] = 255; ptr[1] = 255; ptr[2] = 255;
	}
	
	if (val == 1) {
		ptr[0] = 0; ptr[1] = 0; ptr[2] = 0;
	}
	
	if (val == 2 || val == 3){
		ptr[0] = 255; ptr[1] = 0; ptr[2] = 0;
	}
}
