#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"
#include"Map.h"
#include"Charater.h"
#include"Timer.h"


int main(int argc, char* args[])
{
    Timer Fps_Time;
    commonFuc::RenderWindow("GAME", SCREEN_WIDTH, SCREEN_HEIGHT);

    Entity background(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, commonFuc::loadTexture("image/background/Background.png"));
    gameMap game_map;
    game_map.loadMap("image/map/test4.csv", "image/map/DungeonTileSet.png");
    bool gameRunning = true;


    Charater charaterr;
    //charaterr.setClips();
    charaterr.loadImage();
    SDL_Event event;

    while (gameRunning)
    {
        Fps_Time.start();
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
            charaterr.HandleInputAction(event);
        }
    	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        commonFuc::clear();
        commonFuc::render(background);
        charaterr.setMapXY(game_map.getMap().startX, game_map.getMap().startY);
        charaterr.doPlayer(game_map);
        charaterr.show();
        game_map.drawMap();
        commonFuc::display();

        int real_Time = Fps_Time.GetTicks();
        int time_oneFrame = 1000 / FPS;
        if (real_Time < time_oneFrame) {
            int delay_time = time_oneFrame - real_Time;
            if (delay_time >= 0) {
                SDL_Delay(delay_time);
            }
        }
    }
    commonFuc::cleanUp();
    SDL_Quit();
    return 0;

}
