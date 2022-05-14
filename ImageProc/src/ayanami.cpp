#include <iostream>
#include "Image.h"

int main()
{
    Image image("res/images/nier.jpg");

    Image gray_avg = image;
    gray_avg.grayscale_avg();
    gray_avg.write("gray_avg.jpg");

    Image gray_lum = image;
    gray_lum.grayscale_lum();
    gray_lum.write("gray_lum.jpg");

    std::cin;
    std::cout << "[Rei] Exiting..." << std::endl;
}
