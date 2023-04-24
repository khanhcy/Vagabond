#include"Monster.h"

Monster::Monster()
{
	x_pos = 100;
	y_pos = 100;
	x_val = 0;
	y_val = 0;
	frame = 0;
	//width_frame = 0;
	//height_frame = 0;
	inputType.right = 1;
	inputType.left = 0;
	inputType.jump = 0;
	on_ground = false;
	map_x = 0;
	map_y = 0; 
	can_move = true;
	block = false;
	
};

void Monster::loadImage() {
	{
		Entity E(commonFuc::loadTexture("image/Monster/Skeleton/Skeleton Idle.png"));
		SkeletonRight.push_back(E);
	}
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
}

void Monster::SetClips() {
	for (int i = 0; i < 11; i++) {
		AnimationIdleRight[i].x = i * 24;
		AnimationIdleRight[i].y = 0;
		AnimationIdleRight[i].w = 24;
		AnimationIdleRight[i].h = 32;
	}
	for (int i = 0; i < 13; i++) {
		AnimationWalkRight[i].x = i * 22;
		AnimationWalkRight[i].y = 0;
		AnimationWalkRight[i].w = 22;
		AnimationWalkRight[i].h = 33;
	}
}

void Monster::show() {
	SDL_Rect dest = { x_pos - map_x ,y_pos - map_y, width_frame, height_frame };
	for (int i = 0; i < 5; i++) {
		SkeletonRight[i].setEntity(dest);
	}
	animationWalk();
	MoveType();
}

void Monster::animationIdle() {
	frame++;
	if (frame >= 11) {
		frame = 0;
	}
	SkeletonRight[0].setCurrentFrame(AnimationIdleRight[frame]);
	commonFuc::render(SkeletonRight[0]);
}

void Monster::animationWalk() {
	frame++;
	if (frame >= 13) {
		frame = 0;
		//inputType.idle = 1;
		//inputType.left = 0;
		//inputType.right = 0;
	}
	SkeletonRight[1].setCurrentFrame(AnimationWalkRight[frame]);
	commonFuc::render(SkeletonRight[1]);
}


void Monster::doPlayer(gameMap& game_map) {
	x_val = 0;
	y_val += gravity_speed;
	if (y_val >= maxGravity_speed) {
		y_val = maxGravity_speed;
	}
	if (inputType.right == 1) {
		x_val += player_speed;
	}
	else if (inputType.left == 1) {
		x_val -= player_speed;
	}
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

void Monster::MoveType() {
	if (on_ground == true) {
		if (x_pos < animationB) {
			inputType.left = 1;
			inputType.right = 0;
			block = true;
		}
		if (x_pos > animationA) {
			inputType.right = 1;
			inputType.left = 0;
			block = true;
		}
		if (x_pos <= animationA && block == true) {
			inputType.left = 1;
			inputType.right = 0;
		}
	}
}
