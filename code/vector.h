/**
 * @file vector.h
 * @author divilol
 * @brief 
 * @version 0.01
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<iostream>
#include "Math.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct vector
{
    float x,y,z;
    float dx,dy,dz;
    float angle=0;

};

bool check_collision(const SDL_Rect& a, const SDL_Rect& b, SDL_Rect& intersect)
{
    intersect = { 0, 0, 0, 0 };

    int leftX = std::max(a.x, b.x);
    int rightX = std::min(a.x + a.w, b.x + b.w);
    int topY = std::max(a.y, b.y);
    int bottomY = std::min(a.y + a.h, b.y + b.h);

    if (leftX <= rightX && topY <= bottomY)
    {
        intersect = { leftX, topY, rightX - leftX, bottomY - topY };
        return true;
    }

    return false;
}
