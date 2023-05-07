#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"
#include"Map.h"
#include"Charater.h"
#include"Timer.h"
#include"Monster.h"
#include"Menu.h"


std::vector<Monster*> make_Skeleton_list_map1()
{
    std::vector<Monster*> list_skeleton;
    {
        Monster* skeleton = new Monster;
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(625);
        skeleton->setY_Pos(140);
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 100, skeleton->getX_Pos() + 100);
        list_skeleton.push_back(skeleton);
    }
    {
        Monster* skeleton = new Monster;
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(380);
        skeleton->setY_Pos(800);
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 80, skeleton->getX_Pos() + 80);
        list_skeleton.push_back(skeleton);
    }
    {
        Monster* skeleton = new Monster;
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(460);
        skeleton->setY_Pos(300);
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 60, skeleton->getX_Pos() + 60);
        list_skeleton.push_back(skeleton);
    }
    {
        Monster* skeleton = new Monster;
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(270);
        skeleton->setY_Pos(140);
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 70, skeleton->getX_Pos() + 70);
        skeleton->holdKey = true;
        list_skeleton.push_back(skeleton);
    }
    {
        Monster* skeleton = new Monster;
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(390);
        skeleton->setY_Pos(140);
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 70, skeleton->getX_Pos() + 70);
        list_skeleton.push_back(skeleton);
    }
    return list_skeleton;
}
std::vector<Monster*> make_Skeleton_list_map2()
{
    std::vector<Monster*> list_skeleton;
    {
        Monster* skeleton = new Monster;
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(130);
        skeleton->setY_Pos(140);
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 80, skeleton->getX_Pos() + 80);
        skeleton->holdKey = true;
        list_skeleton.push_back(skeleton);
    }
    {
        Monster* skeleton = new Monster;
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(170);
        skeleton->setY_Pos(140);
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 90, skeleton->getX_Pos() + 90);
        list_skeleton.push_back(skeleton);
    }
    {
        Monster* skeleton = new Monster;
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(870);
        skeleton->setY_Pos(800);
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 90, skeleton->getX_Pos() + 90);
        list_skeleton.push_back(skeleton);
    }
    {
        Monster* skeleton = new Monster;
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(980);
        skeleton->setY_Pos(800);
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 90, skeleton->getX_Pos() + 90);
        list_skeleton.push_back(skeleton);
    }
    {
        Monster* skeleton = new Monster;
        skeleton->loadSkeletonImage();
        skeleton->SetClips();
        skeleton->setX_Pos(1090);
        skeleton->setY_Pos(800);
        skeleton->holdKey = true;
        skeleton->SetAnimationPos(skeleton->getX_Pos() - 90, skeleton->getX_Pos() + 90);
        list_skeleton.push_back(skeleton);
    }
    return list_skeleton;
}

