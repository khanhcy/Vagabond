#include"Charater.h"

Charater::Charater()
{
	x_pos = 200;
	y_pos = 100;
	x_val = 0;
	y_val = 0;
	frame = 0;
	status = -1;
	//width_frame = 0;
	//height_frame = 0;
	inputType.right = 0;
	inputType.left = 0;
	inputType.jump = 0;
	on_ground = false;
	on_block = false;
	dashing = true;
	deading = false;
	map_x = 0;
	map_y = 0;


	frameJump = 0;
	frameRunEnd = 0;
	frameDash = 0;

	centermap = true;

	dashTime = 0;
};


void Charater::loadImage() {
	SDL_Rect R = { 42,83,45,45 };
	R = { 42,83,45,45 };
	for (int i = 0; i < RunAnimationFrame; i++) {
		std::string s = "image/vagabond/run/vagabond-run" + std::to_string(i + 1) + ".png";
		Entity E(0,0,128,128,commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		RunAnimationRight.push_back(E);
	}
	for (int i = 0; i < RunAnimationFrame; i++) {
		std::string s = "image/vagabond/run/vagabond-run-left" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		RunAnimationLeft.push_back(E);
	}

	for (int i = 0; i < idleAnimationFrame; i++) {
		std::string s = "image/vagabond/idle/vagabond-idle" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		idleAnimationRight.push_back(E);
	}

	for (int i = 0; i < idleAnimationFrame; i++) {
		std::string s = "image/vagabond/idle/vagabond-idle-left" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		idleAnimationLeft.push_back(E);
	}
	for (int i = 0; i < runEndAnimationFrame; i++) {
		std::string s = "image/vagabond/run-end/vagabond-run-end" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		runEndAnimationRight.push_back(E);
	}
	for (int i = 0; i < runEndAnimationFrame; i++) {
		std::string s = "image/vagabond/run-end/vagabond-run-end-left" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		runEndAnimationLeft.push_back(E);
	}
	for (int i = 0; i < jumpAnimationFrame; i++) {
		std::string s = "image/vagabond/jump/vagabond-jump" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		R.y = 42;
		E.setCurrentFrame(R);
		jumpAnimationRight.push_back(E);
	}
	for (int i = 0; i < jumpAnimationFrame; i++) {
		std::string s = "image/vagabond/jump/vagabond-jump-left" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		R.y = 42;
		E.setCurrentFrame(R);
		jumpAnimationLeft.push_back(E);
	}
	R = { 21,40,23,23 };
	for (int i = 0; i < dashAnimationFrame; i++) {
		std::string s = "image/vagabond/dash/vagabond-dash" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		dashAnimationRight.push_back(E);
	}
	for (int i = 0; i < dashAnimationFrame; i++) {
		std::string s = "image/vagabond/dash/vagabond-dash-left" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		dashAnimationLeft.push_back(E);
	}
	R = { 42,83,45,45 };
	for (int i = 0; i < deadAnimationFrame; i++) {
		std::string s = "image/vagabond/death/vagabond-death" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		deadAnimationRight.push_back(E);
	}
	for (int i = 0; i < deadAnimationFrame; i++) {
		std::string s = "image/vagabond/death/vagabond-death-left" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		deadAnimationLeft.push_back(E);
	}
	for (int i = 0; i < deadAnimationFrame; i++) {
		std::string s = "image/vagabond/death/vagabond-death" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		deadAnimationRight.push_back(E);
	}
	for (int i = 0; i < deadAnimationFrame; i++) {
		std::string s = "image/vagabond/death/vagabond-death-left" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		deadAnimationLeft.push_back(E);
	}
	R = { 26,83,140,70 };
	for (int i = 0; i < attackAnimationFrame; i++) {
		std::string s = "image/vagabond/attack/vagabond-attack" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		attackAnimationRight.push_back(E);
	}
	R = { 92,83,140,70 };
	for (int i = 0; i < attackAnimationFrame; i++) {
		std::string s = "image/vagabond/attack/vagabond-attack-left (" + std::to_string(i + 1) + ").png";
		Entity E(0, 0, 128, 128, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		attackAnimationLeft.push_back(E);
	}

};


void Charater::show() {
	SDL_Rect dest = { x_pos - map_x ,y_pos - map_y, width_frame, height_frame };
	for (int i = 0; i < RunAnimationFrame; i++) {
		RunAnimationRight[i].setEntity(dest);
		RunAnimationLeft[i].setEntity(dest);
	}
	for (int i = 0; i < idleAnimationFrame; i++) {
		idleAnimationLeft[i].setEntity(dest);
		idleAnimationRight[i].setEntity(dest);

	}
	for (int i = 0; i < runEndAnimationFrame; i++) {
		runEndAnimationLeft[i].setEntity(dest);
		runEndAnimationRight[i].setEntity(dest);
	}

	for (int i = 0; i < jumpAnimationFrame; i++) {
		jumpAnimationLeft[i].setEntity(dest);
		jumpAnimationRight[i].setEntity(dest);
	}
	
	for (int i = 0; i < dashAnimationFrame; i++) {
		dashAnimationLeft[i].setEntity(dest);
		dashAnimationRight[i].setEntity(dest);

	}
	for (int i = 0; i < deadAnimationFrame; i++) {
		deadAnimationLeft[i].setEntity(dest);
		deadAnimationRight[i].setEntity(dest);

	}
	for (int i = 0; i < attackAnimationFrame; i++) {
		dest.w = 140;
		dest.h = height_frame;
		attackAnimationRight[i].setEntity(dest);

	}
	dest.x -= 89;
	for (int i = 0; i < attackAnimationFrame; i++) {
		dest.w = 140;
		dest.h = height_frame;
		attackAnimationLeft[i].setEntity(dest);

	}

	animationRun();
	animationJump();
	animationDash();
	animationDead();
	animationAttack();
}

void Charater::animationRun() {
	if (status == 1 && deading == false && inputType.attack == 0) {
		if (on_ground == true && inputType.dash == 0) {
			if (inputType.left == 1) {
				commonFuc::render(RunAnimationLeft[(frame / 8) % 8]);
				runing = true;
				frameRunEnd = 0;
			}
			else {
				if (runing) {
					if (frameRunEnd >= 15) {
						runing = false;
					}
					commonFuc::render(runEndAnimationLeft[(frameRunEnd / 5) % 3]);
					frameRunEnd++;
					frame = 0;
				}
				else {
					commonFuc::render(idleAnimationLeft[(frame / 10) % 2]);
					
				}
			}
		}
	}
	else if (status == 0 && deading == false && inputType.attack == 0) {
		if (on_ground == true && inputType.dash == 0) {
			if (inputType.right == 1) {
				commonFuc::render(RunAnimationRight[(frame / 8) % 8]);
				runing = true;
				frameRunEnd = 0;

			}
			else {
				if (runing) {
					if (frameRunEnd >= 15) {
						runing = false;
					}
					commonFuc::render(runEndAnimationRight[(frameRunEnd / 5) % 3]);
					frameRunEnd++;
					frame = 0;
				}
				else {
						commonFuc::render(idleAnimationRight[(frame / 10) % 2]);
					
				}
			}
		}
	}
	frame++;
}

void Charater::animationJump() {
	if (status == 1) {
		if (inputType.jump == 1 && inputType.dash == 0 && inputType.attack == 0) {
			commonFuc::render(jumpAnimationLeft[frameJump / 20]);
		}
		if (on_ground == false && inputType.jump == 0 && inputType.dash == 0 && inputType.attack == 0) {
			commonFuc::render(jumpAnimationLeft[2]);
		}
	}
	else {
		if (inputType.jump == 1 && inputType.dash == 0 && inputType.attack == 0) {
			commonFuc::render(jumpAnimationRight[frameJump / 20]);
		}
		if (on_ground == false && inputType.jump == 0 && inputType.dash == 0 && inputType.attack == 0) {
			commonFuc::render(jumpAnimationRight[2]);
		}
	}
	frameJump++;
	if (frameJump / 20 >= 3) {
		frameJump = 20;
	}
}


void Charater::HandleInputAction(SDL_Event e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:           
			status = run_right;
			inputType.right = 1;
			inputType.left = 0;
			break;
		case SDLK_LEFT:            
			status = run_left;
			inputType.left = 1;
			inputType.right = 0;
			break;
		case SDLK_SPACE:
			if (on_ground == true) {
				on_ground = false;
				jumping = true;
				jumpStartTime = SDL_GetTicks();
				inputType.jump = 1;
			}
			break;
		case SDLK_e:
			if (dashing) {
				dashTime = SDL_GetTicks();
				inputType.dash = 1;
				dashing = false;
			}
			break;
		case SDLK_a:
			inputType.attack = 1;
			break;
		default:
			break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:           
			inputType.right = 0;
			break;
		case SDLK_LEFT:	
			inputType.left = 0;
			break;
		case SDLK_SPACE :
			jump_duration = SDL_GetTicks() - jumpStartTime;
			//std::cout << jump_duration << std::endl;
			break;
		default:
			break;
		}
	}
}

