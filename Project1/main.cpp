#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"
#include"Map.h"
#include"Charater.h"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    commonFuc::RenderWindow("GAME", SCREEN_WIDTH, SCREEN_HEIGHT);

    Entity background(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, commonFuc::loadTexture("image/background/Background.png"));

    gameMap game_map;
    game_map.loadMap("image/map/test1.csv", "image/map/DungeonTileSet.png");
    bool gameRunning = true;


    Charater charaterr;
    //charaterr.setClips();
    charaterr.loadImage();
    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
            charaterr.HandleInputAction(event);
        }
    	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        commonFuc::clear();
        commonFuc::render(background);
        game_map.drawMap();
        charaterr.doPlayer();
        charaterr.show();
        commonFuc::display();
    }
    commonFuc::cleanUp();
    SDL_Quit();
    return 0;

}
