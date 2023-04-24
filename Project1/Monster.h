#pragma once
#include"commonFuncion.h"
#include"RenderWindow.h"
#include"Entity.h"
class Monster {
public:
	enum Skeleton
	{
		SkeletonIdie,
		SkeletonWalk,
		SkeletonAttack,
		SkeletonDeath,
		SkeletonHit

	};
	Monster();
	void loadImage();
	void show();
	void doPlayer(gameMap& game_map);
	void checkToMap(gameMap& game_map);
	void setMapXY(const int map_x_, const int map_y_) { map_x = map_x_; map_y = map_y_; };
	void animationIdle();
	void animationWalk();
	//void centerEntityOnMap(gameMap& game_map);

	void SetClips();
	void SetAnimationPos(const int& posA, const int& posB) { animationA = posA; animationB = posB; }
	void SetInputLeft() { inputType.right = 0, inputType.left = 1; }
	void SetInputRight() { inputType.left = 0, inputType.right = 1; }
	void MoveType();

	void setX_val(const float xVal) { x_val = xVal;}
	void setY_val(const float yVal) { y_val = yVal;}
	void setX_Pos(const float xPos) { x_pos = xPos;}
	void setY_Pos(const float yPos) { y_pos = yPos;}

	int get_WithFrame() { return width_frame; }
	int get_HeighFrame() { return height_frame; }
	int getX_Pos() { return x_pos; };
	int getY_Pos() { return y_pos; };


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

	bool on_ground;
	bool can_move;
	bool block;

	int animationA;
	int animationB;

	int frame;
	//std::vector<Entity> SkeletonLeft;
	std::vector<Entity> SkeletonRight;

	SDL_Rect AnimationIdleRight[11];
	SDL_Rect AnimationWalkRight[13];

	Input inputType;

};