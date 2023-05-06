#pragma once
#include"commonFuncion.h"
#include"Entity.h"
#include"Charater.h"

const int Map_thorn[] = { 211,212,213,214,215,216 };

const int Map_wall[] = { 16, 17, 18, 31, 33, 46, 47, 48, 76, 77, 78, 91, 93, 106, 107, 108, 145, 136, 137 ,138, 157, 158};

const int Map_corner[] = { 16,18,76,78 };

const int Map_key = 146;

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
	bool init();
	void display();


	bool check_wall(int n);
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);


}