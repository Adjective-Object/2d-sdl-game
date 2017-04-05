#include <iostream>
#include <SDL.h>

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glu.h>

#include "material.hpp"

void surfaceToGlTexture(GLuint & glTexture, SDL_Surface * surface) {

   // Check that the image's width is a power of 2
    if( (surface->w & (surface->w - 1)) != 0 )
    {
        std::cout << "warning: surface width is not a power of 2\n" << std::endl;
    }

    // Also check if the height is a power of 2
    if( (surface->h & (surface->h - 1)) != 0 )
    {
        std::cout << "warning: surface height is not a power of 2\n" << std::endl;
    }

    SDL_Surface * rgbSurface = SDL_CreateRGBSurface(
            0,
            surface->w,
            surface->h,
            surface->format->BitsPerPixel,
            surface->format->Rmask,
            surface->format->Gmask,
            surface->format->Bmask,
            surface->format->Amask
            );
    if (rgbSurface == NULL) {
        std::cout << SDL_GetError() << std::endl;
    }
    std::cout << rgbSurface << std::endl;
    SDL_BlitSurface(surface, NULL, rgbSurface, NULL);

    int ncolors = surface->format->BytesPerPixel;
    int texture_format;
    if( ncolors == 4 ) {
		// has alpha
        if(rgbSurface->format->Rmask == 0x000000ff)
            texture_format = GL_RGBA;
        else
            texture_format = GL_BGRA;
    }

    else if( ncolors == 3 ) {
		// no alpha
        if(rgbSurface->format->Rmask == 0x000000ff)
            texture_format = GL_RGB;
        else
            texture_format = GL_BGR;
    }

    else {
        std::cout << "warning: surface not truecolor, this will probably break"
            << std::endl;
    }

    glBindTexture(GL_TEXTURE_2D, glTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(
            GL_TEXTURE_2D,
            0,
            ncolors,
            rgbSurface->w,
            rgbSurface->h,
            0,
            texture_format,
            GL_UNSIGNED_BYTE,
            rgbSurface->pixels
            );
    int glerror = glGetError();
    if( glerror != 0 )
        std::cout << "error in glTexImage2D" << glerror
                  << " @ " __FILE__ << ":" <<  __LINE__ << std::endl;

    SDL_FreeSurface(rgbSurface);
}

void Material::setAmbientTexture(SDL_Surface * texture) {
    ambientTexture = texture;
    if (glAmbientTexture == 0) {
        glGenTextures(1, &glAmbientTexture);
    }
    surfaceToGlTexture(glAmbientTexture, texture);
}

bool Material::hasTexture() {
    return glAmbientTexture != 0;
}
