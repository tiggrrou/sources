#include "image.h"


// nous avons besoin de diverses fonctions traitant les images pour, 
// entre autres, récupérer les valeurs d'altitude servant à
// initialiser le Z de nos Tpoint 
// les fichiers à lire sont du P5 (pgm)


// dans le format pgm les lignes commençant par # sont des commentaires 
void skip_comment(File *f)
{
	char c = getc(f);
	
	switch (c) 
		{
		case '#'
			while (getc(file) != '\n') {}
			skip_comment(f);
			break;
		case '\n':
			skip_comment(f);
			break;
		default:
			ungetc(c, file);
			break;
		}
}

// allocation de la structure image
Image 	alloc_image( int height, int width)
{
	Image* img 	= (Image*)malloc(sizeof(Image));
	img->height = height;
	img->width 	= width;
	img->px 	= (int *)(malloc(sizeof(int)) * height * width);
}

// libération de la structure image
void	free_image(Image * im)
{
	free(im->px);
	free(im);
}
