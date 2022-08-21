/**
 * @file Event.h
 * @author divilol
 * @brief 
 * @version 0.01
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <SDL2/SDL.h>

#define Right SDLK_RIGHT
#define Left SDLK_LEFT
#define Up SDLK_UP
#define Down SDLK_DOWN
#define W SDLK_w
#define A SDLK_a
#define D SDLK_d
#define S SDLK_s
#define F SDLK_f
#define C SDLK_c
#define E SDLK_e
#define H SDLK_h
#define J SDLK_j
#define K SDLK_k
#define Esc SDLK_ESCAPE
#define Space SDLK_SPACE
#define key key.keysym.sym
#define KeyEvent SDL_KEYDOWN
#define NoKeyEvent SDL_KEYUP
#define Exit SDL_QUIT
#define LoopEvent SDL_PollEvent


class Event
{
public:
    SDL_Event event;
    SDL_EventType type;
    

};

struct action
{
    bool up = 0;
    bool down = 0;
    bool right = 0;
    bool left = 0;
    bool space = 0;
    
};

