#include "image.h"


// nous avons besoin de diverses fonctions traitant les images pour, 
// entre autres, récupérer les valeurs d'altitude servant à
// initialiser le Z de nos Tpoint 
// les fichiers à lire sont du P5 (pgm)


// dans le format pgm les lignes commençant par # sont des commentaires 
void skip_comment(FILE *f)
{
	char c = getc(f);
	
	switch (c) 
		{
	case '#':
			while (getc(f) != '\n') {}
			skip_comment(f);
			break;
		case '\n':
			skip_comment(f);
			break;
		default:
			ungetc(c, f);
			break;
		}
}

// allocation de la structure image
Image *	alloc_image( int height, int width)
{
	Image* img 	= (Image*)(malloc(sizeof(Image)));
	img->height = height;
	img->width 	= width;
	img->px 	= (int *)(malloc(sizeof(int)* height * width) );

	return img;
}

// libération de la structure image
void	free_image(Image * im)
{
	free(im->px);
	free(im);
}

// chargement d'une image
Image * load_image(const char * f_name)
{
	int i, j;
	int height, width;
	FILE * f = fopen(f_name,"r"); 
	skip_comment(f);

	sscanf(f_name,"%d%d",&width, &height);

	skip_comment(f);

	Image* img = alloc_image(height, width);

	for(i = height-1; i >= 0; i--)
    {
        for(j = 0; j < width; j++)
        {
            fscanf(f, "%d", &(img->px[i][j])) ;
        }
    }

    return img ;
}