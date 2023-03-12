#pragma once
#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"
#include"Map.h"

const int RunAnimationFrame = 8;

const int idleAnimationFrame = 2;


// trọng lực rơi
static float gravity_speed = 0.8;

// tốc độ rơi tối đa
const float maxGravity_speed = 2;

const float player_speed = 5;




class Charater{
public:
	enum animation
	{

		Walk_right,
		Walk_left,
	};
	Charater();
	void loadImage();
	void show();
	void HandleInputAction(SDL_Event e);
	void doPlayer();
	//void checkToMap(map& gamemap);

private:

	//vị trí hiện tại 
	float x_pos = 0;
	float y_pos = 0;

	// kích thước từng frame;
	int width_frame = 300;
	int height_frame = 300;

	int frame;

	int status;

	std::vector<Entity> RunAnimationRight;
	std::vector<Entity> RunAnimationLeft;
	std::vector<Entity> idleAnimationRight;
	std::vector<Entity> idleAnimationLeft;

	Input inputType;

};