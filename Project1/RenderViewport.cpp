#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "RenderViewport.h"

RenderViewport::RenderViewport(const char* p_title,int p_x, int p_y, int p_w, int p_h) : RenderWindow( p_title, p_w, p_h)
{
	Viewport = { p_x,p_y,p_w,p_h };
}

SDL_Rect& RenderViewport::getRect() {
	return Viewport;
}

void RenderViewport::setViewport(SDL_Rect &Viewport)
{
	Viewport.w /= 2;
	Viewport.h /= 2;
	SDL_RenderSetViewport(getRenderer(), &Viewport);
}
