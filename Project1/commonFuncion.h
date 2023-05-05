#pragma once

#include<iostream>
#include <SDL.h>
#include <SDL_image.h>
#include<SDL_ttf.h>
#include<string>
#include<vector>
#include <fstream> 
#include<sstream>
#include<cmath>


static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Surface* surface = NULL;

const int SCREEN_WIDTH = 840 ;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

typedef struct Input {
	int left;
	int right;
	int jump;
	int dash;
	int idle;
	int attack;
	int dead;
};




