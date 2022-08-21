#include<stdio.h>
#include<iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void apply_surface( int x, int y, SDL_Texture* source, SDL_Renderer* destination)
{
    //Holds offsets
    SDL_Rect offset;
    SDL_Rect offset_src;
    //Get offsets
    offset.x = x;
    offset.y = y;
    offset.h = 64;
    offset.w = 64;
    offset_src.x = 0;
    offset_src.y = 0;
    offset_src.h = 64;
    offset_src.w = 64;

    //Blit
   SDL_RenderCopy(destination,source,&offset_src,&offset);
}




SDL_Renderer *render;
SDL_Surface *red = IMG_Load("spaceship.png");
SDL_Surface *green = IMG_Load("green.bmp");
SDL_Surface *blue = IMG_Load("blue.bmp");
SDL_Texture * red_texture = SDL_CreateTextureFromSurface(render, red);
SDL_Surface *shimmer = NULL;
SDL_Surface *screen = NULL;

class Particle
{
    private:
    //Offsets
    int x, y;
    
    //Current frame of animation
    int frame;
    
    //Type of particle
    SDL_Surface *type;
    
    public:
    //Constructor
    Particle( int X, int Y );
    
    //Shows the particle
    void show();

    //Checks if particle is dead
    bool is_dead();
};

Particle::Particle( int X, int Y )
{
    //Set offsets
    x = X;
    y = Y;
    
    //Initialize animation
    frame = rand() % 5;
    
    //Set type
    switch( rand() % 3 )
    {
        case 0: type = red; break;
        case 1: type = green; break;
        case 2: type = blue; break;
    }
}

void Particle::show()
{
    //Show image
    apply_surface( x, y, red_texture,render);
    
    //Show shimmer
    
    
    //Animate
    frame++;
}

bool Particle::is_dead() 
{
    if( frame > 10 )
    {
        return true;    
    }
    
    return false;
}