/**
 // @file game.cpp
 // @author divilol
 // @brief Just trying c++
 // @version 0.01
 // @date 2022-08-10
 // @copyright Copyright (c) 2022
 *
 */

#include "code/game.h"

int main(int argc, char *argv[])
{

    Game game;
    game.init();
    Color color;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    //* Sample Log//
    game.log.send_log_in_color("Physics process.", 3,"PROCESS");
    game.log.send_log_in_color("End.", 3,"PROCESS");

   

    while (true)
    {
        SDL_GetMouseState(&game.x, &game.y);
        //& Camera stuff//
        if (!game.player_landed)
        {
            game.Camera.x = (game.player->entity_vector.x - WIDTH / 2) / 1.2;
            game.Camera.y = (game.player->entity_vector.y - HEIGHT / 2) / 1.2;
        }
        else
        {
            game.Camera.x = (game.x - WIDTH / 2)/1.2;
            game.Camera.y = (game.y - HEIGHT / 2)/1.2;
        }
        game.player->set_camera(game.Camera);
        game.box->set_camera(game.Camera);
        game.plannet->set_camera(game.Camera);
        game.back_rect.x = -game.Camera.x;
        //* Events//

        if (LoopEvent(&game.event.event))
        {
            if (game.event_happen(Exit))
            {
                break;
            }

            if (game.event_happen(KeyEvent))
            {
                if (E == game.event.event.key)
                {
                    game.player_landed = false;
                    game.e = true;
                    

                }
                if(Esc == game.event.event.key)
                {
                    break;
                }
                if (!game.player_landed)
                {
                    if (W == game.event.event.key)
                    {
                        game.player_action.up = 1;
                    }
                    if (S == game.event.event.key)
                    {
                        game.player_action.down = 1;
                    }
                    if (A == game.event.event.key)
                    {
                        game.player_action.left = 1;
                    }

                    if (D == game.event.event.key)
                    {
                        game.player_action.right = 1;
                    }

                    if (Space == game.event.event.key)
                    {
                        game.player_action.space = 1;
                        game.e = true;
                        game.player->entity_rect.h = 0;
                        game.player->entity_rect.w = 0;
                    }
                    if (J == game.event.event.key)
                    {
                        game.turnSpeed = 0.001;
                        game.player->entity_vector.angle = 0;
                    }

                    if (K == game.event.event.key)
                    {
                        game.turnSpeed = 0.003 * 1.2;
                    }
                }
            }

            if (game.event_happen(NoKeyEvent))
            {
                if (!game.player_landed)
                {
                    if (W == game.event.event.key)
                    {
                        game.player_action.up = 0;
                    }
                    if (S == game.event.event.key)
                    {
                        game.player_action.down = 0;
                    }
                    if (A == game.event.event.key)
                    {
                        game.player_action.left = 0;
                    }

                    if (D == game.event.event.key)
                    {
                        game.player_action.right = 0;
                    }

                    if (Space == game.event.event.key)
                    {

                        game.player_action.space = 0;
                        game.e = false;
                        game.player->entity_rect.h = game.player->size_x;
                        game.player->entity_rect.w = game.player->size_y;
                    }
                }
            }
        }

        if (game.player_action.up)
        {
            game.maxSpeed = 1 * 2;
            game.player->entity_vector.dx += cos(game.player->entity_vector.angle) / 2;
            game.player->entity_vector.dy += sin(game.player->entity_vector.angle) / 2;
        }

        if (game.player_action.down)
        {
            game.maxSpeed = 1;
            game.player->entity_vector.dx -= cos(game.player->entity_vector.angle) / 2;
            game.player->entity_vector.dy -= sin(game.player->entity_vector.angle) / 2;
        }

        if (game.player_action.space && !game.player_action.down)
        {
            game.maxSpeed = 5.00 * 2;
            game.player->entity_vector.dx += cos(game.player->entity_vector.angle) / 2;
            game.player->entity_vector.dy += sin(game.player->entity_vector.angle) / 2;
        }
        else
        {
            game.player->entity_vector.dx *= 0.99;
            game.player->entity_vector.dy *= 0.99;
        }

        if (game.player_action.right)
            game.player->entity_vector.angle += game.turnSpeed;
        if (game.player_action.left)
            game.player->entity_vector.angle -= game.turnSpeed;

        game.speed = sqrt(game.player->entity_vector.dx * game.player->entity_vector.dx + game.player->entity_vector.dy * game.player->entity_vector.dy);

        if (game.speed > game.maxSpeed)
        {
            game.player->entity_vector.dx *= game.maxSpeed / game.speed;
            game.player->entity_vector.dy *= game.maxSpeed / game.speed;
        }

        game.player->entity_vector.x += game.player->entity_vector.dx;
        game.player->entity_vector.y += game.player->entity_vector.dy;
        //& Update//

        game.player->update();
        game.box->update();
        game.plannet->update();

        //^ Collsion//

        if (game.player->has_collided_entity(game.plannet))
        {
          
                
            if(game.player_action.up)
            {
                delete game.player;
            }
            if(game.e)
            {
                if(game.player->entity_rect.y > game.plannet->entity_rect.y)
                {
                    game.player->set_position_y(game.player->entity_vector.y+9);
                }
                if(game.player->entity_rect.y < game.plannet->entity_rect.y)
                {
                    game.player->set_position_y(game.player->entity_vector.y-9);
                }
                if(game.player->entity_rect.x > game.plannet->entity_rect.x)
                {
                    game.player->set_position_x(game.player->entity_vector.x+9);
                }
                if(game.player->entity_rect.x < game.plannet->entity_rect.x)
                {
                    game.player->set_position_x(game.player->entity_vector.x-9);
                }
            }
            game.player_landed = true;

            game.player->entity_vector.dx *= -0.01;
            game.player->entity_vector.dy *= -0.01;

            // speed = 0;
            game.player_action.right = 0;
            game.player_action.left = 0;
            game.player_action.up = 0;
            game.player_action.down = 0;

            game.log.send_log_in_color("Landed!", 3,"DEBUG");
        }
        //! Rendering//
        game.set_color(color);
        SDL_RenderClear(game.renderer);
        game.set_color(color);

        game.plannet->blit(game.window, game.renderer);
        game.player->blit(game.window, game.renderer);

        game.box->blit(game.window, game.renderer);

        SDL_RenderPresent(game.renderer);
    }
    //~ If program ended//
    game.player->exit();
    game.box->exit();
    game.plannet->exit();
    SDL_FreeSurface(red);
    SDL_FreeSurface(green);
    SDL_FreeSurface(blue);
    IMG_Quit();
    SDL_DestroyWindow(game.window);
    game.log.send_log_in_color("Exited.", 3,"EXIT");
    SDL_Quit();

    return 0;
}
