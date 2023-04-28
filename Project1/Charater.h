#pragma once
#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"
#include"Map.h"

const int RunAnimationFrame = 8;
const int idleAnimationFrame = 2;
const int runEndAnimationFrame = 4;
const int jumpAnimationFrame = 3;
const int dashAnimationFrame = 4;
const int deadAnimationFrame = 7;
const int attackAnimationFrame = 3;


// trọng lực rơi
const float gravity_speed = 3;

// tốc độ rơi tối đa
const float maxGravity_speed = 4;

const float jump_speed = 5.5;
const float player_speed = 3;
const float dash_speed = 10;


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
	bool checkMap(gameMap& game_map);
	void setMapXY(const int map_x_, const int map_y_){ map_x = map_x_; map_y = map_y_; };
	void centerEntityOnMap(gameMap& game_map);
	bool attackMonster(SDL_Rect& Monster);


	void animationRun();
	void animationJump();
	void animationDash();
	void animationDead();
	void animationAttack();

	SDL_Rect getCharater() {
		SDL_Rect res = { x_pos, y_pos, height_frame, height_frame };
		if (inputType.attack == 1 && run_left == status) {
			res.x -= 89;
		}
		return res;
	}
	bool attacking() {
		if (inputType.attack == 1) {
			return true;
		}
		else {
			return false;
		}
	}
private:
	float x_val;
	float y_val;

	//vị trí hiện tại 
	float x_pos = 0;
	float y_pos = 0;

	float his = 0;
	//float y_his = 0;

	//lưu vị trí map hiện tại
	int map_x;
	int map_y;

	// kích thước từng frame;
	int width_frame = 45;
	int height_frame = 45;

	int status;

	bool runing;
	bool jumping;
	bool on_block;
	bool dashing;
	bool centermap;
	bool deading;


	// biến để lưu thời gian bắt dâu nhảy
	Uint32 jumpStartTime;

	Uint32 dashTime;
	Uint32 jump_duration;

	bool on_ground;

	std::vector<Entity> dashAnimationLeft;
	std::vector<Entity> dashAnimationRight;

	int frame;
	int frameAttack;
	int frameRunEnd;
	int frameJump;
	int frameDash;
	int frameDead;

	std::vector<Entity> RunAnimationRight;
	std::vector<Entity> RunAnimationLeft;
	std::vector<Entity> idleAnimationRight;
	std::vector<Entity> idleAnimationLeft;
	std::vector<Entity> runEndAnimationLeft;
	std::vector<Entity> runEndAnimationRight;
	std::vector<Entity> jumpAnimationLeft;
	std::vector<Entity> jumpAnimationRight;
	std::vector<Entity> deadAnimationLeft;
	std::vector<Entity> deadAnimationRight;
	std::vector <Entity> attackAnimationLeft;
	std::vector<Entity> attackAnimationRight;
	

	Input inputType;

};