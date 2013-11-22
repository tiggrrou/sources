#include "points.h"


/////////////////////////////////////////////////
//             GENERATION DES SOMMETS          //
/////////////////////////////////////////////////
Tpoint* init_sommet(double x, double y, double z)
{
	Tpoint * point = (Tpoint *) malloc(sizeof(Tpoint));
	point->coord[X] = x; 
	point->coord[Y] = y;
	point->coord[Z] = z;

	return point;
}

void free_sommet(Tpoint* point)
{
	if(point != NULL)
		{
		free(point);
		}
}

Tpoint* genere_sommet()
{
	double x = rand()/ (double) RAND_MAX; 	// la division par rand_max ramene le nombre entre 0 et 1
	double y = rand()/ (double) RAND_MAX;
	// on évite que les valeurs générées soient sur les bords de la map
	if(x == 0)
		x = 0.00001;
	if(x == 1)
		x = 0.99999;
	if(y == 0)
		x = 0.00001;
	if(y == 1)
		x = 0.99999;
	// reste à générer le point d'altitude
	return init_sommet(x, y, 0.); 
	
}

// liste


// initialisation d'une liste avec un élément
Liste* init_Liste(Tpoint * point)
{
	Liste * l = (Liste *) malloc(sizeof(Liste));
	l->l_Tp = point;
	l->next = NULL;
	
	return l;
}

//ajout d'un elt à la tete d'une liste existante
void add_to_Liste(Liste * liste, Tpoint * point)
{
	Liste* l_tmp = init_Liste(point);
	l_tmp->next = liste;
	liste = l_tmp;
}

//supprime l'element passé en parametre de la liste
void erase_element(Liste * element, Liste * elt_previous)
{
	if(element != NULL)
	{
		if(elt_previous != NULL)
			elt_previous->next = element->next;
		free(element);
	}		
}

//libère la mémoire attribuée aux points
void free_liste(Liste * liste)
{
	Liste * l_tmp = liste;
	Liste * next_point;
	while(l_tmp != NULL)
	{
		next_point = l_tmp->next;
		free(l_tmp);
		l_tmp = next_point;
	}
}


// calculs

int puissance(Tpoint * pA, Tpoint * pB, Tpoint * pC)
{
	double puissance = 	( pB->coord[X] - pA->coord[X]) * 
						( pC->coord[Y] - pA->coord[Y]) -
						( pC->coord[X] - pA->coord[X]) * 
						( pB->coord[Y] - pA->coord[Y]);
 	if		(puissance < 0)
		return DROITE;
	else if (puissance > 0)
		return GAUCHE;
	else //  puissance == 0
		return ALIGNE;		
}
