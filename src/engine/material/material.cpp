#include <iostream>
#include <SDL.h>

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glu.h>

#include "material.hpp"

void surfaceToGlTexture(GLuint& glTexture, SDL_Surface* surface) {
    // Check that the image's width is a power of 2
    if ((surface->w & (surface->w - 1)) != 0) {
        std::cout << "warning: surface width is not a power of 2\n"
                  << std::endl;
    }

    // Also check if the height is a power of 2
    if ((surface->h & (surface->h - 1)) != 0) {
        std::cout << "warning: surface height is not a power of 2\n"
                  << std::endl;
    }

    SDL_Surface* rgbSurface =
        SDL_CreateRGBSurface(0, surface->w, surface->h,
                             8 * 4,  // force RGBA
                             surface->format->Rmask, surface->format->Gmask,
                             surface->format->Bmask, surface->format->Amask);
    if (rgbSurface == NULL) {
        std::cout << SDL_GetError() << std::endl;
    }
    std::cout << rgbSurface << std::endl;
    SDL_BlitSurface(surface, NULL, rgbSurface, NULL);

    int ncolors = rgbSurface->format->BytesPerPixel;
    std::cout << "colors: " << ncolors << std::endl;
    int texture_format;
    if (ncolors == 4) {
        // has alpha
        if (rgbSurface->format->Rmask == 0x000000ff)
            texture_format = GL_RGBA;
        else
            texture_format = GL_BGRA;
    }

    else if (ncolors == 3) {
        // no alpha
        if (rgbSurface->format->Rmask == 0x000000ff)
            texture_format = GL_RGB;
        else
            texture_format = GL_BGR;
    }

    else {
        std::cout << "warning: surface not truecolor, this will probably break"
                  << std::endl;
    }

    glBindTexture(GL_TEXTURE_2D, glTexture);

    /*
    std::cout << rgbSurface->w << "x" << rgbSurface->h << std::endl;
    for (int x=0; x<rgbSurface->w; x++) {
        for (int y=0; y<rgbSurface->h; y++) {
            size_t pixelIndex = (x + y * rgbSurface->w);
            uint8_t * pixel = ((uint8_t *) rgbSurface->pixels) + (4 *
pixelIndex);
            float xFrac = (float) x / (float) rgbSurface->w;
            float yFrac = (float) y / (float) rgbSurface->h;
            pixel[0] = (uint8_t) (xFrac * 255);
            pixel[1] = (uint8_t) (yFrac * 255);
            pixel[2] = 0;
            pixel[3] = 255;
//            std::cout << +((uint8_t *) rgbSurface->pixels)[i * 3 + 0] << ", ";
//            std::cout << +((uint8_t *) rgbSurface->pixels)[i * 3 + 1] << ", ";
//            std::cout << +((uint8_t *) rgbSurface->pixels)[i * 3 + 2] <<
std::endl;
        }
    }
    */

    SDL_SaveBMP(rgbSurface, "surface.bmp");

    glTexImage2D(GL_TEXTURE_2D, 0,
                 GL_RGBA,  // rgb surface
                 rgbSurface->w, rgbSurface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 rgbSurface->pixels);
    int glerror = glGetError();
    if (glerror != 0)
        std::cout << "error in glTexImage2D" << glerror << " @ " __FILE__ << ":"
                  << __LINE__ << std::endl;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_FreeSurface(rgbSurface);
}

void Material::setAmbientTexture(SDL_Texture* texture) {
    ambientTexture = texture;
}

bool Material::hasTexture() {
    return ambientTexture != NULL;
}
