/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** my
*/
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include  <unistd.h>
#include <time.h>

#ifndef MY_H_
    #define MY_H_

typedef struct wind {
    sfRenderWindow *window;
    sfEvent event;
    char *buffer;
    int nb_plane;
    int nb_tower;
    sfTexture *text_background;
    sfSprite *sprite_background;
    sfClock *clock;
    sfTime time;;
    sfClock *clock2;
    sfTime time2;
    sfClock *clock3;
    sfTime time3;
    int rect_aff;
    int rect_aff2;
    sfText *text;
    sfFont *font;
    sfRectangleShape *slider;
    int slider_pos;
    sfRectangleShape *slider2;
    int slider_pos2;
    int menu;
    sfTexture *menu_texture;
    sfSprite *menu_sprite;
    sfTexture *settings_texture;
    sfSprite *settings_sprite;
    int nb_swpan_plane;
    int nb_tower_spawn;
    sfText *text_nb;
    sfText *text_nb2;
    int spawn;
    sfClock *clock_spawn;
    sfTime time_spawn;
    sfText *timer;
    int timer_sec;
    sfClock *clock_timer;
    sfTime time_timer;
} wind_t;

typedef struct plane plane_t;
struct plane {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos_start;
    sfVector2f pos_end;
    sfVector2f pos;
    float vx;
    float vy;
    int speed;
    int delay;
    float time_flight;
    sfRectangleShape *rect;
    sfVector2f pos_rect;
    sfRectangleShape *light;
    sfVector2f pos_light;
    int id;
    int in_cirlce;
    plane_t *next;
};

typedef struct list_plane {
    plane_t *first;
}list_plane;

typedef struct tower tower_t;
struct tower {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int range;
    sfCircleShape *circle;
    sfVector2f pos_circle;
    tower_t *next;
};

typedef struct list_tower {
    tower_t *first;
}list_tower;

list_plane *init_airplaine(void);
list_tower *init_tower(void);
int read_file(char *file, wind_t *wind);
void in_linked_list_plane(int nb, plane_t *plane, int count);
int search_num(wind_t *wind, int i, list_plane *list_plane, plane_t *plane);
void create_plane_2(wind_t *wind, int i, list_plane *list_plane,
plane_t *plane);
int is_plane(wind_t *wind, int i, list_plane *list_plane);
int search_num_t(wind_t *wind, int i, list_tower *list_tower,
tower_t *tower);
void is_tower_create(wind_t *wind, int i, list_tower *list_tower,
tower_t *tower);
int is_tower(wind_t *wind, int i, list_tower *list_tower);
int search_in_file(wind_t *wind, list_plane *list_plane,
list_tower *list_tower);
void move_plane(list_plane *list_plane, sfTime time);
void window_start(wind_t *wind, tower_t *tower,
list_plane *list_plane, list_tower *list_tower);
void window_next(wind_t *wind, list_plane *list_plane, plane_t *plane);
int start_window(wind_t *wind, list_plane *list_plane,
list_tower *list_tower);
void light_on_plane(wind_t *wind, list_plane *list_plane, plane_t *plane);
int verifnull(char *str);
char * str_conca(char *a, char *b);
char *pre_int_to_str(int nb);
void actualiser_number_plane(wind_t *wind, list_plane *list_plane);
int check_if_overlap(int rad, sfVector2i tower, sfVector2i one, sfVector2i two);
int max(int a, int b);
int min(int a, int b);
int intersecting_circle_and_square(plane_t *plane, list_tower *list_tower);
int coliding_plane_with_plane(sfVector2f pos, sfVector2f pos2);
void colide_plane(plane_t *plane, plane_t *plane2, wind_t *wind);
int plane_colision(wind_t *wind, list_plane *list_plane,
list_tower *list_tower);
void create_randome_plane(wind_t *wind, list_plane *list_plane);
void draw_number_plane(wind_t *wind, list_plane *list_plane);
void create_slider(wind_t *wind);
void settings(wind_t *wind);
void menu(wind_t *wind);
void menu_paused(wind_t *wind);
void delete_plane_in_list(list_plane *list_plane, plane_t *plane, wind_t *wind);
void draw_number_plane(wind_t *wind, list_plane *list_plane);
void create_plane(wind_t *wind, list_plane *list_plane, plane_t *plane);
void init_plane(plane_t *plane);
void next_slider(wind_t *wind);
void create_slider(wind_t *wind);
void close_menu(wind_t *wind);
void slider_move(wind_t *wind);
void slider_two_move(wind_t *wind);
void print_settins(wind_t *wind);
sfRectangleShape *create_rec(plane_t *plane);
void create_rand_planes(wind_t *wind, list_plane *list_plane);
int get_file_size(char *file);
void disp_window(wind_t *wind);
void wind_start(wind_t *wind, list_plane *list_plane,
list_tower *list_tower, int b);
void first_menu(wind_t *wind, list_plane *list_plane, list_tower *list_tower);
#endif /* !MY_H_ */
