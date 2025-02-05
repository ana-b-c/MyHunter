/*
** EPITECH PROJECT, 2024
** update.c
** File description:
** update
*/
#include "game.h"

void update_duck(duck_t *duck, float dt, int level)
{
    duck->position.x += duck->velocity.x * dt;
    if (duck->position.x > 800) {
        duck->position.x = -50;
        duck->position.y = rand() % 400 + 100;
        duck->velocity.x = rand() % 100 + 200 * level;
    }
    sfSprite_setPosition(duck->sprite, duck->position);
    duck->animation_timer += dt;
    if (duck->animation_timer >= 0.2f) {
        duck->animation_timer -= 0.2f;
        duck->frame_rect.left = (duck->frame_rect.left + 110) % 330;
        sfSprite_setTextureRect(duck->sprite, duck->frame_rect);
    }
}

void update_ducks(game_t *game, float dt)
{
    for (int i = 0; i < game->max_ducks; i++) {
        if (game->ducks[i]) {
            update_duck(game->ducks[i], dt, game->level);
        }
    }
}
