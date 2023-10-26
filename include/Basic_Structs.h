#ifndef BASIC_STRUCTS_H
#define BASIC_STRUCTS_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>


typedef struct 
{
    size_t width;
    size_t height;
    size_t size;
    Uint32* Pixels;
    Uint8* GreyPixels;
}Image;

Image* NewImage();
Image* ToImage(SDL_Surface* surface);
void FreeImage(Image* image);
void WriteFile(void* data, size_t size, size_t count, FILE* file);

#endif /* ! BASIC_STRUCTS_H */
