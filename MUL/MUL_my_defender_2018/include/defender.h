/*
** EPITECH PROJECT, 2018
** defender.h
** File description:
** defender
*/

#ifndef _DEFENDER_H_
#define _DEFENDER_H_

#include "my_sfml.h"
#define ATTACK "audio/attack.ogg"
#define BOW "audio/bow.ogg"
#define DIE "audio/die.ogg"
#define G_MUSIC "audio/g_music.ogg"
#define M_CLIC "audio/m_clic.ogg"
#define PAUSE "audio/pause.ogg"
#define BOOST "audio/boost.ogg"
#define BUILD "audio/build.ogg"
#define G_CLIC "audio/g_clic.ogg"
#define HOVER "audio/hover.ogg"
#define M_MUSIC "audio/m_music.ogg"
#define RAL "audio/ral.ogg"
#define BG_PATH "sprites/background.png"
#define ENTITY_PATH "sprites/entity.png"
#define END_PATH "sprites/background.png"
#define MENU_PATH "sprites/menu.png"
#define HELP_PATH "sprites/help.png"
#define PAUSE_PATH "sprites/pause.png"
#define FONT_MENU_PATH "text/Qaranta-Bold.ttf"
#define FONT_INFO_PATH "text/clutsy.ttf"

typedef struct window {
    sfVideoMode mode;
    int width;
    int height;
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i mouse_vect;
    sfVector2i clic_vect;
    sfVector2f enemie_vect;
    sfVector2f tower_vect;
    sfKeyCode key;
    int **position_map;
    sfFont *font_menu;
    sfText *text_menu;
    sfFont *font_info;
    sfText *text_info;
    int select_menu;
    int menu_degrees;
    int freq;
    int select_option;
} window_t;

typedef struct image {
    sfTexture *help_tex;
    sfTexture *entity_tex;
    sfTexture *pause_tex;
    sfTexture *bg_tex;
    sfTexture *menu_tex;
    sfTexture *game_end_tex;
    sfSprite *game_end_sprite;
    sfSprite *help_sprite;
    sfSprite *entity_sprite;
    sfSprite *pause_sprite;
    sfSprite *bg_sprite;
    sfSprite *menu_sprite;
    sfIntRect *enemi_rect;
    sfIntRect *tower_rect;
    sfIntRect chemin_rect;
    sfIntRect menu_rect;
    sfIntRect obj_rect;
    sfIntRect spawn_rect;
    sfIntRect panel_rect;
    sfIntRect money_rect;
    sfIntRect tower_panel_rect;
} image_t;

typedef struct audio {
    int music_enable;
    int effet_enable;
    sfMusic *music;
    sfMusic *effect;
} audio_t;

typedef struct tower {
    int id;
    int x;
    int y;
    int level;
    int hp;
    int vda;
    int b_vda;
    int atq;
    int b_atq;
    int ral;
    sfVector2i pos;
    sfIntRect rect;
    sfClock *attack;
    sfTime time_atq;
    float s_atq;
} tower_t;

typedef struct enemi {
    int id;
    sfVector2i pos;
    int level;
    int hp;
    int speed;
    int atq;
    int rew;
    sfIntRect rect;
    int is_spawn;
    int dir;
    sfVector2f fpos;
    int p_dir;
    int state;
} enemi_t;

typedef struct information {
    tower_t *tower;
    enemi_t *enemi;
    int score;
    int money;
    int difficulty;
    int is_pause;
    sfVector2i spawn;
    sfVector2i obj;
    int is_panel;
    sfVector2i panel_pos;
    int panel_display;
    int max_tour;
    int actual_tour;
    int actual_monster;
    int end_tour;
} info_t;

typedef struct timer {
    sfClock *main_clock;
    sfTime main_time;
    float second;
    sfClock *mvt;
    sfClock *anim;
    sfTime mv_time;
    sfTime anim_time;
    float mv_s;
    float ani_s;
    sfClock *sound;
    sfTime sound_time;
    float time_s;
} timergame_t;

typedef struct game {
    window_t win;
    image_t image;
    info_t info;
    audio_t audio;
    timergame_t timer;
} game_t;

void configure_window(window_t *);
int configure_game(game_t *, timergame_t *);
int **prep_mal(void);
void set_tex_sprite(sfTexture *, sfSprite *, char *);
int launch_menu(game_t *);
int display_menu_start(game_t *);
int check_option(char **, game_t);
int get_color(game_t *, sfVector2f);
int compare_option(char *);
void menu_option(game_t *);
void menu_event(game_t *);
void erase_mouse(game_t *);
void change_option(int, game_t *);
int launch_game(game_t *);
int menu_pause(game_t *);
void prepare_map(game_t *);
void get_spawn_obj(sfVector2i *, sfVector2i *, window_t *);
void finish_map(window_t *, info_t *);
void put_map(game_t *);
void prepare_rect(image_t *);
void prepare_entity(game_t *);
void display_panel(game_t *);
void panel_tower(game_t *, int, int);
void put_tower(image_t *, int, int, game_t *);
int get_data(game_t *, int, int, char *);
void push_data(sfVector2i, int, info_t *, game_t *);
void display_info(game_t *);
void draw_panel(sfVector2f *, image_t *, window_t *);
void upgrade_castle(game_t *, int, int);
void erase_panel(game_t *);
void get_upgrade_castle(game_t *, int, int, int);
void up_data_castle(info_t *, int, int);
void upgrade_tower(game_t *, int, int);
void display_max_level(game_t *);
char *next_description(char *, int, int, game_t *);
int is_inside(int, int, game_t *);
void up_data_tower(info_t *, int);
void get_upgrade_tower(game_t *, int, int);
void put_monster(game_t *);
void fill_array(game_t *);
void set_info_enemi(enemi_t *, image_t *);
int get_index(game_t *, int, int);
void display_monster(game_t *, image_t *);
void configure_timer(timergame_t *);
void prepare_timer(timergame_t *);
void attack_tower(game_t *, int);
void attack_monster(game_t *);
void clear_enemi(game_t *);
void put_hp(game_t *, int);
void play_effect(game_t *, char *);
void play_music(game_t *, char *);
void display_score_menu(game_t *);
int next_compare(char *);
int next_menu(game_t *);
void menu_aide(game_t *);
#endif
