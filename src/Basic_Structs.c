#include "../include/Basic_Structs.h"

static inline Uint8* Greyscale(SDL_Surface *surface)
{
	Uint8* GreyPixels = malloc(surface->w * surface->h * sizeof(Uint8));
    SDL_LockSurface(surface);
    Uint32* Pixels = (Uint32*)surface->pixels;
    for (size_t i = 0; i < surface->w * surface->h; i++)
    {
        Uint8 r, g, b;
        SDL_GetRGB(Pixels[i], surface->format, &r, &g, &b);
        GreyPixels[i] = 0.2126*r + 0.7152*g + 0.0722*b;
    }
    SDL_UnlockSurface(surface);
    return GreyPixels;
}


Image* NewImage()
{
	Image* image = malloc(sizeof(Image));
	image->width = 0;
	image->height = 0;
	image->size = 0;
	image->Pixels = NULL;
	image->GreyPixels = NULL;
	return image;
}

Image* ToImage(SDL_Surface* surface)
{
	Image* image = NewImage();
	image->width = surface->w;
	image->height = surface->h;
	image->size = image->width * image->height;
	SDL_LockSurface(surface);

	Uint32* PreviousPix = (Uint32*)surface->pixels;
	image->Pixels = (Uint32*)malloc(image->size * sizeof(Uint32));
	memcpy(image->Pixels, PreviousPix, image->size * sizeof(Uint32));
	image->GreyPixels = Greyscale(surface);
	SDL_UnlockSurface(surface);
	return image;
}

void FreeImage(Image* image)
{
	free(image->Pixels);
	free(image->GreyPixels);
	free(image);
}

void WriteFile(void* data, size_t size, size_t count, FILE* file)
{
	fwrite(data, size, count, file);
}
