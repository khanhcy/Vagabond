//#pragma once
//#include"commonFuncion.h"
//#include"Entity.h"
//
//class Charator :public Entity {
//public:
//	enum Walk_type
//	{
//		Walk_right = 0,
//		Walk_left = 1,
//	};
//	Charator();
//	Charator(SDL_Texture* p_tex);
//	~Charator();
//	void setClips();
//	void show();
//	void HandleInputAction(SDL_Event e);
//
//private:
//
//	// di chuyển tăng lên bao nhiêu;
//	int x_val;
//	int y_val;
//
//	// vị trí hiện tại
//	float x_pos;
//	float y_pos;
//
//	// kích thước từng frame;
//	int width_frame;
//	int height_frame;
//
//	int frame;
//	int status;
//	SDL_Rect FrameClips[WALKING_ANIMATION_FRAMES];
//
//	Input inputType;
//
//};