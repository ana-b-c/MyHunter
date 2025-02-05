/*
** EPITECH PROJECT, 2024
** game.h
** File description:
** game
*/
#ifndef GAME_H
    #define GAME_H

    #define SFT sfTexture_createFromFile
    #define SFMBP sfEvtMouseButtonPressed
    #define SFMPRW sfMouse_getPositionRenderWindow
    #define SFFRC sfFloatRect_contains
    #define SFSGP sfSprite_getGlobalBounds
    #define SFSST sfSprite_setTexture
    #define SFRWDS sfRenderWindow_drawSprite

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <unistd.h>

typedef struct duck_s {
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f velocity;
    sfIntRect frame_rect;
    float animation_timer;
} duck_t;

typedef struct ui_s {
    sfText *score_text;
    sfText *level_text;
    sfText *game_over_text;
} ui_t;

typedef struct assets_s {
    sfFont *font;
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfTexture *start_texture;
    sfSprite *start_sprite;
    sfTexture *game_over_texture;
    sfSprite *game_over_sprite;
    sfSoundBuffer *shoot_buffer;
    sfSound *shoot_sound;
} assets_t;

typedef enum game_state_e {
    MENU,
    IN_GAME,
    GAME_OVER
} game_state_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    assets_t assets;
    ui_t ui;
    duck_t **ducks;
    int score;
    int misses;
    int max_ducks;
    int level;
    int is_running;
    game_state_t game_state;
} game_t;

duck_t *init_duck(void);
void init_game(game_t *game);
void update_ducks(game_t *game, float dt);
void destroy_game(game_t *game);
void handle_events(game_t *game);

char *int_to_str(int num);
int my_strlen(const char *str);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, const char *src);

#endif
