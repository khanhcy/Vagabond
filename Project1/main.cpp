#include"commonFuncion.h"
#include"Entity.h"
#include "RenderWindow.h"


int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	RenderWindow window("GAME", SCREEN_WIDTH, SCREEN_HIGH);

	Entity entity1(100, 50, window.loadTexture("image/loaded.png"));


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

		window.clear();
		window.render(entity1);
		window.display();

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}