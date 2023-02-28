#include"Entity.h"

Entity::Entity(float p_x, float p_y,int p_w,int p_h, SDL_Texture* p_tex) {
	x = p_x;
	y = p_y;
	w = p_w;
	h = p_h;
	tex = p_tex;
// đây là hàm lấy thuộc tính của p_tex
	SDL_QueryTexture(p_tex, NULL,  NULL, &currentFrame.w, &currentFrame.h);
	currentFrame.x = 0;
	currentFrame.y = 0;
}

Entity::Entity(SDL_Rect p_rect, SDL_Texture* p_tex) {
	x = p_rect.x;
	y = p_rect.y;
	w = p_rect.w;
	h = p_rect.h;
	tex = p_tex;
	SDL_QueryTexture(p_tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
	currentFrame.x = 0;
	currentFrame.y = 0;
}

Entity::Entity(SDL_Texture* p_tex) {
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	tex = p_tex;
	// đây là hàm lấy thuộc tính của p_tex
	SDL_QueryTexture(p_tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
	currentFrame.x = 0;
	currentFrame.y = 0;
}


void Entity::setEntity(float p_x, float p_y, int p_w, int p_h) {
	x = p_x;
	y = p_y;
	w = p_w;
	h = p_h;
}

void Entity::setEntity(SDL_Rect p_rect) {
	x = p_rect.x;
	y = p_rect.y;
	w = p_rect.w;
	h = p_rect.h;
}
void Entity::setCurrentFrame(float p_x, float p_y, int p_w, int p_h) {
	currentFrame.x = p_x;
	currentFrame.y = p_y;
	currentFrame.w = p_w;
	currentFrame.h = p_h;
}
void Entity::setCurrentFrame(SDL_Rect p_rect) {
	currentFrame.x = p_rect.x;
	currentFrame.y = p_rect.y;
	currentFrame.w = p_rect.w;
	currentFrame.h = p_rect.h;
}


float Entity::getX() {
	return x;
}

float Entity::getY() {
	return y;
}

SDL_Rect Entity::getCurrentFrame() {
	return currentFrame;
}

SDL_Texture* Entity::getTex() {
	return tex;
}
int Entity::getW() {
	return w;
}
int Entity::getH() {
	return h;
}
