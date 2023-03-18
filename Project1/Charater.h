#pragma once
#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"
#include"Map.h"

const int RunAnimationFrame = 8;
const int idleAnimationFrame = 2;
const int runEndAnimationFrame = 4;
const int jumpAnimationFrame = 3;


// trọng lực rơi
static float gravity_speed = 2;

// tốc độ rơi tối đa
const float maxGravity_speed = 5;

const float player_speed = 7;


const int item_key = 146;
const int item_chest = 147;


//gai từ 211 đến 216;
//bậc lên 20;


class gameMap;

class Charater{
public:
	enum animation
	{
		run_right,
		run_left,
	};
	Charater();
	void loadImage();
	void show();
	void HandleInputAction(SDL_Event e);
	void doPlayer(gameMap& game_map);
	void checkToMap(gameMap& game_map);
	void setMapXY(const int map_x_, const int map_y_){ map_x = map_x_; map_y = map_y_; };
	void centerEntityOnMap(gameMap& game_map);
private:
	float x_val;
	float y_val;

	//vị trí hiện tại 
	float x_pos = 0;
	float y_pos = 0;

	//lưu vị trí map hiện tại
	int map_x;
	int map_y;

	// kích thước từng frame;
	int width_frame = 45;
	int height_frame = 45;

	int frame;

	int status;

	bool runing;

	bool on_ground;

	int frameRunEnd;
	int frameJump;

	std::vector<Entity> RunAnimationRight;
	std::vector<Entity> RunAnimationLeft;
	std::vector<Entity> idleAnimationRight;
	std::vector<Entity> idleAnimationLeft;
	std::vector<Entity> runEndAnimationLeft;
	std::vector<Entity> runEndAnimationRight;
	std::vector<Entity> jumpAnimaitionLeft;
	std::vector<Entity> jumpAnimationRight;

	Input inputType;

};