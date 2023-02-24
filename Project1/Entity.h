#pragma once
#include"commonFuncion.h"


class Entity {
public:
	Entity(float p_x, float p_y, SDL_Texture* tex);
	float getX();
	float getY();
	SDL_Rect getCurrentFrame();
	SDL_Texture* getTex();

private:
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};