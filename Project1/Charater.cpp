#include"Charater.h"

Charater::Charater()
{
	x_pos = 0;
	y_pos = 0;
	x_val = 0;
	y_val = 0;
	frame = 0;
	status = -1;
	//width_frame = 0;
	//height_frame = 0;
	inputType.right = 0;
	inputType.left = 0;
	inputType.down = 0;
	inputType.jump = 0;
	inputType.up = 0;
	on_ground = false;
	map_x = 0;
	map_y = 0;
};


void Charater::loadImage() {
	SDL_Rect R = { 42,83,45,45 };
	for (int i = 0; i < RunAnimationFrame; i++) {
		std::string s = "image/vagabond/run/vagabond-run" + std::to_string(i + 1) + ".png";
		Entity E(64,128,64,64,commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		RunAnimationRight.push_back(E);
	}
	for (int i = 0; i < RunAnimationFrame; i++) {
		std::string s = "image/vagabond/run/vagabond-run-left" + std::to_string(i + 1) + ".png";
		Entity E(64, 128, 64, 64, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		RunAnimationLeft.push_back(E);
	}

	for (int i = 0; i < idleAnimationFrame; i++) {
		std::string s = "image/vagabond/idle/vagabond-idle" + std::to_string(i + 1) + ".png";
		Entity E(64, 128, 64, 64, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		idleAnimationRight.push_back(E);
	}

	for (int i = 0; i < idleAnimationFrame; i++) {
		std::string s = "image/vagabond/idle/vagabond-idle-left" + std::to_string(i + 1) + ".png";
		Entity E(64, 128, 64, 64, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		idleAnimationLeft.push_back(E);
	}
	for (int i = 0; i < runEndAnimationFrame; i++) {
		std::string s = "image/vagabond/run-end/vagabond-run-end" + std::to_string(i + 1) + ".png";
		Entity E(64, 128, 64, 64, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		runEndAnimationRight.push_back(E);
	}
	for (int i = 0; i < runEndAnimationFrame; i++) {
		std::string s = "image/vagabond/run-end/vagabond-run-end-left" + std::to_string(i + 1) + ".png";
		Entity E(64, 128, 64, 64, commonFuc::loadTexture(s.c_str()));
		E.setCurrentFrame(R);
		runEndAnimationLeft.push_back(E);
	}
};


void Charater::show() {
	//std::cout << x_pos << " " << y_pos << std::endl;
	SDL_Rect dest = { x_pos - map_x ,y_pos - map_y, width_frame, height_frame };
	std::cout << x_pos - map_x << " " << y_pos - map_y << std::endl;
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
	if (status == 1 ) {
		if (inputType.left == 1 && on_ground == true) {
			commonFuc::render(RunAnimationLeft[frame % 8]);
			runing = true;
			frameRunEnd = 0;
		}
		else {
			if (runing) {
				if (frameRunEnd >= 3) {
					runing = false;
				}
				commonFuc::render(runEndAnimationLeft[frameRunEnd]);
				frameRunEnd++;
			}else
			commonFuc::render(idleAnimationLeft[frame % 2]);
		}
	}
	else if(status == 0 ){
		if (inputType.right == 1 && on_ground == true) {
			commonFuc::render(RunAnimationRight[frame % 8]);
			runing = true;
			frameRunEnd = 0;
		}
		else {
			if (runing) {
				if (frameRunEnd >= 3) {
					runing = false;
				}
				commonFuc::render(runEndAnimationRight[frameRunEnd]);
				frameRunEnd++;
			}else
			commonFuc::render(idleAnimationRight[frame % 2]);
		}
	}
	frame++;
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
			on_ground = false;
			inputType.up = 1;
			break;
		case SDLK_DOWN:
			inputType.down = 1;

			break;
		default:
			break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:           // left arrow		
			inputType.right = 0;
			break;
		case SDLK_LEFT:            // right arrow
			inputType.left = 0;
			break;
		case SDLK_SPACE:            
			inputType.up = 0;
			break;
		case SDLK_DOWN:            
			inputType.down = 0;
			break;
		default:
			break;
		}
	}
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
	if (inputType.up == 1) {
		y_val = -(player_speed + maxGravity_speed);
		//std::cout << maxGravity_speed << std::endl;
	}
	else if(inputType.down == 1) {
		y_val += player_speed;
	}
	checkToMap(game_map);
	centerEntityOnMap(game_map);
}

void Charater::checkToMap(gameMap& game_map) {
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	int heightMin = height_frame < TILE_SIZE ? height_frame : TILE_SIZE;
	int widthMin = width_frame < TILE_SIZE ? width_frame : TILE_SIZE;

	// Kiểm tra va chạm theo chiều ngang
	x1 = (x_pos + x_val) / TILE_SIZE;
	x2 = (x_pos + x_val + width_frame) / TILE_SIZE;
	y1 = (y_pos + 1) / TILE_SIZE;
	y2 = (y_pos + heightMin - 1) / TILE_SIZE;
	if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y) {
		if (x_val > 0) {
			if (game_map.getMap().tile[y1][x2] != -1 || game_map.getMap().tile[y2][x2] != -1) {
				x_pos = x2 * TILE_SIZE - width_frame - 1;
				x_val = 0;
			}
		}
		else if (x_val < 0) {
			if (game_map.getMap().tile[y1][x1] != -1 || game_map.getMap().tile[y2][x1] != -1) {
				x_pos = (x1 + 1) * TILE_SIZE;
				x_val = 0;
			}
		}
	}

	// Kiểm tra va chạm theo chiều dọc
	x1 = x_pos / TILE_SIZE;
	x2 = (x_pos + widthMin) / TILE_SIZE;	
	y1 = (y_pos + y_val) / TILE_SIZE;
	y2 = (y_pos + y_val + height_frame - 1) / TILE_SIZE;
	if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y) {
		if (y_val > 0) {
			if (game_map.getMap().tile[y2][x1] != -1 || game_map.getMap().tile[y2][x2] != -1) {
				y_pos = y2 * TILE_SIZE - height_frame - 1;
				y_val = 0;
				on_ground = true;
			}
		}
		else if (y_val < 0) {
			if (game_map.getMap().tile[y1][x1] != -1 || game_map.getMap().tile[y1][x2] != -1) {
				y_pos = (y1 + 1) * TILE_SIZE;
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
	game_map.getStartY(startY_);
	if (startY_ < 0) {
		game_map.getStartY(0);
	}
	else if (startY_ + SCREEN_HEIGHT >= game_map.getMap().maxY) {
		game_map.getStartY(game_map.getMap().maxY - SCREEN_HEIGHT);
	}
	//std::cout << game_map.getMap().maxX << " " << game_map.getMap().maxY << std::endl;

}

