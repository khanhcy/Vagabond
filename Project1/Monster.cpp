#include"Monster.h"

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
	inputType.attack = 0;
	knockback = false;
	healSkeleton = 0;
	commback = 0;
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

	{
		Entity R(commonFuc::loadTexture("image/UI/healMonster.png"));
		HP_Monster = R;
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
		AnimationAttackRight[i].x = i * 43;
		AnimationAttackRight[i].y = 0;
		AnimationAttackRight[i].w = 43;
		AnimationAttackRight[i].h = 37;
		AnimationAttackLeft[animationSkeletonAttackFrame - i - 1].x = i * 43;
		AnimationAttackLeft[animationSkeletonAttackFrame - i - 1].y = 0;
		AnimationAttackLeft[animationSkeletonAttackFrame - i - 1].w = 43;
		AnimationAttackLeft[animationSkeletonAttackFrame - i - 1].h = 37;
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
		AnimationHitRight[i].x = i * 30;
		AnimationHitRight[i].y = 0;
		AnimationHitRight[i].w = 30;
		AnimationHitRight[i].h = 32;
		AnimationHitLeft[animationSkeletonHitFrame - i - 1].x = i * 30;
		AnimationHitLeft[animationSkeletonHitFrame - i - 1].y = 0;
		AnimationHitLeft[animationSkeletonHitFrame - i - 1].w = 30;
		AnimationHitLeft[animationSkeletonHitFrame - i - 1].h = 32;
	}
	for (int i = 0; i < HP_size; i++) {
		R_HP[i].x = i * 47;
		R_HP[i].y = 0;
		R_HP[i].w = 47;
		R_HP[i].h = 4;
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
	for (int i = 0; i < animationSkeletonHitFrame; i++) {
		SkeletonRight[SkeletonHit].setEntity(dest);
		SkeletonLeft[SkeletonHit].setEntity(dest);
	}
	for (int i = 0; i < animationSkeletonAttackFrame; i++) {
		dest.w = 90;
		SkeletonRight[SkeletonAttack].setEntity(dest);
	}
	dest.x -= 45;
	for (int i = 0; i < animationSkeletonAttackFrame; i++) {
		dest.w = 90;
		SkeletonLeft[SkeletonAttack].setEntity(dest);
	}
	dest.x = x_pos - map_x;
	dest.y = y_pos - map_y;
	if (alive == false) {
		if (commback > 200) {
			alive = true;
			commback = 0;
		}
		commback++;
		if (commback <= 45) {
			animationSkeletonDead();
		}
		else {
			frameDead = 0;
		}

	}
	else {
		commback = 0;
		animationSkeletonWalk();
		animationSkeletonAttack();
		animationSkeletonHit();
		if (healSkeleton >= 3) {
			alive = false;
			healSkeleton = 0;
		}
	}
}

void Monster::animationSkeletonWalk() {
	frame++;
	if (frame / 3 >= 13) {
		frame = 0;

	}
	if (inputType.right == 1 && alive == true && inputType.attack == 0 && can_moveR == true && knockback == false) {
		SkeletonRight[SkeletonWalk].setCurrentFrame(AnimationWalkRight[frame / 3]);
		commonFuc::render(SkeletonRight[SkeletonWalk]);
	}
	else if (inputType.left == 1 && alive == true && inputType.attack == 0 && can_moveL == true && knockback == false) {
		SkeletonLeft[SkeletonWalk].setCurrentFrame(AnimationWalkLeft[frame / 3]);
		commonFuc::render(SkeletonLeft[SkeletonWalk]);
	}
	
}
void Monster::animationSkeletonAttack() {
	if (can_moveR == true) {
		if (inputType.attack == 1 && alive == true && knockback == false) {
			SkeletonRight[SkeletonAttack].setCurrentFrame(AnimationAttackRight[frameAttack / 3]);
			commonFuc::render(SkeletonRight[SkeletonAttack]);
			frameAttack++;
			if ((frameAttack / 3) >= animationSkeletonAttackFrame) {
				frameAttack = 0;
				inputType.attack = 0;
			}
		}

	}
	else if (can_moveL == true) {
		if (inputType.attack == 1 && alive == true && knockback == false) {
			SkeletonLeft[SkeletonAttack].setCurrentFrame(AnimationAttackLeft[frameAttack / 3]);
			commonFuc::render(SkeletonLeft[SkeletonAttack]);
			frameAttack++;
			if ((frameAttack / 3)>= animationSkeletonAttackFrame) {
				frameAttack = 0;
				inputType.attack = 0;
			}
		}
		
	}
	
}

void Monster::animationSkeletonHit() {
	if ( knockback == true) {
		if (can_moveR) {
			SkeletonRight[SkeletonHit].setCurrentFrame(AnimationHitRight[frameHit / 5]);
			commonFuc::render(SkeletonRight[SkeletonHit]);
			frameHit++;
		}else if (can_moveL) {
			SkeletonLeft[SkeletonHit].setCurrentFrame(AnimationHitLeft[frameHit / 5]);
			commonFuc::render(SkeletonLeft[SkeletonHit]);
			frameHit++;
			
		}
		if ((frameHit / 5) >= animationSkeletonHitFrame) {
			frameHit = 0;
			healSkeleton++;
			knockback = false;
		}
	}
}
void Monster::animationSkeletonDead() {
	if (can_moveR == true && alive == false && knockback == false) {
		inputType.left = 0;
		inputType.right = 0;
		SkeletonRight[SkeletonDeath].setCurrentFrame(AnimationDeadRight[frameDead / 5]);
		commonFuc::render(SkeletonRight[SkeletonDeath]);
		frameDead++;
	}
	else if (can_moveL == true && alive == false && knockback == false) {
		inputType.left = 0;
		inputType.right = 0;
		SkeletonLeft[SkeletonDeath].setCurrentFrame(AnimationDeadLeft[frameDead / 5]);
		commonFuc::render(SkeletonLeft[SkeletonDeath]);
		frameDead++;
	}
	if (alive == false) {
		if (frameDead / 5 >= animationSkeletonDeadFrame) {
			frameDead = 0;
		}
	}
}

