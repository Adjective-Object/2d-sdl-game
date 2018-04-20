#include <SDL.h>
#include <iostream>
#include <stdexcept>

#include "engine/texture/texture.hpp"

GLenum getFormatFromSurface(SDL_Surface* surface) {
    return (surface->format->BytesPerPixel == 4) ? (false  // TODO
                                                        ? GL_BGRA
                                                        : GL_RGBA)
                                                 : (false  // TODO
                                                        ? GL_BGR
                                                        : GL_RGB);
}

Texture::Texture(int width, int height, GLenum textureMode, const GLvoid* data)
    : width(width), height(height), textureMode(textureMode) {
    PRINT_GL_CONTEXT
    std::cout << "make texture with width " << width << std::endl;
    std::cout << "TexureMode " << textureMode << std::endl;
    _glGenTextures(1, &(this->textureID));
    std::cout << "Texture ID " << textureID << std::endl;
    _glBindTexture(GL_TEXTURE_2D, textureID);
    _glTexImage2D(GL_TEXTURE_2D,
                  0,            // level
                  textureMode,  // internalFormat
                  width, height,
                  0,                 // border
                  textureMode,       // format
                  GL_UNSIGNED_BYTE,  // type
                  data);

    _glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    _glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

Texture* Texture::createEmpty(int width, int height, int textureMode) {
    int bytesPerPixel = (textureMode == GL_RGBA ? 4 : 3);
    size_t arraySize = bytesPerPixel * width * height;
    char* pixels = new char[arraySize];
    memset(pixels, arraySize * sizeof(char), 0);
    Texture* createdTexture = new Texture(width, height, textureMode, pixels);
    delete[] pixels;
    return createdTexture;
}

Texture* Texture::fromSurface(SDL_Surface* sourceSurface) {
    return new Texture(sourceSurface->w, sourceSurface->h,
                       getFormatFromSurface(sourceSurface),
                       sourceSurface->pixels);
}

GLuint Texture::getTextureID() {
    return textureID;
}

void Texture::update(SDL_Surface* surface, SDL_Rect* rect) {
    if (rect->x + rect->w > this->width || rect->y + rect->h > this->height) {
        throw std::invalid_argument("Updated rect outside bounds of texture");
    }
    GLenum surfaceTextureMode = getFormatFromSurface(surface);
    if (surfaceTextureMode != this->textureMode) {
        std::cerr << "Surface mode is " << surfaceTextureMode
                  << ", but original surface was " << textureMode << std::endl;
        throw std::invalid_argument(
            "Texture mode of surface provided to Texture::update does not match"
            " initial texture mode");
    }
    _glBindTexture(GL_TEXTURE_2D, textureID);
    _glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
    _glTexSubImage2D(GL_TEXTURE_2D,
                     0,                   // level
                     rect->x,             // x offset
                     rect->y,             // y offset
                     rect->w,             // width,
                     rect->h,             // height,
                     surfaceTextureMode,  // format
                     GL_UNSIGNED_BYTE,    // type
                     surface->pixels      // data
    );
    _glBindTexture(GL_TEXTURE_2D, 0);
}