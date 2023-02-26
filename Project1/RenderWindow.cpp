#include"commonFuncion.h"

#include "RenderWindow.h"
#include "Entity.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(p_filePath);

	if (loadedSurface == NULL) {
		std::cout << "Failed to load surface. Error: " << SDL_GetError() << std::endl;
	}
	else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == NULL) {

			std::cout << "Failed toCreateTextur. Error: " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(loadedSurface);
	}
	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{	
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w ;
	src.h = p_entity.getCurrentFrame().h ;
	SDL_Rect dst;
	dst.x = p_entity.getX();
	dst.y = p_entity.getY();
	dst.w = p_entity.getW();
	dst.h = p_entity.getH();

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* RenderWindow::getRenderer() const {
	return renderer;
}