void Charater::animationDash() {
	if (status == run_left) {
		if (inputType.dash == 1) {
			commonFuc::render(dashAnimationLeft[1]);
		}
	}
	else if (status == run_right) {
		if (inputType.dash == 1) {
			commonFuc::render(dashAnimationRight[1]);
		}
		
	}
}

void Charater::animationAttack() {
	if (status == run_left) {
		if (inputType.attack == 1) {
			jumping = false;
			inputType.jump = 0;
			inputType.dash = 0;
			inputType.idle = 0;
			commonFuc::render(attackAnimationLeft[frameAttack / 10]);
			frameAttack++;
			if (frameAttack / 10 >= 4) {
				frameAttack = 0;
				inputType.attack = 0;
			}
		}
	}
	else if (status == run_right) {
		if (inputType.attack == 1) {
			jumping = false;
			inputType.jump = 0;
			inputType.dash = 0;
			inputType.idle = 0;
			commonFuc::render(attackAnimationRight[frameAttack / 10]);
			frameAttack++;
			if (frameAttack / 10 >= 4) {
				frameAttack = 0;
				inputType.attack = 0;
			}
		}

	}
}

void Charater::animationDead() {
	if (deading) {
		x_val = 0;
		y_val = 0;
		jumping = false;
		inputType.left = 0;
		inputType.right = 0;
		inputType.jump = 0;
		inputType.dash = 0;
		inputType.idle = 0;
		if (status == run_left) {
			commonFuc::render(deadAnimationLeft[frameDead / 10]);
			frameDead++;
			if (frameDead / 10 >= 7) {
				frameDead = 0;
				deading = false;
				x_pos = 100;
				y_pos = 100;
			}
		}
		else if (status == run_right) {
			commonFuc::render(deadAnimationRight[frameDead / 10]);
			frameDead++;
			if (frameDead / 10 >= 7) {
				frameDead = 0;
				deading = false;
				x_pos = 100;
				y_pos = 100;
			}
		}
	}
}

