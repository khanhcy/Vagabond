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

	Entity backGround(0, 0, 0, 0, window.loadTexture("image/background/dots.png"));

	SDL_Rect grect[4];
	grect[0] = { 0,0,100,100 };
	grect[1] = { 0,100,100,100 };
	grect[2] = { 100,0,100,100 };
	grect[3] = { 100,100,100,100 };

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
		SDL_SetRenderDrawColor(window.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		window.clear();
		backGround.setEntity(0, 0, grect[0].w, grect[0].h);
		backGround.setCurrentFrame(grect[0]);
		window.render(backGround);
		backGround.setEntity(SCREEN_WIDTH - grect[1].w, 0, grect[1].h, grect[1].h);
		backGround.setCurrentFrame(grect[1]);
		window.render(backGround);
		backGround.setEntity(0,SCREEN_HIGH - grect[2].h, grect[2].h, grect[2].h);
		backGround.setCurrentFrame(grect[2]);
		window.render(backGround);
		backGround.setEntity(SCREEN_WIDTH - grect[3].w, SCREEN_HIGH - grect[3].h, grect[3].h, grect[3].h);
		backGround.setCurrentFrame(grect[3]);
		window.render(backGround);
		window.display();

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}