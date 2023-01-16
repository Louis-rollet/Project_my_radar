/*
** EPITECH PROJECT, 2023
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** menu_next_settings
*/

#include "my.h"

void print_settins(wind_t *wind)
{
    sfRenderWindow_clear(wind->window, sfBlack);
    sfRenderWindow_drawSprite(wind->window, wind->settings_sprite, NULL);
    sfRenderWindow_drawRectangleShape(wind->window, wind->slider, NULL);
    sfText_setString(wind->text_nb, pre_int_to_str(wind->nb_swpan_plane));
    sfRenderWindow_drawText(wind->window, wind->text_nb, NULL);
    sfRenderWindow_display(wind->window);
}

sfRectangleShape *create_rec(plane_t *plane)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfRed);
    sfRectangleShape_setOutlineThickness(rect, 1);
    plane->pos_rect.x = plane->pos.x;
    plane->pos_rect.y = plane->pos.y;
    sfRectangleShape_setPosition(rect, plane->pos_rect);
    int rotation_angle = atan2(plane->vy, plane->vx) * 180 / M_PI;
    rotation_angle = rotation_angle + 90;
    sfSprite_setOrigin(plane->sprite, (sfVector2f){10, 10});
    sfSprite_setRotation(plane->sprite, rotation_angle);
    sfRectangleShape_setOrigin(rect, (sfVector2f){10, 10});
    sfRectangleShape_setRotation(rect, rotation_angle);
    return (rect);
}

void create_rand_planes(wind_t *wind, list_plane *list_plane)
{
    for (int i = 0; i < wind->nb_swpan_plane; i++)
        create_randome_plane(wind, list_plane);
}

int get_file_size(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return (84);
    for (int i = 0; 1; i++) {
        char c = 0;
        int size = read(fd, &c, 1);
        if (size == 0)
            return (i);
    }
}
