#pragma once
#include"commonFuncion.h"

#include"Entity.h"

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(Entity& p_entity);
	void render(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	void display();
	SDL_Renderer* getRenderer()const;
		
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	
};