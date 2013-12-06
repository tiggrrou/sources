#include "include.h"

void main()
{
	int nb_point = 100;
	int i = 0;
	Liste * liste = create_square();
	liste = add_rand_point(nb_point);
	
	for (i = 0; i < (nb_point +4); i++)
	{
		printf("%d %d %d\n",liste->l_Tp->coord[0],liste->l_Tp->coord[1],liste->l_Tp->coord[2]);
		liste = liste->next;
	}
}