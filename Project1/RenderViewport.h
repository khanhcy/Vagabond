#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include"RenderWindow.h"
class RenderViewport : public RenderWindow {
public:
	RenderViewport(const char* p_title, int p_x, int p_y, int p_w, int p_h);
	void setViewport(SDL_Rect& Viewport);
	SDL_Rect& getRect();
private:
	SDL_Rect Viewport;
};