bool check_step(int n) {
	for (int i = 0; i < sizeof(Map_step); i++) {
		if (n == Map_step[i]) {
			return true;

		}
	}
	return false;
}

void Charater::doPlayer(gameMap& game_map) {
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

	if (inputType.dash == 1) {
		// Tính toán vận tốc ngang tương ứng với dash
		if (status == run_left) {
			x_val = -dash_speed;
		}
		else if (status == run_right) {
			x_val = dash_speed;
		}
	}
	if (SDL_GetTicks() - dashTime >= 200) {
		dashing = true;
		inputType.dash = 0;
		frameDash = 0;
	}

	if (jumping == 1) {
		Uint32 jumpTime = SDL_GetTicks() - jumpStartTime;
		if (on_block) {
			y_val += 2;
		}
		else {
			if (jump_duration <= 200) { // Giữ phím nhảy trong thời gian ngắn (200ms)
				y_val = 3 * jump_speed * jumpTime / 1000 - jump_speed; // Nhảy thấp
			}
			else { // Giữ phím nhảy trong thời gian dài
				y_val = 2 * jump_speed * jumpTime / 1000 - jump_speed;
			}
			//std::cout << jump_duration << std::endl;
		}

	}
	checkToMap(game_map);
	//if (checkMap(game_map) == 1) {
	//	if (x_val > 0 && step_top == 1) {
	//		x_pos += 2;
	//		y_pos -= 10;
	//	}
	//	else if (x_val > 0 && step_top == 0) {
	//		x_pos += 2;
	//	}
	//	else if (x_val < 0 && step_top == 1) {
	//		x_pos -= 2;
	//	}
	//	else {
	//		x_pos -= 2;
	//		y_pos -= 10;
	//	}
	//	//x_val = 0;
	//	y_val = 0;
	//}
	if (checkMap(game_map)) {
		deading = true;
	}
	centerEntityOnMap(game_map);

}


