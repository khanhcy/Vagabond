#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"
#include"Map.h"
#include"Charater.h"
#include"Timer.h"
#include"Monster.h"


std::vector<Monster*> make_Skeleton_list()
{
    std::vector<Monster*> list_skeleton;
    for (int i = 0; i < 1; i++)
    {
        Monster* skeleton = new Monster[1];
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(625);
        skeleton->setY_Pos(140);
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 100, skeleton->getX_Pos() + 100);
        list_skeleton.push_back(skeleton);
    }
    return list_skeleton;
}

std::vector<Monster*> make_Bat_litst() {
    std::vector<Monster*> list_Bat;
    for (int i = 0; i < 1; i++) {
        Monster* bat = new Monster[1];
        bat->loadBatImage();
        bat->setX_Pos(500);
        bat->setY_Pos(50);
        list_Bat.push_back(bat);
    }
    return list_Bat;
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

    std::vector<Monster*> Skeleton_list = make_Skeleton_list();
    std::vector<Monster*> Bat_list = make_Bat_litst();

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


        for (int i = 0; i < Skeleton_list.size(); i++) {
            Monster* skeleton = Skeleton_list.at(i);
            skeleton->setMapXY(game_map.getMap().startX, game_map.getMap().startY);
            skeleton->doPlayer(game_map);
            skeleton->show();
            skeleton->gravity();
            SDL_Rect R_monster = { skeleton->getX_Pos(), skeleton->getY_Pos(), skeleton->get_WithFrame(), skeleton->get_HeighFrame()};
            if(charaterr.attackMonster(R_monster)) {
                skeleton->knockback = true;
            }
            skeleton->SkeletonMeetPlayer(charaterr.getCharater());
        }
        for (int i = 0; i < Bat_list.size(); i++) {
            Monster* Bat = Bat_list.at(i);
            Bat->setMapXY(game_map.getMap().startX, game_map.getMap().startY);
            Bat->doPlayer(game_map);
            Bat->show();
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