int main(int argc, char* args[])
{
    Timer Fps_Time;
    commonFuc::init();
    if (Mix_Init(MIX_INIT_MP3) < 0) {
        // Xử lý lỗi khi không khởi tạo được thư viện âm thanh
        // ...
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        // Xử lý lỗi khi không khởi tạo được cấu hình âm thanh
        // ...
    }
    Mix_Music* backgroundMusic = Mix_LoadMUS("boss-133663.mp3");
    Mix_PlayMusic(backgroundMusic, -1);

    commonFuc::RenderWindow("Vagabond", SCREEN_WIDTH, SCREEN_HEIGHT);
    Entity win(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, commonFuc::loadTexture("image/background/win.png"));
    Entity background1(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, commonFuc::loadTexture("image/map/0.png"));
    std::vector<Entity> background2;
    {
        Entity E1(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, commonFuc::loadTexture("image/background/background_layer_1.png"));
        Entity E2(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, commonFuc::loadTexture("image/background/background_layer_2.png"));
        Entity E3(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, commonFuc::loadTexture("image/background/background_layer_3.png"));
        background2.push_back(E1);
        background2.push_back(E2);
        background2.push_back(E3);
    }
    Entity tutorialbackground(0, 0, 840, 480, commonFuc::loadTexture("image/UI/tutorial.png"));
    Entity play(0,0,234,123,commonFuc::loadTexture("image/UI/Button.png"));
    play.setCurrentFrame(0, 20, 290, 90);
    play.setEntity(310, 230, 170, 50);
    Entity tutorial(0,0,234,123, commonFuc::loadTexture("image/UI/Button.png"));
    tutorial.setCurrentFrame(310, 20, 583, 90);
    tutorial.setEntity(270, 300, 300, 50);
    Entity quit(0,0,234,123,commonFuc::loadTexture("image/UI/Button.png"));
    quit.setCurrentFrame(915, 20, 290, 90);
    quit.setEntity(310, 370, 170, 50);
    Menu menu;
    menu.menu_pic = commonFuc::loadTexture("image/UI/menu.png");

  
    
    gameMap game_map;
    game_map.loadMap("image/map/map1.csv", "image/map/DungeonTileSet.png");
    bool gameRunning = false;

    Charater charaterr;
    Monster monster;
    charaterr.loadImage();
    charaterr.loadHealBar();


    std::vector<Monster*> Skeleton_list1 = make_Skeleton_list_map1();
    std::vector<Monster*> Skeleton_list2 = make_Skeleton_list_map2();
    SDL_Rect back = { 0,0,150,150 };
    SDL_Event event;
    bool runningMenu = true;
    bool gametutorial = false;
    while (runningMenu)
    {
        //neu ma tutorial chay runmenu
        menu.runMenu(play, quit, tutorial, event, gameRunning, runningMenu, gametutorial);
        commonFuc::display();
        while(gametutorial == true) {
            commonFuc::render(tutorialbackground);
            commonFuc::display();
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    // Kiểm tra xem chuột có trên nút Play không
                    if (event.button.x >= back.x && event.button.x <= back.x + back.w
                        && event.button.y >= back.y && event.button.y <= back.y + back.h) {
                        gametutorial = false;
                    }
                }
            }
        }
    }
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
        if (charaterr.isWin == true) {
            commonFuc::render(win);

        }
        if (game_map.statusMap == 1) {
            commonFuc::render(background1);
        }
        else {
            commonFuc::render(background2[0]);
            commonFuc::render(background2[1]);
            commonFuc::render(background2[2]);
        }
        charaterr.setMapXY(game_map.getMap().startX, game_map.getMap().startY);
        charaterr.doPlayer(game_map);
        charaterr.show();
        if (game_map.statusMap == 1) {
            game_map.mapMap1();
        }
        else {
            game_map.mapMap2();
        }
        game_map.drawMap();
        charaterr.showBar();
        if (game_map.statusMap == 1) {
            for (int i = 0; i < Skeleton_list1.size(); i++) {
                Monster* skeleton = Skeleton_list1.at(i);
                skeleton->setMapXY(game_map.getMap().startX, game_map.getMap().startY);
                skeleton->doPlayer(game_map);
                skeleton->show();
                skeleton->showHP();
                skeleton->gravity();
                SDL_Rect R_monster = { skeleton->getX_Pos(), skeleton->getY_Pos(), skeleton->get_WithFrame(), skeleton->get_HeighFrame() };
                if (charaterr.attackMonster(R_monster)) {
                    skeleton->knockback = true;
                }
                if (skeleton->attackCharater(charaterr.getCharater())) {
                    charaterr.knoback = true;
                }
                skeleton->SkeletonMeetPlayer(charaterr.getCharater());
            }
            if (charaterr.nextMap == true) {
                game_map.nextMap();
                game_map.statusMap = 2;
                charaterr.nextMap = false;
                charaterr.setstatusMap(2);
                charaterr.resetcharater();
            }
        }
        else {
            for (int i = 0; i < Skeleton_list2.size(); i++) {
                Monster* skeleton = Skeleton_list2.at(i);
                skeleton->setMapXY(game_map.getMap().startX, game_map.getMap().startY);
                skeleton->doPlayer(game_map);
                skeleton->show();
                skeleton->showHP();
                skeleton->gravity();
                SDL_Rect R_monster = { skeleton->getX_Pos(), skeleton->getY_Pos(), skeleton->get_WithFrame(), skeleton->get_HeighFrame() };
                if (charaterr.attackMonster(R_monster)) {
                    skeleton->knockback = true;
                }
                if (skeleton->attackCharater(charaterr.getCharater())) {
                    charaterr.knoback = true;
                }
                skeleton->SkeletonMeetPlayer(charaterr.getCharater());
            }
        }
        if (charaterr.isWin == true) {
            commonFuc::render(win);

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
