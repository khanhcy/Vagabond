#include"Entity.h"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex) {
	x = p_x;
	y = p_y;
	tex = p_tex;
// đây là hàm lấy thuộc tính của p_tex
	SDL_QueryTexture(p_tex, NULL,  NULL, &currentFrame.w, &currentFrame.h);
	currentFrame.x = 0;
	currentFrame.y = 0;


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
