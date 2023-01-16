/*
** EPITECH PROJECT, 2023
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** debut_windows
*/
#include "my.h"

void delete_plane_in_list(list_plane *list_plane, plane_t *plane, wind_t *wind)
{
    plane_t *tmp = list_plane->first;
    if (tmp == NULL || tmp->next == NULL)
        return;
    if (tmp == plane) {
        list_plane->first = tmp->next;
        free(tmp);
        return;
    }
    while (tmp->next != plane)
        tmp = tmp->next;
    tmp->next = plane->next;
    free(plane);
}

int search_in_file(wind_t *wind, list_plane *list_plane, list_tower *list_tower)
{
    for (int i = 0; wind->buffer[i + 1] != '\0'; i++) {
        if (wind->buffer[i] == 'A'){
            is_plane(wind, i, list_plane);
        }
        if (wind->buffer[i] == 'T') {
            is_tower(wind, i, list_tower);
        }
    }
    free(wind->buffer);
}

void move_plane(list_plane *list_plane, sfTime time)
{
    plane_t *plane = list_plane->first;
    while (plane != NULL) {
        if (time.microseconds / 1000000.0 > plane->delay){
            plane->pos.x += plane->vx / 100;
            plane->pos.y += plane->vy / 100;
            plane->time_flight -= 0.01;
            sfSprite_setPosition(plane->sprite, plane->pos);
            plane->pos_rect.y = plane->pos.y ;
            plane->pos_rect.x = plane->pos.x ;
            sfRectangleShape_setPosition(plane->rect, plane->pos_rect);
        }
        if (plane->pos.x > 1920)
            plane->pos.x = 0;
        if (plane->pos.x < 0)
            plane->pos.x = 1920;
        if (plane->pos.y > 1080)
            plane->pos.y = 0;
        plane = plane->next;
    }
}

void aff_plane(wind_t *wind, tower_t *tower,
list_plane *list_plane, list_tower *list_tower)
{
    while (sfRenderWindow_pollEvent(wind->window, &wind->event)) {
        if (wind->event.type == sfEvtClosed)
            sfRenderWindow_close(wind->window);
        if (wind->event.type == sfEvtKeyPressed &&
        wind->event.key.code == sfKeyEscape)
            wind->menu = 3;
        if ((wind->event.type == sfEvtKeyPressed &&
        wind->event.key.code == sfKeySpace) ||
        (wind->event.type == sfEvtKeyPressed &&
        wind->event.key.code == sfKeyL))
            wind->rect_aff *= -1;
        if (wind->event.type == sfEvtKeyPressed &&
        wind->event.key.code == sfKeyA && wind->spawn == 1){
            create_rand_planes(wind, list_plane);
            wind->spawn = 0;
        }
        if (wind->event.type == sfEvtKeyPressed &&
        wind->event.key.code == sfKeyS)
            wind->rect_aff2 *= -1;
    }
}

void window_start(wind_t *wind, tower_t *tower,
list_plane *list_plane, list_tower *list_tower)
{
    sfRenderWindow_clear(wind->window, sfBlack);
    aff_plane(wind, tower, list_plane, list_tower);
    sfRenderWindow_drawSprite(wind->window, wind->sprite_background, NULL);
    while (tower != NULL) {
        if (wind->rect_aff2 == 1)
            sfRenderWindow_drawSprite(wind->window, tower->sprite, NULL);
        if (wind->rect_aff == 1)
            sfRenderWindow_drawCircleShape(wind->window,
            tower->circle, NULL);
        tower = tower->next;
    }
}
