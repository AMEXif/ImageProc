#define STB_IMAGE_IMPLEMENTATION
#define STB_IMGAE_WRITE_IMPLEMENTATION
#include <iostream>
#include "Image.h"
#include "stb_image.h"
#include "stb_image_write.h"



Image::Image(const char* filename)
{
	if (read(filename))
	{
		std::cout << "[Rei] Read " << filename << std::endl;
	}
	else
	{
		std::cout << "[Rei error] Failed to read " << filename << std::endl;
	}
}

Image::Image(int width, int height, int channels)
{

}

Image::Image(const Image& img) 
{

}

Image::~Image() 
{
	stbi_image_free(data);
}

bool Image::read(const char* filename) 
{
	data = stbi_load(filename, &width, &height, &channels, 0);

	return data != NULL;
}

bool Image::write(const char* filename)
{
	return 0;
}