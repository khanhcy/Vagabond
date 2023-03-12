#include"Charater.h"

Charater::Charater()
{
	frame = 0;
	status = -1;
	//width_frame = 0;
	//height_frame = 0;
	inputType.right = 0;
	inputType.left = 0;
	inputType.down = 0;
	inputType.jump = 0;
	inputType.up = 0;
};


void Charater::loadImage() {
	for (int i = 0; i < RunAnimationFrame; i++) {
		std::string s = "image/vagabond/run/vagabond-run" + std::to_string(i + 1) + ".png";
		Entity E(0,0,120,120,commonFuc::loadTexture(s.c_str()));
		RunAnimationRight.push_back(E);
	}
	for (int i = 0; i < RunAnimationFrame; i++) {
		std::string s = "image/vagabond/run/vagabond-run-left" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 120, 120, commonFuc::loadTexture(s.c_str()));
		RunAnimationLeft.push_back(E);
	}

	for (int i = 0; i < idleAnimationFrame; i++) {
		std::string s = "image/vagabond/idle/vagabond-idle" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 120, 120, commonFuc::loadTexture(s.c_str()));
		idleAnimationRight.push_back(E);
	}

	for (int i = 0; i < idleAnimationFrame; i++) {
		std::string s = "image/vagabond/idle/vagabond-idle-left" + std::to_string(i + 1) + ".png";
		Entity E(0, 0, 120, 120, commonFuc::loadTexture(s.c_str()));
		idleAnimationLeft.push_back(E);
	}
};


void Charater::show() {
	SDL_Rect dest = { x_pos,y_pos,width_frame,height_frame };
	if (inputType.left == 1 || inputType.right == 1)
	{
		if (status == 1)
		{
			commonFuc::render(RunAnimationLeft[frame]);
		}
		else
		{
			commonFuc::render(RunAnimationRight[frame]);
		}
		frame++;
		if (frame >= 8)
		{
			frame = 0;
		}
		for (int i = 0; i < RunAnimationFrame; i++) {
			RunAnimationRight[i].setEntity(dest);
			RunAnimationLeft[i].setEntity(dest);
		}

	}
	else
	{
		if (frame >= 2) {
			frame = 0;
		}
		for (int i = 0; i < idleAnimationFrame; i++) {
			idleAnimationLeft[i].setEntity(dest);
			idleAnimationRight[i].setEntity(dest);

		}
		if (status == 1)
		{
			commonFuc::render(idleAnimationLeft[frame]);
		}
		else
		{
			commonFuc::render(idleAnimationRight[frame]);
		}
		frame++;		
	}
}


void Charater::HandleInputAction(SDL_Event e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:           
			status = Walk_right;
			inputType.right = 1;
			inputType.left = 0;
			break;
		case SDLK_LEFT:            
			status = Walk_left;
			inputType.left = 1;
			inputType.right = 0;
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
		default:
			break;
		}
	}
}

void Charater::doPlayer(/*map& gamemap*/) {
	/*x = 0;*/
	if (y_pos > maxGravity_speed) {
		gravity_speed = maxGravity_speed;
	}
	if (inputType.left == 1) {
		x_pos -= player_speed;
	}
	else if (inputType.right == 1) {
		x_pos += player_speed;
	}
	if (inputType.up == 1) {
		y_pos -= player_speed;
	}
	else if (inputType.down == 1) {
		y_pos += player_speed;
	}
}

//void Charater::checkToMap(map& gamemap) {
//	int x1 = 0;
//	int y1 = 0;
//
//	int x2 = 0;
//	int y2 = 0;
//
//
//}

