/*
** EPITECH PROJECT, 2024
** destroy.c
** File description:
** destroy
*/
#include "game.h"

void destroy_assets(assets_t *assets)
{
    sfSprite_destroy(assets->background_sprite);
    sfTexture_destroy(assets->background_texture);
    sfSprite_destroy(assets->start_sprite);
    sfTexture_destroy(assets->start_texture);
    sfSprite_destroy(assets->game_over_sprite);
    sfTexture_destroy(assets->game_over_texture);
    sfSound_destroy(assets->shoot_sound);
    sfSoundBuffer_destroy(assets->shoot_buffer);
    sfFont_destroy(assets->font);
}

void destroy_ui(ui_t *ui)
{
    sfText_destroy(ui->score_text);
    sfText_destroy(ui->level_text);
    sfText_destroy(ui->game_over_text);
}

void destroy_game(game_t *game)
{
    for (int i = 0; i < 10; i++) {
        if (game->ducks[i]) {
            sfSprite_destroy(game->ducks[i]->sprite);
            free(game->ducks[i]);
        }
    }
    free(game->ducks);
    destroy_assets(&game->assets);
    destroy_ui(&game->ui);
    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(game->window);
}
