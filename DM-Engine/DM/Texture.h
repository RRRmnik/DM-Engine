#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>

class Texture
{
public:
	void Load(const char* path, SDL_Renderer* pRenderer);

	SDL_Surface* GetSurface() { return m_pSurface; }
	SDL_Texture* GetTexture() { return m_pTexture; }
private:
	SDL_Surface* m_pSurface;
	SDL_Texture* m_pTexture;
};

#endif