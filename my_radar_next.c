/*
** EPITECH PROJECT, 2023
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** my_radar_next
*/

#include "my.h"

void text_next(wind_t *wind)
{
    sfText *text2 = sfText_create();
    sfText_setFont(text2, wind->font);
    sfText_setCharacterSize(text2, 30);
    sfText_setPosition(text2, (sfVector2f){110, 50});
    sfText_setColor(text2, sfWhite);
    char *str2 = "0";
    sfText_setString(text2, str2);
    wind->timer = text2;
}

void draw_number_plane(wind_t *wind, list_plane *list_plane)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("src/font.otf");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, (sfVector2f){10, 10});
    sfText_setColor(text, sfWhite);
    char *str = "Number of plane: 0";
    sfText_setString(text, str);
    wind->text = text;
    wind->font = font;
    sfText *text2 = sfText_create();
    sfText_setFont(text2, font);
    sfText_setCharacterSize(text2, 30);
    sfText_setPosition(text2, (sfVector2f){10, 50});
    sfText_setColor(text2, sfWhite);
    char *str2 = "Timer: ";
    sfText_setString(text2, str2);
    wind->text_nb2 = text2;
    text_next(wind);
}

void create_plane(wind_t *wind, list_plane *list_plane, plane_t *plane)
{
    plane->pos.x = plane->pos_start.x;
    plane->pos.y = plane->pos_start.y;
    plane->speed = rand() % 100;
    if (plane->speed == 0)
        plane->speed = 1;
    if (plane->speed < 50)
        plane->speed = 50;
    plane->delay = 0;
    create_plane_2(wind, 1, list_plane, plane);
}

void init_plane(plane_t *plane)
{
    plane->texture = sfTexture_createFromFile("src/plane.png", NULL);
    plane->sprite = sfSprite_create();
    sfSprite_setTexture(plane->sprite, plane->texture, sfFalse);
    plane->pos_start.x = rand() % 1920;
    plane->pos_start.y = rand() % 1080;
    plane->pos_end.x = rand() % 1920;
    plane->pos_end.y = rand() % 1080;
}

void disp_window(wind_t *wind)
{
    sfRenderWindow_drawText(wind->window, wind->text, NULL);
    sfRenderWindow_drawText(wind->window, wind->text_nb2, NULL);
    if (wind->time_timer.microseconds / 1000000 >= 1){
        sfClock_restart(wind->clock_timer);
        wind->timer_sec++;
        char *str2 = pre_int_to_str(wind->timer_sec);
        sfText_setString(wind->timer, str2);
    }
    sfRenderWindow_drawText(wind->window, wind->timer, NULL);
}
