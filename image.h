#ifndef IMAGE_H_
#define IMAGE_H_

typedef struct Image
{
	int height;
	int width;
	int *px;
} Image;

void skip_comment(File *f);
Image * alloc_image( int height, int width);

#endif