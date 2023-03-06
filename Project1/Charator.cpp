//#include"Charator.h"
//
//Charator::Charator()
//{
//	x_val = 0;
//	y_val = 0;
//	x_pos = 0;
//	y_pos = 0;
//	frame = 0;
//	status = -1;
//	width_frame = 0;
//	height_frame = 0;
//	inputType.right = 0;
//	inputType.left = 0;
//	inputType.down = 0;
//	inputType.jump = 0;
//	inputType.up = 0;
//}
//
//
//Charator::Charator(SDL_Texture* p_tex){
//	tex = p_tex;
//	width_frame = currentFrame.w / 8;
//	height_frame = currentFrame.h;
//}
//
//
//void Charator::setClips() {
//	for (int i = 0; i < WALKING_ANIMATION_FRAMES; i++)
//	{
//		FrameClips[i] = { i * width_frame, 0,width_frame, height_frame};
//	}
//}
//
//void Charator::show() {
//	if (inputType.left == 1 || inputType.right == 1)
//	{
//		frame++;
//	}
//	else
//	{
//		frame = 0;
//	}
//	if(frame >= 8)
//	{
//		frame = 0;
//	}
//	x = x_pos;
//	y = y_pos;
//
//	currentFrame = FrameClips[frame];
//	
//	SDL_Rect renderQuad = { x, y, width_frame, height_frame };
//
//	SDL_RenderCopy(renderer, tex, &currentFrame, &renderQuad);
//
//}
//
//void Charator::HandleInputAction(SDL_Event e) {
//	if (e.type == SDL_KEYDOWN)
//	{
//		switch (e.key.keysym.sym)
//		{
//			case SDLK_RIGHT:           // left arrow
//				status = Walk_right;
//				inputType.right = 1;
//				inputType.left = 0;
//				break;
//			case SDLK_LEFT:            // right arrow
//				status = Walk_left;
//				inputType.left = 1;
//				inputType.right = 0;
//				break;
//		}
//	}
//}
