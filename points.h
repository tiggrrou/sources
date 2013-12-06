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

//Structure pour contenir les triangles
typedef struct Simplex
{
	struct  Tpoint*		xyz[3];
	struct	Simplex *	neighbors[3];
} Simplex;

//structure Pile de triangles
typedef struct Pile
{
	struct Simplex *	triangle;
	struct Pile *		next;
} Pile;

// GENERATION DES SOMMETS

	Tpoint* init_sommet(double x, double y, double z);
	void free_sommet(Tpoint* point);
	Tpoint* genere_sommet(Image * image);
	double genere_altitude(Image * i, double x, double y );

// LISTE

	Liste* init_Liste(Tpoint * point);
	void add_to_Liste(Liste * liste, Tpoint * point);
	void erase_element(Liste * element, Liste * elt_previous);
	void free_liste(Liste * liste);

// CALCULS
	
	int puissance(Tpoint * pA, Tpoint * pB, Tpoint * pC);

#endif