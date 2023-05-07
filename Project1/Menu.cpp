#include"Menu.h"



void Menu::runMenu(Entity play, Entity quit, Entity tutorial, SDL_Event& e
    , bool& gameRunning, bool& runningMenu, bool& gametutorial)
{

    // Xử lý sự kiện
    while (SDL_PollEvent(&e)) {
        // Nhấp chuột
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            // Kiểm tra xem chuột có trên nút Play không
            if (e.button.x >= play.getX() && e.button.x <= play.getX() + play.getW()
                && e.button.y >= play.getY() && e.button.y <= play.getY() + play.getH()) {
                std::cout << "Play button clicked!" << std::endl;
                gameRunning = true;
                runningMenu = false;
            }
            else if (e.button.x >= quit.getX() && e.button.x <= quit.getX() + quit.getW()
                && e.button.y >= quit.getY() && e.button.y <= quit.getY() + quit.getH()) {
                gameRunning = false;
                runningMenu = false;
            }
            else if (e.button.x >= tutorial.getX() && e.button.x <= tutorial.getX() + tutorial.getW()
                && e.button.y >= tutorial.getY() && e.button.y <= tutorial.getY() + tutorial.getH()) {
                gametutorial = true;
            }

        }
        // Sự kiện thoát khỏi cửa sổ
        else if (e.type == SDL_QUIT) {
            gameRunning = false;
            runningMenu = false;

        }
    }
    

    // Xóa màn hình
    //SDL_RenderClear(window.renderer);

    // Vẽ các nút lên màn hình
    SDL_Rect dest = { 0,0,840,480 };
 
    commonFuc::render(menu_pic, NULL, dest);
    commonFuc::render(play);
    commonFuc::render(tutorial);
    commonFuc::render(quit);
    commonFuc::display(); 
}