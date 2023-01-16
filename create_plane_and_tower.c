/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** create_plane_and_tower
*/
#include "my.h"

void create_plane_2(wind_t *wind, int i, list_plane *list_plane, plane_t *plane)
{
    int result = ((plane->pos_start.x - plane->pos_end.x) +
    (plane->pos_start.y - plane->pos_end.y)) / plane->speed;
    int temp = plane->pos_start.x - plane->pos_end.x;
    int temp2 = plane->pos_start.y - plane->pos_end.y;
    if (temp < 0)
        temp = -temp;
    if (temp2 < 0)
        temp2 = -temp2;
    temp = temp + temp2;
    if (plane->speed == 0)
        plane->speed = 1;
    plane->time_flight = temp / plane->speed;
    plane->vx = (plane->pos_end.x - plane->pos_start.x) / plane->time_flight;
    plane->vy = (plane->pos_end.y - plane->pos_start.y) / plane->time_flight;
    sfRectangleShape *rect = create_rec(plane);
    plane->rect = rect;
}

int is_plane(wind_t *wind, int i, list_plane *list_plane)
{
    plane_t *plane = malloc(sizeof(*plane));
    if (list_plane == NULL){
        plane->next = NULL;
        list_plane->first = plane;
    } else {
        plane->next = list_plane->first;
        list_plane->first = plane;
    }
    search_num(wind, i, list_plane, plane);
    plane->sprite = sfSprite_create();
    plane->texture = sfTexture_createFromFile("src/plane.png", NULL);
    sfSprite_setTexture(plane->sprite, plane->texture, sfFalse);
    plane->pos.x = plane->pos_start.x;
    plane->pos.y = plane->pos_start.y;
    wind->nb_plane++;
    plane->id = wind->nb_plane;
    create_plane_2(wind, i, list_plane, plane);
    light_on_plane(wind, list_plane, plane);
}

int search_num_t(wind_t *wind, int i, list_tower *list_tower, tower_t *tower)
{
    int count = 0, v = 0, nb = 0;
    for (; wind->buffer[i] != '\0' && wind->buffer[i] != '\n'; i++){
        nb = 0;
        v = 0;
        for (; wind->buffer[i] >= '0' && wind->buffer[i] <= '9' &&
            wind->buffer[i] != '\n'; i++){
            nb = nb * 10 + wind->buffer[i] - 48;
            v = 1;
        }
        if (count == 0)
            tower->pos.x = nb;
        if (count == 1)
            tower->pos.y = nb;
        if (count == 2)
            tower->range = nb;
        if (v == 1)
            count++;
    }
}

void is_tower_create(wind_t *wind, int i, list_tower *list_t, tower_t *tower)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, tower->range);
    tower->pos_circle.x = tower->pos.x + 32;
    tower->pos_circle.y = tower->pos.y + 32;
    sfCircleShape_setOrigin(circle, (sfVector2f){tower->range,
    tower->range});
    sfCircleShape_setPosition(circle, tower->pos_circle);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfRed);
    sfCircleShape_setOutlineThickness(circle, 2);
    tower->circle = circle;
}

int is_tower(wind_t *wind, int i, list_tower *list_tower)
{
    tower_t *tower = malloc(sizeof(*tower));
    if (list_tower == NULL){
        tower->next = NULL;
        list_tower->first = tower;
    } else {
        tower->next = list_tower->first;
        list_tower->first = tower;
    }
    search_num_t(wind, i + 1, list_tower, tower);
    tower->sprite = sfSprite_create();
    tower->texture = sfTexture_createFromFile("src/tower1.png", NULL);
    sfSprite_setTexture(tower->sprite, tower->texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->pos);
    is_tower_create(wind, i, list_tower, tower);
}
