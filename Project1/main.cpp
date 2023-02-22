#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "RenderViewport.h"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	RenderViewport Viewport("GAME", 0, 0, 1280, 720);

	Viewport.setViewport(Viewport.getRect());

	SDL_Texture* grassTexture = Viewport.loadTexture("image/loaded.png");

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		Viewport.clear();
		Viewport.render(grassTexture);
		Viewport.display();

	}

	Viewport.cleanUp();
	SDL_Quit();

	return 0;
}