#include "Texture.h"
#include <stdio.h>

void Texture::Load(const char* path, SDL_Renderer* pRenderer)
{
	m_pSurface = IMG_Load(path);
	if (!m_pSurface)
	{
		fprintf(stderr, "Error loading image.\n");
	}
	m_pTexture = SDL_CreateTextureFromSurface(pRenderer, m_pSurface);
	if (!m_pTexture)
	{
		fprintf(stderr, "Error creating texture from surface.\n");
	}
	SDL_FreeSurface(m_pSurface);
}