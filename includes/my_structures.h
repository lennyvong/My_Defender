/*
** EPITECH PROJECT, 2022
** my_structures.h
** File description:
** my_structures
*/

#ifndef MY_STRUCTURES_H_
    #define MY_STRUCTURES_H_
    #include <SFML/Window/Mouse.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

typedef struct button_s{
    sfRectangleShape *rect;
    sfVector2f position;
    sfVector2f size;
} button_t;

typedef struct mouse_s {
    sfVector2i mouse;
    int id;
    int inv_idx;
}mouse_t;

typedef struct manager_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    mouse_t mouse;
} manager_t;

/////////////////* HOME MENU *//////////////////
typedef struct smoke_s {
    sfSprite *sprite_smoke;
    sfTexture *texture_smoke;
    sfIntRect rect_smoke;
    sfClock *clock_smoke;
    sfTime time_smoke;
    float sec_smoke;
    sfSoundBuffer *smoke_sound;
    sfSound *smoke;
} smoke_t;

typedef struct book_s {
    sfSprite *sprite_book;
    sfTexture *texture_book;
    sfIntRect rect_book;
    sfClock *clock_book;
    sfTime time_book;
    float sec_book;
    sfSoundBuffer *page_sound;
    sfSound *page;
    sfSoundBuffer *allpage_sound;
    sfSound *allpage;
} book_t;

typedef struct speaker_s {
    int sound;
    sfSprite *sprite_speaker;
    sfSprite *sprite_bar;
    sfSprite *sprite_bar2;
    sfTexture *texture_speaker;
    sfTexture *texture_bar;
    sfTexture *texture_bar2;
    sfVector2f pos_bar;
    sfIntRect rect_speaker;
} speaker_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
} text_t;

typedef struct home_scene_s {
    int fps;
    button_t *buttons[6];
    text_t *text[6];
    sfSprite *sprite_home_back;
    sfTexture *home_back;
    sfText *title;
    sfFont *title_font;
    int nb_buttons;
} home_scene_t;

//////////////////* GAME PAUSE *////////////
typedef struct element_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
}element_t;

typedef struct game_pause_s {
    int setting;
    sfRectangleShape *back;
    element_t *elmt[5];
    sfSprite *border_sprite;
    sfSprite *quit_sprite;
    sfSprite *resume_sprite;
    sfTexture *border_texture;
    sfTexture *quit_texture;
    sfTexture *resume_texture;
    sfText *title;
    sfFont *title_font;
}game_pause_t;

/////////////////* GAME *//////////////////
////* MAPS*////
typedef struct maps_s {
    char **map_use;
    char ***maps;
    int y_spawner;
    int x_spawner;
} maps_t;

typedef struct map_info_s {
    int grass;
    int road;
    int rock;
    int box;
    int floor;
} map_info_t;

////* DECOR *////
typedef struct game_elements_s {
    sfIntRect rect;
    sfSprite *life_bar;
    sfIntRect rect_life;
    sfSprite *element;
    int y;
    int x;
    int life;
    int id;
} game_elements_t;

typedef struct index_decor_s {
    int grass;
    int road;
    int rock;
    int box;
    int floor;
} index_decor_t;

typedef struct decor_s {
    index_decor_t *index;
    game_elements_t *grass[120]; //temporaire
    game_elements_t *road[120];
    game_elements_t *rock[120];
    game_elements_t *box[120];
    game_elements_t *floor[120];
    game_elements_t *spawner;
    game_elements_t *base;
} decor_t;

////* ENEMIES *////

typedef struct game_enemy_s {
    sfSprite *enemy;
    sfSprite *life_bar;
    sfSprite *attack;
    sfIntRect rect_attack;
    sfIntRect rect_life;
    sfIntRect rect;
    sfClock *clock_attack;
    sfTime time_attack;
    sfClock *clock;
    sfTime time;
    sfTexture *texture;
    float seconds_attack;
    float speed;
    float seconds;
    int y;
    int x;
    int y_map;
    int x_map;
    int count_move;
    int max_move;
    int position;
    int *direction_spawn;
    int statement;
    int action;
    int base;
    char id;
    int life;
    int attacked;
} game_enemy_t;

typedef struct tab_enemies_s {
    void (*move)(game_enemy_t *enemy, int move);
    char flag;
} tab_enemies_t;

typedef struct spawn_enemies_s {
    sfClock *clock;
    sfTime time;
    int i_count;
    int nb_killed;
    float seconds;
} spawn_enemies_t;

typedef struct enemies_s {
    game_enemy_t **soldiers;
    game_enemy_t **tanks;
    spawn_enemies_t *spawn_soldiers;
    spawn_enemies_t *spawn_tanks;
} enemies_t;

typedef struct game_textures_s {
    sfTexture *tank;
    sfTexture *soldier;
    sfTexture *tower_floor;
    sfTexture *fire_drag;
    sfTexture *life_bar;
    sfTexture *road;
    sfTexture *grass;
    sfTexture *rock;
    sfTexture *box;
    sfTexture *spawner;
    sfTexture *archer_attack;
    sfTexture *ice_attack;
    sfTexture *fire_blue;
} game_textures_t;

typedef struct inventory_s {
    sfRectangleShape *rect;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f size;
    int id;
}inventory_t;

typedef struct shop_s {
    sfRectangleShape *rect;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f size;
    sfText *price;
    char *string;
    sfText *info;
    sfFont *font;
    int id;
}shop_t;
/*  TOWERS */

typedef struct towers_elements_s {
    sfSprite *tower;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    sfTexture *texture;
    float seconds;
    int y;
    int x;
    char id;
    int statement;
} towers_elements_t;

typedef struct towers_s {
    towers_elements_t **tower_archery;
    int nb_tower;
} towers_t;

typedef struct game_scene_s {
    int mode;
    int shopping;
    int nb;
    char *string;
    float sec;
    sfMusic *music;
    sfSprite *sprite_money;
    sfTexture *texture_money;
    sfText *text_money;
    sfFont *font_money;
    sfClock *money_clock;
    sfTime money_time;
    sfVector2f click_pos;
    maps_t *maps;
    map_info_t *info;
    game_textures_t *texture;
    decor_t *decor;
    enemies_t *ennemies;
    inventory_t *inventory[9];
    shop_t *shop[7];
    towers_t *towers;
    sfSoundBuffer *coin_sound;
    sfSound *coin;
} game_scene_t;

typedef struct eng_game_s {
    element_t *elmt[5];
}end_game_t;

/* SCENES */

typedef struct scenes_s {
    int mode;
    int endscene;
    sfMusic *music;
    home_scene_t *home;
    game_scene_t *game;
    game_pause_t *pause;
    manager_t *manager;
    book_t *book;
    smoke_t *smoke;
    speaker_t *speaker;
    end_game_t *end;
} scenes_t;
#endif /* !MY_STRUCTURES_H_ */
