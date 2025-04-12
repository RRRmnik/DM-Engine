#include "Game.h"
#include <stdio.h>

void Game::DrawPixel(Vector2f position, Color color)
{
	SDL_Rect SDLRect =
	{
		position.x,
		position.y,
		1,
		1
	};

	SDL_SetRenderDrawColor(m_pRenderer, color.r, color.g, color.b, color.a);

	SDL_RenderFillRect(m_pRenderer, &SDLRect);
}

void Game::DrawRect(FloatRect rect, Color color)
{
	SDL_Rect SDLRect =
	{
		rect.x,
		rect.y,
		rect.width,
		rect.height
	};

	SDL_SetRenderDrawColor(m_pRenderer, color.r, color.g, color.b, color.a);

	SDL_RenderFillRect(m_pRenderer, &SDLRect);
}

void Game::DrawCircle(FloatCircle circle, Color color)
{
	int offsetx, offsety, d;

	offsetx = 0;
	offsety = circle.radius;
	d = circle.radius - 1;

	SDL_SetRenderDrawColor(m_pRenderer, color.r, color.g, color.b, color.a);

	while (offsety >= offsetx)
	{
		SDL_RenderDrawLine(m_pRenderer, circle.x - offsety, circle.y + offsetx,
										circle.x + offsety, circle.y + offsetx);
		SDL_RenderDrawLine(m_pRenderer, circle.x - offsetx, circle.y + offsety,
										circle.x + offsetx, circle.y + offsety);
		SDL_RenderDrawLine(m_pRenderer, circle.x - offsetx, circle.y - offsety,
										circle.x + offsetx, circle.y - offsety);
		SDL_RenderDrawLine(m_pRenderer, circle.x - offsety, circle.y - offsetx,
										circle.x + offsety, circle.y - offsetx);

		if (d >= 2 * offsetx)
		{
			d -= 2 * offsetx + 1;
			offsetx += 1;
		}
		else if (d < 2 * (circle.radius - offsety))
		{
			d += 2 * offsety - 1;
			offsety -= 1;
		}
		else
		{
			d += 2 * (offsety - offsetx - 1);
			offsety -= 1;
			offsetx += 1;
		}
	}
}

void Game::DrawCircleOutline(FloatCircle circle, Color color)
{
	int offsetx, offsety, d;

	offsetx = 0;
	offsety = circle.radius;
	d = circle.radius - 1;

	SDL_SetRenderDrawColor(m_pRenderer, color.r, color.g, color.b, color.a);

	while (offsety >= offsetx)
	{
		SDL_RenderDrawPoint(m_pRenderer, circle.x + offsetx, circle.y + offsety);
		SDL_RenderDrawPoint(m_pRenderer, circle.x + offsety, circle.y + offsetx);
		SDL_RenderDrawPoint(m_pRenderer, circle.x - offsetx, circle.y + offsety);
		SDL_RenderDrawPoint(m_pRenderer, circle.x - offsety, circle.y + offsetx);
		SDL_RenderDrawPoint(m_pRenderer, circle.x + offsetx, circle.y - offsety);
		SDL_RenderDrawPoint(m_pRenderer, circle.x + offsety, circle.y - offsetx);
		SDL_RenderDrawPoint(m_pRenderer, circle.x - offsetx, circle.y - offsety);
		SDL_RenderDrawPoint(m_pRenderer, circle.x - offsety, circle.y - offsetx);

		if (d >= 2 * offsetx)
		{
			d -= 2 * offsetx + 1;
			offsetx += 1;
		}
		else if (d < 2 * (circle.radius - offsety))
		{
			d += 2 * offsety - 1;
			offsety -= 1;
		}
		else
		{
			d += 2 * (offsety - offsetx - 1);
			offsety -= 1;
			offsetx += 1;
		}
	}
}

void Game::DrawTexture(Texture texture, FloatRect rect, Color color = {})
{
	SDL_Rect SDLRect =
	{
		rect.x,
		rect.y,
		rect.width,
		rect.height
	};

	SDL_SetTextureColorMod(texture.GetTexture(), color.r, color.g, color.b);

	SDL_RenderCopy(m_pRenderer, texture.GetTexture(), NULL, &SDLRect);
}

void Game::Clear(Color color)
{
	SDL_SetRenderDrawColor(m_pRenderer, color.r, color.g, color.b, color.a);

	SDL_RenderClear(m_pRenderer);
}

bool Game::Setup()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL.\n");
		return false;
	}

	m_pWindow = SDL_CreateWindow
	(
		0,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		(*m_pGameSettings).WINDOW_WIDTH,
		(*m_pGameSettings).WINDOW_HEIGHT,
		0
	);
	if (!m_pWindow)
	{
		fprintf(stderr, "Error creating SDL Window.\n");
		return false;
	}

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	if (!m_pRenderer)
	{
		fprintf(stderr, "Error creating SDL Renderer.\n");
		return false;
	}

	return true;
}

void Game::ProcessTime()
{
	dt = SDL_GetTicks64() / 1000.0f - timer;
	timer = SDL_GetTicks64() / 1000.0f;
	fps = 1.0f / dt;
}

void Game::PollEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		m_IsRunning = false;
		break;
	}
}

void Game::GetInput()
{
	m_pKeyboardInput = SDL_GetKeyboardState(nullptr);
}

void Game::Display()
{
	SDL_RenderPresent(m_pRenderer);
}

void Game::Run()
{
	m_IsRunning = Setup();
	
	m_pStart();

	while (m_IsRunning)
	{
		ProcessTime();
		GetInput();
		m_pUpdate();
		m_pRender();
		Display();
		PollEvents();
	}

	Quit();
}

void Game::Quit()
{
	
}