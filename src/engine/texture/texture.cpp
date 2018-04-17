#include <SDL.h>
#include <stdexcept>

#include "engine/texture/texture.hpp"

GLenum getFormatFromSurface(SDL_Surface* surface) {
    return (surface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
}

Texture::Texture(int width, int height, int textureMode, const GLvoid* data)
    : width(width), height(height) {
    GLuint textureID = 0;
    glGenTextures(1, &textureID);
    CHECK_GL_ERROR(glGenTextures);
    glBindTexture(GL_TEXTURE_2D, textureID);
    CHECK_GL_ERROR(glBindTexture);
    glTexImage2D(GL_TEXTURE_2D,
                 0,            // level
                 textureMode,  // internalFormat
                 width, height,
                 0,                 // border
                 textureMode,       // format
                 GL_UNSIGNED_BYTE,  // type
                 data);
    CHECK_GL_ERROR(glTexImage2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    CHECK_GL_ERROR(glTexParameteri);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    CHECK_GL_ERROR(glTexParameteri);
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
    glTexSubImage2D(this->textureID,
                    0,        // level
                    rect->x,  // x offset
                    rect->y,  // y offset
                    rect->w,  // width,
                    rect->h,  // height,
                    getFormatFromSurface(surface),
                    GL_UNSIGNED_BYTE,  // type
                    surface->pixels    // data
    );
    CHECK_GL_ERROR(glTexSubImage2D);
}