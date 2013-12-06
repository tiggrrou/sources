#ifndef IMAGE_H_
#define IMAGE_H_

#include "include.h"

typedef struct Image
{
	int height;
	int width;
	int **px;
} Image;

void skip_comment(FILE* f);
Image * alloc_image( int height, int width);
Image * load_image(const char * f_name);


#endif