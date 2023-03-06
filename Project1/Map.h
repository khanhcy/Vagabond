#pragma once
#include"commonFuncion.h"
#include"Entity.h"
#include"RenderWindow.h"


const int TILE_SIZE = 32;

const int MAX_MAP_X = 40;

const int MAX_MAP_Y = 10;

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

    const char* fileName;
};


class gameMap {
public:

    //gameMap();

    void loadMap(const char* name, const char* path);
    void drawMap();


private:
    map gamemap;
    //số lượng tileset
    std::vector<Entity>  tileSet;
};