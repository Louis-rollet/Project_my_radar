/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** start_window
*/

#include "my.h"

void wind_plane_aff(wind_t *wind, list_plane *list_plane, plane_t *plane)
{
    sfSprite_setPosition(plane->sprite, plane->pos);
    sfRectangleShape_setPosition(plane->rect, plane->pos_rect);
    sfRectangleShape_setPosition(plane->light, plane->pos_light);
    if (wind->time.microseconds / 1000000 >= plane->delay &&
    plane->time_flight > 0 && wind->rect_aff2 == 1){
        sfRenderWindow_drawSprite(wind->window, plane->sprite, NULL);
    }
    if (wind->time.microseconds / 1000000 >= plane->delay)
        wind->nb_plane++;
    if (wind->rect_aff == 1 && plane->time_flight > 0 &&
    wind->time.microseconds / 1000000 >= plane->delay)
        sfRenderWindow_drawRectangleShape(wind->window, plane->rect, NULL);
    if (plane->time_flight <= 0){
        delete_plane_in_list(list_plane, plane, wind);
        wind->nb_plane--;
    }
}

void window_next(wind_t *wind, list_plane *list_plane, plane_t *plane)
{
    wind->time = sfClock_getElapsedTime(wind->clock);
    wind->time2 = sfClock_getElapsedTime(wind->clock2);
    wind->time_spawn = sfClock_getElapsedTime(wind->clock_spawn);
    wind->time_timer = sfClock_getElapsedTime(wind->clock_timer);
    if (wind->time2.microseconds / 1000000.0 > 0.01) {
        move_plane(list_plane, wind->time);
        sfClock_restart(wind->clock2);
    }
    if (wind->time_spawn.microseconds / 1000000 >= 0.05){
        wind->spawn = 1;
        sfClock_restart(wind->clock_spawn);
    }
    wind->nb_plane = 0;
    while (plane != NULL) {
        wind_plane_aff(wind, list_plane, plane);
        plane = plane->next;
    }
    disp_window(wind);
    sfRenderWindow_display(wind->window);
}

void create_windows_start(wind_t *wind,
list_plane *list_plane, list_tower *list_tower)
{
    wind->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 60},
    "My_Radar", sfFullscreen, NULL);
    wind->text_background = sfTexture_createFromFile("src/map2.jpg", NULL);
    wind->sprite_background = sfSprite_create();
    wind->menu_texture =
    sfTexture_createFromFile("src/background_menu(1).jpg", NULL);
    wind->menu_sprite = sfSprite_create();
    sfSprite_setTexture(wind->menu_sprite, wind->menu_texture, sfTrue);
    sfSprite_setTexture(wind->sprite_background, wind->text_background, sfTrue);
    wind->settings_sprite = sfSprite_create();
    wind->settings_texture =
    sfTexture_createFromFile("src/background_sett.jpg", NULL);
    sfSprite_setTexture(wind->settings_sprite, wind->settings_texture, sfTrue);
    wind->clock = sfClock_create();
    wind->rect_aff = -1, wind->rect_aff2 = 1;
    draw_number_plane(wind, list_plane);
    create_slider(wind);
    wind->nb_swpan_plane = 1000, wind->nb_tower_spawn = 100;
    wind->menu = 3;
    wind->clock_spawn = sfClock_create();
}

void first_menu(wind_t *wind, list_plane *list_plane, list_tower *list_tower)
{
    plane_t *plane = list_plane->first;
    tower_t *tower = list_tower->first;
    if (wind->nb_plane == 0 && plane->time_flight <= 0 && plane->next == NULL){
        wind->nb_plane = 0;
        sfRenderWindow_close(wind->window);
    }
    window_start(wind, tower, list_plane, list_tower);
    window_next(wind, list_plane, plane);
    actualiser_number_plane(wind, list_plane);
    plane_colision(wind, list_plane, list_tower);
}

int start_window(wind_t *wind, list_plane *list_plane, list_tower *list_tower)
{
    wind->spawn = 1;
    int b = 1;
    create_windows_start(wind, list_plane, list_tower);
    wind->clock2 = sfClock_create();
    while (sfRenderWindow_isOpen(wind->window)) {
        wind_start(wind, list_plane, list_tower, b);
    }
}
