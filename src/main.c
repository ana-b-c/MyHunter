/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/
#include "game.h"

void update_ui(game_t *game)
{
    char score_buffer[50] = "Score: ";
    char level_buffer[50] = "Level: ";

    my_strcat(score_buffer, int_to_str(game->score));
    my_strcat(level_buffer, int_to_str(game->level));
    sfText_setString(game->ui.score_text, score_buffer);
    sfText_setString(game->ui.level_text, level_buffer);
}

void update_game_state(game_t *game, float dt)
{
    if (game->game_state != IN_GAME)
        return;
    update_ducks(game, dt);
    if (game->score >= game->level * 100) {
        game->level++;
        if (game->max_ducks < 10) {
            game->max_ducks++;
            game->ducks[game->max_ducks - 1] = init_duck();
        }
    }
    if (game->misses >= 3)
        game->game_state = GAME_OVER;
}

static void draw_menu(game_t *game)
{
    SFRWDS(game->window, game->assets.start_sprite, NULL);
}

static void draw_in_game(game_t *game)
{
    for (int i = 0; i < game->max_ducks; i++) {
        if (game->ducks[i])
            SFRWDS(game->window, game->ducks[i]->sprite, NULL);
    }
    sfRenderWindow_drawText(game->window, game->ui.score_text, NULL);
    sfRenderWindow_drawText(game->window, game->ui.level_text, NULL);
}

static void draw_game_over(game_t *game)
{
    SFRWDS(game->window, game->assets.game_over_sprite, NULL);
    sfRenderWindow_drawText(game->window, game->ui.game_over_text, NULL);
}

void draw_game(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    SFRWDS(game->window, game->assets.background_sprite, NULL);
    switch (game->game_state) {
        case MENU:
            draw_menu(game);
            break;
        case IN_GAME:
            draw_in_game(game);
            break;
        case GAME_OVER:
            draw_game_over(game);
            break;
    }
    sfRenderWindow_display(game->window);
}

int main(void)
{
    game_t game;
    float dt;

    init_game(&game);
    while (game.is_running) {
        handle_events(&game);
        dt = sfClock_restart(game.clock).microseconds / 1000000.0f;
        update_game_state(&game, dt);
        update_ui(&game);
        draw_game(&game);
    }
    destroy_game(&game);
    return 0;
}
