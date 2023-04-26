﻿#include"Monster.h"

Monster::Monster()
{
	x_pos = 100;
	y_pos = 100;
	x_val = 0;
	y_val = 0;
	//width_frame = 0;
	//height_frame = 0;
	inputType.right = 0;
	inputType.left = 0;
	inputType.jump = 0;
	on_ground = false;
	map_x = 0;
	map_y = 0; 
	can_moveR = true;
	can_moveL = false;
	block = true;
	alive = true;
	
};

void Monster::loadSkeletonImage() {
	{
		Entity E(commonFuc::loadTexture("image/Monster/Skeleton/Skeleton Walk.png"));
		SkeletonRight.push_back(E);
	}
	{
		Entity E(commonFuc::loadTexture("image/Monster/Skeleton/Skeleton Attack.png"));
		SkeletonRight.push_back(E);
	}
	{
		Entity E(commonFuc::loadTexture("image/Monster/Skeleton/Skeleton Dead.png"));
		SkeletonRight.push_back(E);
	}
	{
		Entity E(commonFuc::loadTexture("image/Monster/Skeleton/Skeleton Hit.png"));
		SkeletonRight.push_back(E);
	}

	{
		Entity E(commonFuc::loadTexture("image/Monster/Skeleton/Skeleton-walk-left.png"));
		SkeletonLeft.push_back(E);
	}
	{
		Entity E(commonFuc::loadTexture("image/Monster/Skeleton/Skeleton-attack-left.png"));
		SkeletonLeft.push_back(E);
	}
	{
		Entity E(commonFuc::loadTexture("image/Monster/Skeleton/Skeleton-dead-left.png"));
		SkeletonLeft.push_back(E);
	}
	{
		Entity E(commonFuc::loadTexture("image/Monster/Skeleton/Skeleton-hit-left.png"));
		SkeletonLeft.push_back(E);
	}

}

