#include"Button.h"


Button::Button()
{
	mPosition.x = 0;
	mPosition.y = 0;
	MenuStauts = MENU;
}

void Button::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}