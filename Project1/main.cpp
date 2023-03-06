#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"
#include"Map.h"

void Charator(const char* path, int& frame) 
{
    const int WALKING_ANIMATION_FRAMES = 8;
    Entity CharatorRun(commonFuc::loadTexture(path));
    SDL_Rect SpriteClips[WALKING_ANIMATION_FRAMES];
    for (int i = 0; i < WALKING_ANIMATION_FRAMES; i++) {
        SpriteClips[i] = { i * 80, 0, 80, 80 };
    }
    SDL_Rect currentClip = SpriteClips[frame / 8];
    CharatorRun.setCurrentFrame(currentClip);
    CharatorRun.setEntity((SCREEN_WIDTH - currentClip.w) / 2, (SCREEN_HEIGHT - currentClip.h) / 2, 200, 200);
    commonFuc::render(CharatorRun);
    frame++;
    if (frame / 8 >= WALKING_ANIMATION_FRAMES)
    {
        frame = 0;
    }
    commonFuc::display();
}

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    commonFuc::RenderWindow("GAME", SCREEN_WIDTH, SCREEN_HEIGHT);

    Entity background(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, commonFuc::loadTexture("image/background/Background.png"));

    gameMap game_map;
    game_map.loadMap("image/map/map1.csv", "image/map/DungeonTileSet.png");
    bool gameRunning = true;

    SDL_Event event;
    //int frame = 0;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
    	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        commonFuc::clear();
        commonFuc::render(background);
             game_map.drawMap();
        //Charator("image/Character/Run/Run-Sheet.png", frame);
        commonFuc::display();
    }
    commonFuc::cleanUp();
    SDL_Quit();
    return 0;

}
