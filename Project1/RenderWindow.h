#pragma once
#include"commonFuncion.h"
#include"Entity.h"
#include"Charater.h"

namespace commonFuc
{
	SDL_Rect getTileSet(int id);

	void RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(Entity& p_entity);
	//void render(Charator& p_charator);
	void render(SDL_Texture* tex, SDL_Rect* src, SDL_Rect dst, double angle, SDL_Point* center, SDL_RendererFlip flip);
	void render(SDL_Texture* tex, SDL_Rect* src, SDL_Rect dest);
	void display();
}