#include "maillage.h"
#include "points.h"

Liste * create_square()
{
// creation des quatre coins
// H = hight
// D = down
// L = left
// R = right
	// Z encore à gérer
	Tpoint * p_DL = init_sommet(0,0,0);
	Tpoint * p_DR = init_sommet(1,0,0);
	Tpoint * p_HR = init_sommet(1,1,0);
	Tpoint * p_HL = init_sommet(0,1,0);

Liste * liste = NULL;

//placement des points dans l'ordre trigo

	add_to_Liste(liste, p_HL);
	add_to_Liste(liste, p_HR);
	add_to_Liste(liste, p_DR);
	add_to_Liste(liste, p_DL);

return liste;
}

Liste * add_rand_point(int nb_points)
{
	Liste * liste = NULL;
	// pour générer un nuage différent a chaque fois
	
	int i = 0;
	srand(time(NULL));

	while (i < nb_points)
	{
		Tpoint * point = genere_sommet();
		add_to_Liste(liste, point);
		i++;
	}
return liste;
}