void Charater::checkToMap(gameMap& game_map) {

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

	int val_h1 = game_map.getMap().tile[y_h1][x_h2];
	int val_h2 = game_map.getMap().tile[y_h2][x_h2];
	int val_v1 = game_map.getMap().tile[y_v2][x_v1];
	int val_v2 = game_map.getMap().tile[y_v2][x_v2];

	// Kiểm tra va chạm theo chiều ngang
	if (x_h1 >= 0 && x_h2 < MAX_MAP_X && y_h1 >= 0 && y_h2 < MAX_MAP_Y) {
		if (x_val > 0) {
			if (commonFuc::check_wall(val_h1) == 1 || commonFuc::check_wall(val_h2) == 1) {
				x_pos = x_h2 * TILE_SIZE - width_frame - 1;
				x_val = 0;
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
			if (commonFuc::check_wall(val_v1) == 1 || commonFuc::check_wall(val_v2) == 1) {
				y_pos = y_v2 * TILE_SIZE - height_frame - 1;
				y_val = 0;
				on_ground = true;
				jumping = false;
				inputType.jump = 0;
				frameJump = 0;
				on_block = false;
			}else if (commonFuc::check_wall(val_v1) != 1 || commonFuc::check_wall(val_v2) != 1) {
				on_ground = false;
			}
		}
		else if (y_val < 0) {
			if (commonFuc::check_wall(game_map.getMap().tile[y_v1][x_v1]) == 1 || commonFuc::check_wall(game_map.getMap().tile[y_v1][x_v2]) == 1) {
				y_pos = (y_v1 + 1) * TILE_SIZE;
				y_val = 0;
				on_block = true;
			}
		}
	}
	if (x_pos + x_val > 0) {
		x_pos += x_val;
	}
	y_pos += y_val;
}

bool Charater::checkMap(gameMap& game_map)
{
	// Calculate the position of the character on the TileMap
	int leftTile = (x_pos) / TILE_SIZE;
	int rightTile = (x_pos + width_frame + 20) / TILE_SIZE;
	int topTile = (y_pos) / TILE_SIZE;
	int bottomTile = (y_pos + height_frame + 20) / TILE_SIZE;
	//std::cout << leftTile << " " << rightTile << " " << topTile << " " << bottomTile << std::endl;
	// check if charactes has collide with a tileset on TileMap
	for (int i = topTile; i < bottomTile; i++) {
		for (int j = leftTile; j < rightTile; j++) {
			if (commonFuc::check_thorn(game_map.getMap().tile[i][j]) == 1)
			{
				return true;
			}
			
		}
	}
	return false;
}

void Charater::centerEntityOnMap(gameMap& game_map) {
	int startX_ = x_pos - (SCREEN_WIDTH / 2);
	game_map.getStartX(startX_);
	if (startX_ < 0) {
		game_map.getStartX(0);
	}
	else if (startX_ + SCREEN_WIDTH >= game_map.getMap().maxX) {
		game_map.getStartX(game_map.getMap().maxX - SCREEN_WIDTH);
	}
	int startY_ = y_pos - (SCREEN_HEIGHT / 2);
	if (abs(his - y_pos) > 154) {
		his = y_pos;
		game_map.getStartY(startY_);

	}
	if (startY_ < 0) {
		game_map.getStartY(0);
	}
	else if (startY_ + SCREEN_HEIGHT >= game_map.getMap().maxY) {
		game_map.getStartY(game_map.getMap().maxY - SCREEN_HEIGHT);

	}

}

