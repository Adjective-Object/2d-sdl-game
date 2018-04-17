#ifndef __ENGINE_TEXTURE
#define __ENGINE_TEXTURE
#include "engine/gl.h"

class Texture {
   private:
    GLuint textureID;
    int width;
    int height;
    Texture(int width, int height, int textureMode, const GLvoid* data);

   public:
    static Texture* fromSurface(SDL_Surface* surface);
    static Texture* createEmpty(int width,
                                int height,
                                int textureMode = GL_RGBA);
    void update(SDL_Surface* surface, SDL_Rect* rect);
    GLuint getTextureID();
};

#endif