void Monster::gravity() {
	y_val += gravity_speed;
	if (y_val >= maxGravity_speed) {
		y_val = maxGravity_speed;
	}
}

void Monster::doPlayer(gameMap& game_map) {
	x_val = 0;
	if (inputType.right == 1) {
		x_val += player_speed - 1;
	}
	else if (inputType.left == 1) {
		x_val -= player_speed - 1;
	}
	SkeletonMove();
	checkToMap(game_map);
}

void Monster::checkToMap(gameMap& game_map) {

	int heightMin = height_frame < TILE_SIZE ? height_frame : TILE_SIZE;
	int widthMin = width_frame < TILE_SIZE ? width_frame : TILE_SIZE;

	//vị trí theo chiều ngang
	int x_h1 = 0;
	int y_h1 = 0;
	int x_h2 = 0;
	int y_h2 = 0;
	x_h1 = (x_pos + x_val ) / TILE_SIZE;
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
			if (commonFuc::check_wall( game_map.getMap().tile[y_h1][x_h2]) == 1 ||commonFuc::check_wall( game_map.getMap().tile[y_h2][x_h2]) == 1) {
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
			if (commonFuc::check_wall(game_map.getMap().tile[y_h1][x_h1]) == 1 || commonFuc::check_wall(game_map.getMap().tile[y_h2][x_h1]) == 1) {
				x_pos = (x_h1 + 1) * TILE_SIZE;
				x_val = 0;
			}
		}
	}

	// Kiểm tra va chạm theo chiều dọc
	if (x_v1 >= 0 && x_v2 < MAX_MAP_X && y_v1 >= 0 && y_v2 < MAX_MAP_Y) {
		if (y_val > 0) {
			if (commonFuc::check_wall(game_map.getMap().tile[y_v2][x_v1]) == 1 || commonFuc::check_wall(game_map.getMap().tile[y_v2][x_v2]) == 1) {
				y_pos = y_v2 * TILE_SIZE - height_frame - 1;
				y_val = 0;
				on_ground = true;

			}
			else {
				on_ground = false;
			}
		}
		else if (y_val < 0) {
			if (commonFuc::check_wall(game_map.getMap().tile[y_v1][x_v1]) == 1 || commonFuc::check_wall(game_map.getMap().tile[y_v1][x_v2]) == 1) {
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
	if (holdKey == true && alive == false) {
		holdKey = false;
		game_map.setMap(y_h1 + 1, y_h2 + 2, 146);
	}
}

void Monster::SkeletonMove() {
	if (x_pos >= animationB && inputType.attack == 0) {
		can_moveR = false;
		can_moveL = true;
	}
	if (x_pos <= animationA && inputType.attack == 0) {
		can_moveL = false;
		can_moveR = true;
	}
	if (can_moveR == true && inputType.attack == 0) {
		SetInputRight();
	}
	else if (can_moveL == true && inputType.attack == 0) {
		SetInputLeft();
	}
}



void Monster::SkeletonMeetPlayer(SDL_Rect player) {
	if (player.x >= animationA && player.x <= animationB && player.y - y_pos < 5 && player.y - y_pos > -5) {
		if (player.x + player.w < x_pos && can_moveR == true) {
			can_moveR = false;
			can_moveL = true;
			SetInputLeft();
		}
		else if (player.x  < x_pos && can_moveL == true){
			if ( x_pos - player.x - player.w <= 0) {
				inputType.attack = 1;
				setInputStop();
			}
		}
		else if (x_pos + width_frame < player.x && can_moveL == true) {
			can_moveR = true;
			can_moveL = false;
			SetInputRight();
		}
		else if (x_pos + width_frame <= player.x && can_moveR == true) {
			if (player.x - x_pos - width_frame <= 5) {
				inputType.attack = 1;
				setInputStop();
			}
		}
	}
}

bool Monster::attackCharater(SDL_Rect charater) {
	if (inputType.attack == 1 && frameAttack == 36) {
		SDL_Rect R_Monster = { x_pos + width_frame, y_pos , width_frame , height_frame };
		if (can_moveL == true) {
			R_Monster.x -= width_frame * 2;
		}
		if (commonFuc::CheckCollision(charater, R_Monster)) {
			return true;
		}
	}
	return false;
}

void Monster::showHP() {
	if (alive == true) {
		SDL_Rect R_skeleton = { x_pos - map_x, y_pos - map_y, 30,4 };
		if (can_moveL == true) {
			R_skeleton.x += 15;
		}
		HP_Monster.setEntity(R_skeleton);
		if (healSkeleton == 0) {
			HP_Monster.setCurrentFrame(R_HP[2]);
		}
		else if (healSkeleton == 1) {
			HP_Monster.setCurrentFrame(R_HP[1]);
		}
		else if (healSkeleton == 2) {
			HP_Monster.setCurrentFrame(R_HP[0]);
		}
		commonFuc::render(HP_Monster);
	}
}