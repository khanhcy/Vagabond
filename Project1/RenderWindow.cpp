
#include "RenderWindow.h"


void commonFuc::RenderWindow(const char* p_title, int p_w, int p_h)

{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

}

SDL_Texture* commonFuc::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(p_filePath);

	if (loadedSurface == NULL) {
		std::cout << "Failed to load surface. Error: " << SDL_GetError() << std::endl;
	}
	else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == NULL) {

			std::cout << "Failed toCreateTextur. Error: " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(loadedSurface);
	}
	return texture;
}

void commonFuc::cleanUp()
{
	SDL_DestroyWindow(window);
}

void commonFuc::clear()
{
	SDL_RenderClear(renderer);
}

void commonFuc::render(Entity& p_entity)
{	
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;
	SDL_Rect dst;
	dst.x = p_entity.getX();
	dst.y = p_entity.getY();
	dst.w = p_entity.getW();
	dst.h = p_entity.getH();

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

//void commonFuc::render(Charator& p_charator)
//{
//	SDL_Rect src;
//	src.x = p_charator.getCurrentFrame().x;
//	src.y = p_charator.getCurrentFrame().y;
//	src.w = p_charator.getCurrentFrame().w;
//	src.h = p_charator.getCurrentFrame().h;
//	SDL_Rect dst;
//	dst.x = p_charator.getX();
//	dst.y = p_charator.getY();
//	dst.w = p_charator.getW();
//	dst.h = p_charator.getH();
//
//	SDL_RenderCopy(renderer, p_charator.getTex(), &src, &dst);
//}

void commonFuc::render(SDL_Texture* tex, SDL_Rect *src, SDL_Rect dst, double angle, SDL_Point* center , SDL_RendererFlip flip) {

	SDL_RenderCopyEx(renderer, tex, src, &dst, angle, center, flip);
}

void commonFuc::render(SDL_Texture* tex, SDL_Rect *src, SDL_Rect dst) {

    //SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
    //SDL_RenderDrawRect(renderer, src);
    SDL_RenderCopy(renderer, tex, src, &dst);
}

void commonFuc::display()
{
	SDL_RenderPresent(renderer);
}

SDL_Rect commonFuc::getTileSet(int id) {
	int x = 0; int y = 0;
	y = id / 15;
	x = id - y * 15;
	SDL_Rect scr = { x * 16,y * 16 ,16,16 };
	return scr;
}


bool commonFuc::check_wall(int n) {
	for (int i = 0; i < sizeof Map_wall; i++) {
		if (n == Map_wall[i]) {
			return true;
		}
	}
	return false;
}



//bool commonFuc::check_thorn(int n) {
//	for (int i = 0; i < sizeof(Map_thorn); i++) {
//		if (n == Map_thorn[i]) {
//			return true;
//		}
//	}
//	return false;
//}
bool commonFuc::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2) {
    // Kiểm tra va chạm giữa hai hình chữ nhật bằng cách kiểm tra xem chúng có chồng lên nhau không
    if (object1.x + object1.w <= object2.x) {
        return false;
    }
    if (object2.x + object2.w <= object1.x) {
        return false;
    }
    if (object1.y + object1.h <= object2.y) {
        return false;
    }
    if (object2.y + object2.h <= object1.y) {
        return false;
    }
    return true;
}


