/**
 * @file game.h
 * @author divilol
 * @brief 
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Entity.h"
#include <iostream>
#include "log.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>
#include "particles.h"
#include "Event.h"

const int WIDTH = 800*2, HEIGHT = 600*2;

struct Color
{
    short int r=0;
    short int g=0;
    short int b=0;
    short int alpha=255;
};

class Game
{
public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Event event;
    float turnSpeed=0.003*1.2;
    int x,y;
    const int TOTAL_PARTICLES = 20;
    /* log is a Log object*/
    Log log;
    /* Player action*/
    action player_action;
    float speed=0;
    float maxSpeed=1.0;
    //? Camera//
    vector Camera;
    //* Sample log//
    bool e;
    bool player_landed;
    SDL_Rect intersection;
    //& Player and box are entitty object//
    Entity *player;
    Entity *box;
    Entity *plannet;
    SDL_Surface *back_surface;
    SDL_Texture *back_texture;
    SDL_Rect back_rect = {0,0,1404/5,846/5};
    SDL_Rect back_rect_src = {0,0,1404,846};
    void init();
    void render(SDL_Texture *tex, SDL_Rect *rect_src, SDL_Rect * rect_dsrc);
    bool event_happen(SDL_EventType type);
    void set_color(Color color);
};

void Game::init()
{
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
     //? If any problems with window*/
    if (NULL == window)
    {
        log.send_log_in_color("Couldn't create window", 4,"FAILURE");
    }
    //& Setting positon for player and the box//
    player = new Entity;
    box = new Entity;
    plannet = new Entity;
    player->set_position_x(400);
    player->set_position_y(299);
    plannet->set_position_x(700);
    plannet->set_position_y(499);
    box->set_position_x(100);
    box->set_position_y(300);
    //? Intialization*//
    int flags = IMG_INIT_PNG;
    int initStatus = IMG_Init(flags);
    if ((initStatus & flags) != flags)
    {
    }

    SDL_Init(SDL_INIT_EVERYTHING);
    //* Setting textures//
    player->set_texture("assets/spaceship.png", renderer);
    box->set_texture("assets/Crate.png", renderer);
    plannet->set_texture("assets/plannet.png",renderer);
    back_surface = IMG_Load("space.png");
    back_texture = SDL_CreateTextureFromSurface(renderer,back_surface);
    log.send_log_in_color("Loading textures.", 3,"TEXTURE");
    //* id for box and player//
    player->id_char = "car";
    player->id = 1;
    box->id_char = "box";
    box->id = 2;
    plannet->id_char = "plannet";
    plannet->id = 3;
    //* size for box and player//
    player->set_size(64,64);
    player->set_size_src(64,64);
    box->set_size(64,64);
    box->set_size_src(512,512);
    plannet->set_size(800,800);
    plannet->set_size_src(800,800);
}

void Game::render(SDL_Texture *tex, SDL_Rect *rect_src, SDL_Rect * rect_dsrc)
{
    SDL_RenderCopy(renderer,tex,rect_src,rect_dsrc);
}

bool Game::event_happen(SDL_EventType type)
{
    if(type == event.event.type)
    {
        return true;
    }
    return false;
}

void Game::set_color(Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.alpha);
}