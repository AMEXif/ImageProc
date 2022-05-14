#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <iostream>
#include "Image.h"
#include "stb_image.h"
#include "stb_image_write.h"



Image::Image(const char* filename)
{
	if (read(filename))
	{
		std::cout << "[Rei] Read " << filename << std::endl;
		size = width * height * channels;
	}
	else
	{
		std::cout << "[Rei error] Failed to read " << filename << std::endl;
	}
}

Image::Image(int width, int height, int channels) : width(width), height(height), channels(channels)
{
	size = width * height * channels;
	data = new uint8_t[size];
}

Image::Image(const Image& img) : Image(img.width, img.height, img.channels)
{
	memcpy(data, img.data, size);
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
	ImageType type = getImageType(filename);

	int success;
	switch (type)
	{
		case PNG:
			success = stbi_write_png(filename, width, height, channels, data, width * channels);
			break;
		case JPG:
			success = stbi_write_jpg(filename, width, height, channels, data, 100);
			break;
		case TGA:
			success = stbi_write_tga(filename, width, height, channels, data);
			break;
		case BMP:
			success = stbi_write_bmp(filename, width, height, channels, data);
			break;
	}

	return success != 0;
}

ImageType Image::getImageType(const char* filename)
{
	const char* ext = strrchr(filename, '.');

	if (ext != nullptr) {

		if (strcmp(ext, ".png") == 0) {
			return PNG;
		}
		else if (strcmp(ext, ".jpg") == 0) {
			return JPG;
		}
		else if (strcmp(ext, ".tga") == 0) {
			return TGA;
		}
		else if (strcmp(ext, ".bmp") == 0) {
			return BMP;
		}
	}
	return PNG;

}