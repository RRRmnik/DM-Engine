#include <stdio.h>
#include "DM/DM-Engine.h"

Game game;

void Start()
{
	printf("Hello world!\n");
}

void Update()
{

}

void Render()
{

}

int main(int argc, char* argv[])
{
	game.SetStart(&Start);
	game.SetUpdate(&Update);
	game.SetRender(&Render);

	game.Run();

	return 0;
}
