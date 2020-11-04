
#pragma once

//nav Variables
#define TITLE 0
#define GAME 1
#define WIN 2
#define LOSE 3
#define HIGHSCORE 4
int gamestate = TITLE;

// DINOSAUR VARIABLES //

float       dino_x            = 24;
float       dino_y            = 24;
float       dino_dx           = 0.0;
float       dino_dy           = 0.0;

const float dino_spd          = 0.020;
const float fric              = 0.94;

byte        dino_dir          = 0;
byte        dino_walk_frame   = 0;
byte        dino_attack_frame = 0;
byte        dino_frame        = 0;

bool        dino_attacking    = false;

// CAMERA VARIABLES //

#define CAM_OFFSET 12

float cam_x     = 0.0;
float cam_y     = 0.0;
int   cam_x_off = 0;
int   cam_y_off = 0;

// FIRE VARIABLES //

byte fire_frame = 0;

// MAP VARIABLES //

#define WORLD_WIDTH  24
#define WORLD_HEIGHT 12
#define TILE_SIZE     8

#define BUILD_S          -1

#define TREES_S          1
#define TREES_M          2
#define TREES_L          3
#define DIRT_M           4
#define DIRT_L           5
#define ROAD_C_TL        6
#define ROAD_C_TR        7
#define ROAD_C_BL        8
#define ROAD_C_BR        9
#define ROAD_H          10
#define ROAD_V          11
#define ROAD_T_L        12
#define ROAD_T_R        13
#define ROAD_T_U        14
#define ROAD_T_D        15

const unsigned int PROGMEM world_map[WORLD_HEIGHT][WORLD_WIDTH] = {
  {TREES_L, TREES_L, TREES_M, TREES_S, ROAD_V, 0, 0, ROAD_V, 0, DIRT_M, DIRT_L, 0, 0, 0, DIRT_L, DIRT_L, 0, 0, 0, 0, 0, 0, 0, 0},
  {TREES_M, TREES_M, TREES_S, TREES_M, ROAD_V, 0, 0, ROAD_V, 0, 0, 0, ROAD_C_TL, ROAD_H, ROAD_C_TR, 0, 0, 0, DIRT_M, 0, 0, 0, 0, 0, 0},
  {TREES_M, TREES_S, DIRT_L, DIRT_L, ROAD_C_BL, ROAD_H, ROAD_H, ROAD_T_L, 0, 0, 0, ROAD_V, 0, ROAD_V, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, DIRT_M, DIRT_L, DIRT_L, DIRT_M, ROAD_V, TREES_S, TREES_L, TREES_M, ROAD_V, 0, ROAD_C_BL, ROAD_H, ROAD_H, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, DIRT_M, 0, ROAD_C_BL, ROAD_H, ROAD_T_D, ROAD_H, ROAD_C_BR, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {TREES_M, 0, 0, 0, 0, 0, 0, 0, 0, ROAD_V, 0, 0, 0, TREES_S, DIRT_M, DIRT_L, 0, 0, 0, 0, 0, 0, DIRT_M, 0},
  {TREES_M, TREES_S, 0, 0, 0, 0, ROAD_C_TL, ROAD_H, ROAD_H, ROAD_C_BR, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {TREES_L, TREES_M, 0, 0, 0, 0, ROAD_V, 0, 0, 0, 0, 0, TREES_S, 0, 0, 0, DIRT_M, 0, 0, DIRT_M, DIRT_M, 0, 0, 0},
  {TREES_L, TREES_M, 0, 0, 0, 0, ROAD_V, 0, 0, 0, 0, 0, 0, 0, DIRT_M, DIRT_M, 0, 0, 0, 0, 0, 0, 0, 0},
  {TREES_L, 0, 0, 0, TREES_M, 0, ROAD_V, 0, 0, 0, 0, 0, 0, TREES_M, 0, DIRT_M, 0, 0, 0, 0, 0, 0, 0, 0},
  {TREES_L, 0, 0, TREES_S, TREES_M, 0, ROAD_V, 0, 0, 0, 0, 0, TREES_S, TREES_M, DIRT_M, DIRT_M, 0, 0, 0, 0, 0, DIRT_M, 0, 0},
  {TREES_L, TREES_M, 0, TREES_S, TREES_M, 0, ROAD_V, 0, 0, 0, 0, 0, TREES_S, 0, DIRT_M, DIRT_M, 0, 0, 0, 0, 0, 0, 0, 0}
};

// BUILDING VARIABLES //
#define LARGE_BUILDING_COUNT 4
byte large_buildings_hp[LARGE_BUILDING_COUNT];
int large_buildings_pos[LARGE_BUILDING_COUNT][2] = {
  {10, 5},
  {14, 6},
  {8, 1},
  {17, 4}
};
#define SMALL_BUILDING_COUNT 8
byte small_buildings_hp[SMALL_BUILDING_COUNT];

int small_buildings_pos[SMALL_BUILDING_COUNT][2] = {
  {7,   7},
  {7,   8},
  {16,  2},
  {14,  4},
  {5,   1},
  {6,   1},
  {12,  2},
  {15,  2}
};

#define HOME_COUNT 10
byte homes_hp[HOME_COUNT];

int homes_pos[HOME_COUNT][2] = {
{7, 10},
{8, 10},
{8, 9},
{8, 13},
{22, 6},
{22, 7},
{0, 4},
{0, 3},
{12, 0},
{13, 0}
};
// SCORE VARIABLES //

unsigned int score = 0;
