#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>
#include "common.hpp"

int main()
{
    unsigned char* img;
    int width, height, bpp;
    img = stbi_load(TEXTURE_PATH, &width, &height, &bpp, 4);
    printf("%d %d %d\n", width, height, bpp);
}