#pragma once
#include"commonFuncion.h"

class Entity
{
public:

	Entity();
	Entity(float p_x, float p_y,int p_w, int p_h, SDL_Texture* p_tex);
	Entity(SDL_Rect p_rect, SDL_Texture* p_tex);
	Entity(SDL_Texture* p_tex);
	SDL_Rect getCurrentFrame();
	SDL_Texture* getTex();

	void setEntity(float p_x, float p_y, int p_w, int p_h);
	void setEntity(SDL_Rect p_rect);
	void setCurrentFrame(float p_x, float p_y, int p_w, int p_h);
	void setCurrentFrame(SDL_Rect p_rect);

	float getX();	
	float getY();
	int getW();
	int getH();
protected:
	float x, y;
	int w, h;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};