#pragma once
#include"commonFuncion.h"


enum Menu
{
	EXIT,
	PLAY,
	MENU,
	INSTRUCTION
};

class Button
{
public:
	//Initializes internal variables
	Button();

	//Sets top left position
	void setPosition(int x, int y);

	//Handles mouse event
	void handleEvent(SDL_Event* e);

	//Shows button sprite
	void render();

private:
	//Top left position
	SDL_Point mPosition;

	//Currently used global sprite
	Menu MenuStauts;
};