void Monster::loadBatImage() {
	SDL_Rect R = { 86,54,94,72 };
	for (int i = 0; i < animationBatAttackFrame; i++) {
		std::string s = "image/Monster/Bat/Bat-bite/demon-bat-bite" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 192, 192, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		BatAttackRight.push_back(E);
	}
	for (int i = animationBatAttackFrame - 1; i != -1; i--) {
		std::string s = "image/Monster/Bat/Bat-bite/Bat-bite-left (" + std::to_string(i + 1) + ").png";
		Entity E(0, 0, 192, 192, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		BatAttackLeft.push_back(E);
	}
	for (int i = 0; i < animationBatFlyFrame; i++) {
		std::string s = "image/Monster/Bat/Bat-flying/demon-bat-flying" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 192, 192, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		BatFlyRight.push_back(E);
	}
	for (int i = animationBatFlyFrame - 1; i != -1; i--) {
		std::cout << i << std::endl;
		std::string s = "image/Monster/Bat/Bat-flying/Bat-fly-left (" + std::to_string(i + 1) + ").png";
		Entity E(0, 0, 192, 192, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		BatFlyLeft.push_back(E);
	}
	for (int i = 0; i < animationBatDeadFrame; i++) {
		std::string s = "image/Monster/Bat/Bat-death/demon-bat-death" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 192, 192, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		BatDeadRight.push_back(E);
	}
	for (int i = animationBatDeadFrame - 1; i != -1; i--) {
		std::string s = "image/Monster/Bat/Bat-death/Bat-dead-left (" + std::to_string(i + 1) + ").png";
		Entity E(0, 0, 192, 192, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		BatDeadLeft.push_back(E);
	}
	{
		std::string s = "image/Monster/Bat/Bat-knockback/demon-bat-knockback.png";
		Entity E(0, 0, 192, 192, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		BatFlyRight.push_back(E);
	}
	{
		std::string s = "image/Monster/Bat/Bat-knockback/bat-knockback-left.png";
		Entity E(0, 0, 192, 192, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		BatFlyLeft.push_back(E);
	}
}

void Monster::SetClips() {

	for (int i = 0; i < animationSkeletonWalkFrame; i++) {
		AnimationWalkRight[i].x = i * 22;
		AnimationWalkRight[i].y = 0;
		AnimationWalkRight[i].w = 22;
		AnimationWalkRight[i].h = 33;
		AnimationWalkLeft[animationSkeletonWalkFrame - i - 1].x = i * 22;
		AnimationWalkLeft[animationSkeletonWalkFrame - i - 1].y = 0;
		AnimationWalkLeft[animationSkeletonWalkFrame - i - 1].w = 22;
		AnimationWalkLeft[animationSkeletonWalkFrame - i - 1].h = 33;
	}

	for (int i = 0; i < animationSkeletonAttackFrame; i++) {
		AnimationAttackRight[i].x = i * 22;
		AnimationAttackRight[i].y = 0;
		AnimationAttackRight[i].w = 22;
		AnimationAttackRight[i].h = 33;
		AnimationAttackLeft[animationSkeletonAttackFrame - i - 1].x = i * 22;
		AnimationAttackLeft[animationSkeletonAttackFrame - i - 1].y = 0;
		AnimationAttackLeft[animationSkeletonAttackFrame - i - 1].w = 22;
		AnimationAttackLeft[animationSkeletonAttackFrame - i - 1].h = 33;
	}

	for (int i = 0; i < animationSkeletonDeadFrame; i++) {
		AnimationDeadRight[i].x = i * 33;
		AnimationDeadRight[i].y = 0;
		AnimationDeadRight[i].w = 33;
		AnimationDeadRight[i].h = 33;
		AnimationDeadLeft[animationSkeletonDeadFrame - i - 1].x = i * 33;
		AnimationDeadLeft[animationSkeletonDeadFrame - i - 1].y = 0;
		AnimationDeadLeft[animationSkeletonDeadFrame - i - 1].w = 33;
		AnimationDeadLeft[animationSkeletonDeadFrame - i - 1].h = 33;

	}
	for (int i = 0; i < animationSkeletonHitFrame; i++) {
		AnimationHitRight[i].x = i * 22;
		AnimationHitRight[i].y = 0;
		AnimationHitRight[i].w = 22;
		AnimationHitRight[i].h = 33;
	}
	for (int i = animationSkeletonHitFrame - 1; i != -1; i--) {
		AnimationHitLeft[i].x = i * 22;
		AnimationHitLeft[i].y = 0;
		AnimationHitLeft[i].w = 22;
		AnimationHitLeft[i].h = 33;
	}

}

void Monster::show() {
	SDL_Rect dest = { x_pos - map_x ,y_pos - map_y, width_frame, height_frame };
	for (int i = 0; i < animationSkeletonWalkFrame; i++) {
		SkeletonRight[SkeletonWalk].setEntity(dest);
		SkeletonLeft[SkeletonWalk].setEntity(dest);
	}
	for (int i = 0; i < animationSkeletonDeadFrame; i++) {
		SkeletonRight[SkeletonDeath].setEntity(dest);
		SkeletonLeft[SkeletonDeath].setEntity(dest);
	}
	animationSkeletonWalk();
	animationSkeletonDead();
}


void Monster::animationSkeletonWalk() {
	frame++;
	if (frame / 3 >= 13) {
		frame = 0;

	}
	if (inputType.right == 1 && alive == true) {
		SkeletonRight[SkeletonWalk].setCurrentFrame(AnimationWalkRight[frame / 3]);
		commonFuc::render(SkeletonRight[SkeletonWalk]);
	}
	else if (inputType.left == 1 && alive == true) {
		SkeletonLeft[SkeletonWalk].setCurrentFrame(AnimationWalkLeft[frame / 3]);
		commonFuc::render(SkeletonLeft[SkeletonWalk]);
	}
	
}
void Monster::animationSkeletonAttack() {

}

void Monster::animationSkeletonHit() {

}
void Monster::animationSkeletonDead() {
	if (can_moveR == true && alive == false) {
		inputType.left = 0;
		inputType.right = 0;
		SkeletonRight[SkeletonDeath].setCurrentFrame(AnimationDeadRight[frameDead / 5]);
		commonFuc::render(SkeletonRight[SkeletonDeath]);
		frameDead++;
		std::cout << frameDead / 10 << std::endl;
		if ((frameDead / 5) >= 15) {
			frameDead = 0;
			alive = true;
		}
	}
	else if (can_moveL == true && alive == false) {
		inputType.left = 0;
		inputType.right = 0;
		SkeletonLeft[SkeletonDeath].setCurrentFrame(AnimationDeadLeft[frameDead / 5]);
		commonFuc::render(SkeletonLeft[SkeletonDeath]);
		frameDead++;
		std::cout << frameDead / 10 << std::endl;
		if ((frameDead / 5) >= 15) {
			frameDead = 0;
			alive = true;
		}
	}
}



void Monster::doPlayer(gameMap& game_map) {
	x_val = 0;
	y_val += gravity_speed;
	if (y_val >= maxGravity_speed) {
		y_val = maxGravity_speed;
	}
	if (inputType.right == 1) {
		x_val += player_speed - 1;
	}
	else if (inputType.left == 1) {
		x_val -= player_speed - 1;
	}
	SkeletonMove();
	checkToMap(game_map);
	//centerEntityOnMap(game_map);
}

void Monster::checkToMap(gameMap& game_map) {

	int heightMin = height_frame < TILE_SIZE ? height_frame : TILE_SIZE;
	int widthMin = width_frame < TILE_SIZE ? width_frame : TILE_SIZE;

	//vị trí theo chiều ngang
	int x_h1 = 0;
	int y_h1 = 0;
	int x_h2 = 0;
	int y_h2 = 0;
	x_h1 = (x_pos + x_val) / TILE_SIZE;
	x_h2 = (x_pos + x_val + width_frame) / TILE_SIZE;
	y_h1 = (y_pos + 1) / TILE_SIZE;
	y_h2 = (y_pos + heightMin - 1) / TILE_SIZE;

	//vị trí theo chiều dọc
	int x_v1 = 0;
	int y_v1 = 0;
	int x_v2 = 0;
	int y_v2 = 0;
	x_v1 = x_pos / TILE_SIZE;
	x_v2 = (x_pos + widthMin) / TILE_SIZE;
	y_v1 = (y_pos + y_val) / TILE_SIZE;
	y_v2 = (y_pos + y_val + height_frame - 1) / TILE_SIZE;



	// Kiểm tra va chạm theo chiều ngang
	if (x_h1 >= 0 && x_h2 < MAX_MAP_X && y_h1 >= 0 && y_h2 < MAX_MAP_Y) {
		if (x_val > 0) {
			if (game_map.getMap().tile[y_h1][x_h2] != -1 || game_map.getMap().tile[y_h2][x_h2] != -1) {
				x_pos = x_h2 * TILE_SIZE - width_frame - 1;
				x_val = 0;
				/*if (inputType.right == 1 && can_move == true) {
					inputType.right = 0;
					inputType.left = 1;
					can_move = false;
				}*/

			}
		}
		else if (x_val < 0) {
			if (game_map.getMap().tile[y_h1][x_h1] != -1 || game_map.getMap().tile[y_h2][x_h1] != -1) {
				x_pos = (x_h1 + 1) * TILE_SIZE;
				x_val = 0;
			}
		}
	}

	// Kiểm tra va chạm theo chiều dọc
	if (x_v1 >= 0 && x_v2 < MAX_MAP_X && y_v1 >= 0 && y_v2 < MAX_MAP_Y) {
		if (y_val > 0) {
			if (game_map.getMap().tile[y_v2][x_v1] != -1 || game_map.getMap().tile[y_v2][x_v2] != -1) {
				y_pos = y_v2 * TILE_SIZE - height_frame - 1;
				y_val = 0;
				on_ground = true;
				
			}
			else {
				on_ground = false;
			}
		}
		else if (y_val < 0) {
			if (game_map.getMap().tile[y_v1][x_v1] != -1 || game_map.getMap().tile[y_v1][x_v2] != -1) {
				y_pos = (y_v1 + 1) * TILE_SIZE;
				y_val = 0;
			}
		}
	}
	
	if (x_pos + x_val > 0) {
		x_pos += x_val;
		//y_pos += y_val;
	}
	y_pos += y_val;
}

void Monster::SkeletonMove() {
	if (x_pos >= animationB) {
		can_moveR = false;
		can_moveL = true;
	}
	if (x_pos <= animationA) {
		can_moveL = false;
		can_moveR = true;
	}
	if (can_moveR == true) {
		SetInputRight();
	}
	else if (can_moveL == true) {
		SetInputLeft();
	}
}


