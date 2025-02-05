/*
** EPITECH PROJECT, 2024
** events.c
** File description:
** events
*/
#include "game.h"

void handle_mouse_click(game_t *game)
{
    sfVector2i mouse_pos = SFMPRW(game->window);
    sfFloatRect start_bounds = SFSGP(game->assets.start_sprite);

    if (SFFRC(&start_bounds, mouse_pos.x, mouse_pos.y)) {
        game->game_state = IN_GAME;
    }
}

void handle_menu_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            game->is_running = 0;
        }
        if (game->event.type == SFMBP &&
            game->event.mouseButton.button == sfMouseLeft) {
            handle_mouse_click(game);
        }
        if (game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeyEnter) {
            game->game_state = IN_GAME;
        }
    }
}

void handle_game_over_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
                game->is_running = 0;
        if (game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeyEscape)
                game->is_running = 0;
    }
}

static void handle_duck_collision(game_t *game, sfVector2i mouse_pos)
{
    int hit = 0;
    sfFloatRect duck_bounds;

    for (int i = 0; i < game->max_ducks; i++) {
        if (!game->ducks[i])
            continue;
        duck_bounds = SFSGP(game->ducks[i]->sprite);
        if (sfFloatRect_contains(&duck_bounds, mouse_pos.x, mouse_pos.y)) {
            game->score += 10;
            game->ducks[i]->position.x = -50;
            game->ducks[i]->position.y = rand() % 400 + 100;
            game->ducks[i]->velocity.x = rand() % 100 + 200 * game->level;
            hit = 1;
            break;
        }
    }
    game->misses += !hit;
}

void handle_in_game_events(game_t *game)
{
    sfVector2i mouse_pos;

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            game->is_running = 0;
        }
        if (game->event.type == SFMBP &&
            game->event.mouseButton.button == sfMouseLeft) {
                sfSound_play(game->assets.shoot_sound);
                mouse_pos = sfMouse_getPositionRenderWindow(game->window);
                handle_duck_collision(game, mouse_pos);
            }
    }
}

void handle_events(game_t *game)
{
    switch (game->game_state) {
        case MENU:
            handle_menu_events(game);
            break;
        case IN_GAME:
            handle_in_game_events(game);
            break;
        case GAME_OVER:
            handle_game_over_events(game);
            break;
    }
}
