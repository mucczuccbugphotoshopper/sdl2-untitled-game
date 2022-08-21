/**
 * @file Entity.h
 * @author divilol
 * @brief 
 * @version 0.01
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "vector.h"
#include <assert.h>

const double PI = 3.14159;

class Entity
{
public:
    vector entity_vector;
    SDL_Rect entity_rect;
    SDL_Rect entity_collsion_rect;
    SDL_Rect entity_rect_dsrc;
    SDL_Surface *entity_surface;
    SDL_Texture *entity_texture;
    short int size_x;
    short int size_dsrec_x;
    short int size_y;
    short int size_dsrec_y;
    const char *id_char;
    vector render_vector;
    short int id;
    int get_position();
    int set_position(float new_position);
    int set_position_x(float dx);
    int set_position_y(float dy);
    int set_size(int dsizex,int dsizey);
    int set_size_src(int dsizex,int dsizey);
    void update();
    void set_texture(const char *file, SDL_Renderer *renderer);
    void blit(SDL_Window *window,SDL_Renderer *renderer);
    bool has_collided_entity(Entity *B);
    bool has_collided_rect(SDL_Rect B);
    void set_camera(vector Camera);
    void exit();
};



int Entity::get_position()
{
    return (entity_vector.x,entity_vector.y);
}
int Entity::set_position(float new_position)
{
    return (entity_vector.x,entity_vector.y) = new_position;
}

int Entity::set_size(int dsizex,int dsizey)
{
    size_x = dsizex;
    size_y = dsizey;
    return size_x,size_y;

}

int Entity::set_size_src(int dsizex,int dsizey)
{
    size_dsrec_x = dsizex;
    size_dsrec_y = dsizey;
    return size_dsrec_x,size_dsrec_y;
}

int Entity::set_position_x(float dx)
{
    return (entity_vector.x = dx);
}

int Entity::set_position_y(float dy)
{
    return (entity_vector.y = dy);
}


void Entity::update()
{

    entity_rect.x = entity_vector.x-render_vector.x;
    entity_rect.y = entity_vector.y-render_vector.y;
    entity_rect.h = size_x;
    entity_rect.w = size_y;

    entity_collsion_rect.x = entity_vector.x-render_vector.x;
    entity_collsion_rect.y = entity_vector.y-render_vector.y;
    entity_collsion_rect.h = 388;
    entity_collsion_rect.w = 388;

    entity_rect_dsrc.x = 0;
    entity_rect_dsrc.y = 0;
    entity_rect_dsrc.h = size_dsrec_x;
    entity_rect_dsrc.w = size_dsrec_y;
}

void Entity::set_texture(const char *file, SDL_Renderer *renderer)
{
    entity_surface = IMG_Load(file);
    entity_texture = SDL_CreateTextureFromSurface(renderer,entity_surface);
}

void Entity::blit(SDL_Window *window,SDL_Renderer *renderer)
{
    SDL_RenderCopyEx(renderer,entity_texture,&entity_rect_dsrc,&entity_rect,entity_vector.angle*180/PI,NULL,SDL_FLIP_NONE);

    
}

bool Entity::has_collided_entity(Entity *B)
{
    if (SDL_HasIntersection(&entity_rect,&B->entity_rect))
    {
        return true;
    }
    return false;
}

bool Entity::has_collided_rect(SDL_Rect B)
{
    if (SDL_HasIntersection(&entity_rect,&B))
    {
        return true;
    }
    return false;
}

void Entity::set_camera(vector Camera)
{
    render_vector.x = Camera.x; 
    render_vector.y = Camera.y;
}

void Entity::exit()
{
    SDL_FreeSurface(entity_surface);
    SDL_DestroyTexture(entity_texture);
    id = 0;
    id_char = "";
}


