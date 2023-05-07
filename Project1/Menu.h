#pragma once
#include"commonFuncion.h"
#include"RenderWindow.h"


using namespace std;


class Menu
{
public:
	//Menu();
	SDL_Texture* menu_pic;
	void runMenu(Entity play, Entity quit, Entity tutorial, SDL_Event& e
		, bool& gameRunning, bool& runningMenu, bool& gametutorial);
	int xhisa = 0, yhisa = 0;	
};