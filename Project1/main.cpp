#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"



int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window("GAME", SCREEN_WIDTH, SCREEN_HIGH / 2);
    Entity map1(window.loadTexture("image/map/0.png"));
    Entity map2(window.loadTexture("image/map/2.png"));
    Entity map3(window.loadTexture("image/map/3.png"));
    Entity map4(window.loadTexture("image/map/4.png"));
    Entity map5(window.loadTexture("image/map/5.png"));


    int map_title[10][400];
    std::ifstream file_name("image/map/map01.dat");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 400; j++) {
            file_name >> map_title[i][j];
        }
    }

    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
    	SDL_SetRenderDrawColor(window.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
        window.clear();
        int type = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 400; j++) {
                type = map_title[i][j];
                if (true) {
                    if (type == 0) {
                        map1.setEntity(32 * j, 32 * i, 32, 32);
                        window.render(map1);
                    }
                    if (type == 2) {
                        map2.setEntity(32 * j, 32 * i, 32, 32);
                        window.render(map2);
                    }
                    if (type == 3) {
                        map3.setEntity(32 * j, 32 * i, 32, 32);
                        window.render(map3);
                    }
                    if (type == 4) {
                        map4.setEntity(32 * j, 32 * i, 32, 32);
                        window.render(map4);
                    }
                    if (type == 5) {
                        map5.setEntity(32 * j, 32 * i, 32, 32);
                        window.render(map5);
                    }
                    
                }
            }
        }
        window.display();
    }
    window.cleanUp();
    SDL_Quit();
    return 0;

}
