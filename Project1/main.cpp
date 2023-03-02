#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"

void loadmap(const char* name, RenderWindow& window) {
    int map_title[10][400];
    std::vector<Entity> map;
    Entity map1(window.loadTexture("image/map/0.png"));
    map.push_back(map1);
    Entity map2(window.loadTexture("image/map/2.png"));
    map.push_back(map2);
    Entity map3(window.loadTexture("image/map/3.png"));
    map.push_back(map3);
    Entity map4(window.loadTexture("image/map/4.png"));
    map.push_back(map4);
    Entity map5(window.loadTexture("image/map/5.png"));
    map.push_back(map5);

    std::ifstream file_name("image/map/map01.dat");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 400; j++) {
            file_name >> map_title[i][j];
        }
    }
    int type = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 400; j++) {
            type = map_title[i][j];
            if (type > 0) {
                if (type == 0) {
                    map[0].setEntity(32 * j,320 + 32 * i, 32, 32);
                    window.render(map[0]);
                }
                if (type == 2) {
                    map[1].setEntity(32 * j, 320 + 32 * i, 32, 32);
                    window.render(map[1]);
                }
                if (type == 3) {
                    map[2].setEntity(32 * j, 320 + 32 * i, 32, 32);
                    window.render(map[2]);
                }
                if (type == 4) {
                    map[3].setEntity(32 * j, 320 + 32 * i, 32, 32);
                    window.render(map[3]);
                }
                if (type == 5) {
                    map[4].setEntity(32 * j, 320 + 32 * i, 32, 32);
                    window.render(map[4]);
                }
            }
        }
    }
}
void Charator(const char* path, RenderWindow& window, int& frame) 
{
    const int WALKING_ANIMATION_FRAMES = 8;
    Entity CharatorRun(window.loadTexture(path));
    SDL_Rect SpriteClips[WALKING_ANIMATION_FRAMES];
    for (int i = 0; i < WALKING_ANIMATION_FRAMES; i++) {
        SpriteClips[i] = { i * 80, 0, 80, 80 };
    } 
    SDL_Rect currentClip = SpriteClips[frame / 8];
    CharatorRun.setCurrentFrame(currentClip);
    CharatorRun.setEntity((SCREEN_WIDTH - currentClip.w) / 2, (SCREEN_HIGH - currentClip.h) / 2, 80, 80);
    window.render(CharatorRun);
    frame++;
    if (frame / 8 >= WALKING_ANIMATION_FRAMES)
    {
        frame = 0;
    }
    window.display();
}

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window("GAME", SCREEN_WIDTH, SCREEN_HIGH);
    std::vector<Entity> map;
    Entity background(0, 0, SCREEN_WIDTH, SCREEN_HIGH, window.loadTexture("image/background/Background.png"));

    bool gameRunning = true;

    SDL_Event event;
    int frame = 0;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
    	SDL_SetRenderDrawColor(window.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
        window.clear();
        window.render(background);
        loadmap("image/map/map01.dat", window);
        Charator("image/Character/Run/Run-Sheet.png", window, frame);
        window.display();
    }
    window.cleanUp();
    SDL_Quit();
    return 0;

}
