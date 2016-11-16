#include "Image.h"


Image::Image(void)
{
}


Image::~Image(void)
{
}

int Image::GetWidth()
{
	return surf->w;
}

int Image::GetHeight()
{
	return surf->h;
}