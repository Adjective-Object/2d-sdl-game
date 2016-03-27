#include <SDL.h>
#include <SDL/image.h>

extern SDL_Texture *engineFallbackTexture;

/**
* Loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* loadPNG(const std::string &file, SDL_Renderer *ren){
    //Initialize to nullptr to avoid dangling pointer issues
    SDL_Texture *texture = engineFallbackTexture;
    //Load the image
    SDL_Surface *loadedImage = SDL_LoadPNG(file.c_str());
    //If the loading went ok, convert to texture and return the texture
    if (loadedImage != nullptr){
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        //Make sure converting went ok too
        if (texture == nullptr){
            logSDLError(std::cout, "CreateTextureFromSurface");
        }
    }
    else {
        logSDLError(std::cout, "LoadBMP");
    }
    return texture;
}

