#pragma once
#include"commonFuncion.h"
#include"RenderWindow.h"
#include"Entity.h"


const int animationSkeletonWalkFrame = 13;
const int animationSkeletonAttackFrame = 18;
const int animationSkeletonHitFrame = 8;
const int animationSkeletonDeadFrame = 15;

const int animationBatFlyFrame = 4;
const int animationBatAttackFrame = 14;
const int animationBatDeadFrame = 6;
const int animationBatHitFrame = 1;

class Monster {
public:
	enum Skeleton
	{
		SkeletonWalk,
		SkeletonAttack,
		SkeletonDeath,
		SkeletonHit

	};
	Monster();
	void loadSkeletonImage();
	void loadBatImage();
	void show();
	void doPlayer(gameMap& game_map);
	void checkToMap(gameMap& game_map);
	void setMapXY(const int map_x_, const int map_y_) { map_x = map_x_; map_y = map_y_; };


	void animationSkeletonWalk();
	void animationSkeletonAttack();
	void animationSkeletonDead();
	void animationSkeletonHit();


	void SetClips();
	void SetAnimationPos(const int& posA, const int& posB) { animationA = posA; animationB = posB; }
	void SetInputLeft() { inputType.right = 0, inputType.left = 1; }
	void SetInputRight() { inputType.left = 0, inputType.right = 1; }
	void SkeletonMove();
		

	void setX_val(const float xVal) { x_val = xVal;}
	void setY_val(const float yVal) { y_val = yVal;}
	void setX_Pos(const float xPos) { x_pos = xPos;}
	void setY_Pos(const float yPos) { y_pos = yPos;}

	int get_WithFrame() { return width_frame; }
	int get_HeighFrame() { return height_frame; }
	int getX_Pos() { return x_pos; };
	int getY_Pos() { return y_pos; };
	bool alive;


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
	bool can_moveR;
	bool can_moveL;
	bool block;
	

	int animationA;
	int animationB;

	int frame = 0;
	int frameDead = 0;
	int frameAttack = 0;

	std::vector<Entity> SkeletonRight;
	std::vector<Entity> SkeletonLeft;


	std::vector<Entity> BatFlyLeft;
	std::vector<Entity> BatFlyRight;
	std::vector<Entity> BatAttackLeft;
	std::vector<Entity> BatAttackRight;
	std::vector<Entity> BatDeadLeft;
	std::vector<Entity> BatDeadRight;
	std::vector<Entity> BatHitkLeft;
	std::vector<Entity> BatHitLLeft;


	SDL_Rect AnimationWalkRight[animationSkeletonWalkFrame];
	SDL_Rect AnimationWalkLeft[animationSkeletonWalkFrame];
	SDL_Rect AnimationAttackRight[animationSkeletonAttackFrame];
	SDL_Rect AnimationAttackLeft[animationSkeletonAttackFrame];
	SDL_Rect AnimationDeadRight[animationSkeletonDeadFrame];
	SDL_Rect AnimationDeadLeft[animationSkeletonDeadFrame];
	SDL_Rect AnimationHitRight[animationSkeletonHitFrame];
	SDL_Rect AnimationHitLeft[animationSkeletonHitFrame];

	Input inputType;

};