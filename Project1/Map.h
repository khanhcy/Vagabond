#pragma once
#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"


const int TILE_SIZE = 32;

const int MAX_MAP_X = 40;

const int MAX_MAP_Y = 30;

//const int Max_tileSet = 2;

typedef struct map {

    // tọa độ tính theo pixel bắt đầu x trong màn hình;
    int startX;
    // tọa độ bắt đầu của y trong màn hình
    int startY;

    // ô thứ bao nhiêu
    int maxX;
    int maxY;

    // mảng chứa map
    int tile[MAX_MAP_Y][MAX_MAP_X];

    std::string fileName;
};


class gameMap {
public:

    //gameMap();

    void loadMap(const char* name, const char* path);
    void drawMap();
    map getMap(){
        return gamemap;
    }
    void getStartX(const int startX_) { gamemap.startX = startX_; };
    void getStartY(const int startY_) { gamemap.startY = startY_; };
private:
    map gamemap;
    //số lượng tileset
    std::vector<Entity> tileSet;
};