#ifndef POINTS_H_
#define POINTS_H_

#include "include.h"

// nombre de dims d'un Tpoint
#define DIM 3

#define X 0
#define Y 1
#define Z 2

#define GAUCHE	0
#define DROITE	1
#define ALIGNE	2

//Structure d'un Tpoint
typedef struct Tpoint
{
	double coord[DIM];
	
} Tpoint;

//Liste de Tpoints
typedef struct Liste
{
	struct Tpoint 	* l_Tp;
	struct Liste 	* next;
} Liste;

// GENERATION DES SOMMETS

	Tpoint* init_sommet(double x, double y, double z);
	void free_sommet(Tpoint* point);
	Tpoint* genere_sommet();

// LISTE

	Liste* init_Liste(Tpoint * point);
	void add_to_Liste(Liste * liste, Tpoint * point);
	void erase_element(Liste * element, Liste * elt_previous);
	void free_liste(Liste * liste);

// CALCULS
	
	int puissance(Tpoint * pA, Tpoint * pB, Tpoint * pC);

#endif