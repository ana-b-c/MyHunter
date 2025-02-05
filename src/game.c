/*
** EPITECH PROJECT, 2024
** game.c
** File description:
** game
*/
#include "game.h"

duck_t *init_duck(void)
{
    duck_t *duck = malloc(sizeof(duck_t));
    sfTexture *duck_texture;

    if (!duck)
        return NULL;
    duck_texture = SFT("assets/duck.png", NULL);
    duck->sprite = sfSprite_create();
    sfSprite_setTexture(duck->sprite, duck_texture, sfTrue);
    duck->position = (sfVector2f){0, rand() % 400 + 100};
    duck->velocity = (sfVector2f){rand() % 100 + 200, 0};
    duck->frame_rect = (sfIntRect){0, 0, 110, 110};
    duck->animation_timer = 0.0f;
    sfSprite_setTextureRect(duck->sprite, duck->frame_rect);
    sfSprite_setPosition(duck->sprite, duck->position);
    return duck;
}

void init_assets(assets_t *assets)
{
    assets->font = sfFont_createFromFile("assets/fonts.ttf");
    assets->background_texture = SFT("assets/back.png", NULL);
    assets->background_sprite = sfSprite_create();
    SFSST(assets->background_sprite, assets->background_texture, sfTrue);
    assets->start_texture = SFT("assets/start.png", NULL);
x    assets->start_sprite = sfSprite_create();
    sfSprite_setTexture(assets->start_sprite, assets->start_texture, sfTrue);
    assets->game_over_texture = SFT("assets/game_over.png", NULL);
    assets->game_over_sprite = sfSprite_create();
    SFSST(assets->game_over_sprite, assets->game_over_texture, sfTrue);
    assets->shoot_buffer = sfSoundBuffer_createFromFile("assets/shoot.ogg");
    assets->shoot_sound = sfSound_create();
    sfSound_setBuffer(assets->shoot_sound, assets->shoot_buffer);
}

void init_ui(ui_t *ui, sfFont *font)
{
    ui->score_text = sfText_create();
    sfText_setFont(ui->score_text, font);
    sfText_setCharacterSize(ui->score_text, 24);
    sfText_setString(ui->score_text, "Score: 0");
    ui->level_text = sfText_create();
    sfText_setFont(ui->level_text, font);
    sfText_setCharacterSize(ui->level_text, 24);
    sfText_setString(ui->level_text, "Level: 1");
    ui->game_over_text = sfText_create();
    sfText_setFont(ui->game_over_text, font);
    sfText_setCharacterSize(ui->game_over_text, 36);
    sfText_setString(ui->game_over_text, "Game Over!");
}

void init_game(game_t *game)
{
    sfVideoMode mode = {800, 600, 32};

    game->window = sfRenderWindow_create(mode, "Duck Hunter", sfClose, NULL);
    game->clock = sfClock_create();
    game->max_ducks = 1;
    game->ducks = malloc(10 * sizeof(duck_t *));
    for (int i = 0; i < 10; i++) {
        game->ducks[i] = (i < game->max_ducks) ? init_duck() : NULL;
    }
    init_assets(&game->assets);
    init_ui(&game->ui, game->assets.font);
    game->score = 0;
    game->misses = 0;
    game->level = 1;
    game->is_running = 1;
    game->game_state = MENU;
}
