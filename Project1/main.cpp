#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"
#include"Map.h"
#include"Charater.h"
#include"Timer.h"
#include"Monster.h"


std::vector<Monster*> make_Skeleton_list()
{
    std::vector<Monster*> list_threat;
    for (int i = 0; i < 1; i++)
    {
        Monster* p_object = new Monster[1];
        p_object->loadSkeletonImage();
        p_object->SetClips();
        p_object->setX_Pos(625);
        p_object->setY_Pos(140);
        p_object->SetAnimationPos(p_object->getX_Pos() - 70, p_object->getX_Pos() + 70);
        list_threat.push_back(p_object);
    }
    return list_threat;
}



int main(int argc, char* args[])
{
    Timer Fps_Time;
    commonFuc::RenderWindow("Vagabond", SCREEN_WIDTH, SCREEN_HEIGHT);

    Entity background(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, commonFuc::loadTexture("image/background/0.png"));

    gameMap game_map;
    game_map.loadMap("image/map/map6.csv", "image/map/DungeonTileSet.png");
    bool gameRunning = true;

    
    Charater charaterr;

    Monster monster;
    charaterr.loadImage();

    std::vector<Monster*> Monster_list = make_Skeleton_list();

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


        for (int i = 0; i < Monster_list.size(); i++) {
            Monster* p_monster = Monster_list.at(i);
            p_monster->setMapXY(game_map.getMap().startX, game_map.getMap().startY);
            p_monster->doPlayer(game_map);
            p_monster->show();
            SDL_Rect R_monster = { p_monster->getX_Pos(), p_monster->getY_Pos(), p_monster->get_WithFrame(), p_monster->get_HeighFrame()};
            if (charaterr.attacking()) {
                std::cout << "haha" << std::endl;
                if (commonFuc::CheckCollision(R_monster, charaterr.getCharater())) {
                    p_monster->alive = false;
                }
           }
        }

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
