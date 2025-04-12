#include <stdio.h>
#include "DM-Engine.h"

Game game;

Texture texture;
Vector2f position;

void Start()
{
	texture.Load("player.png", game.GetRenderer());
	position =
	{
		(float)game.GetGameSettings()->WINDOW_WIDTH / 2,
		(float)game.GetGameSettings()->WINDOW_HEIGHT / 2
	};
}

void Update()
{
	float dt = game.GetDt();
	float speed = 1000.0f;

	if (game.IsKeyPressed(SDL_SCANCODE_W))
	{
		position.y -= speed * dt;
	}
	if (game.IsKeyPressed(SDL_SCANCODE_A))
	{
		position.x -= speed * dt;
	}
	if (game.IsKeyPressed(SDL_SCANCODE_S))
	{
		position.y += speed * dt;
	}
	if (game.IsKeyPressed(SDL_SCANCODE_D))
	{
		position.x += speed * dt;
	}
}

void Render()
{
	game.Clear(Color{});
	game.DrawTexture
	(
		texture,
		FloatRect{ position.x, position.y, 50, 70 },
		Color{ 255, 255, 255 }
	);
}

int main(int argc, char* argv[])
{
	GameSettings gameSettings =
	{
		1280,
		720
	};

	game.SetStart(&Start);
	game.SetUpdate(&Update);
	game.SetRender(&Render);

	game.SetGameSettings(&gameSettings);

	game.Run();

	return 0;
}
