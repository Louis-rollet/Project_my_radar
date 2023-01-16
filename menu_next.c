/*
** EPITECH PROJECT, 2023
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** menu_next
*/

#include "my.h"

void create_slider(wind_t *wind)
{
    wind->slider = sfRectangleShape_create();
    sfRectangleShape_setSize(wind->slider, (sfVector2f){564, 31});
    sfRectangleShape_setFillColor(wind->slider, sfWhite);
    sfRectangleShape_setPosition(wind->slider, (sfVector2f){242, 590});
    wind->slider_pos = 100;
    wind->text_nb = sfText_create();
    sfText_setString(wind->text_nb, "1000");
    sfText_setFont(wind->text_nb, wind->font);
    sfText_setCharacterSize(wind->text_nb, 30);
    sfText_setPosition(wind->text_nb, (sfVector2f){826, 585});
    sfText_setColor(wind->text_nb, sfBlack);
    wind->clock_timer = sfClock_create();
    wind->timer_sec = 0;
}

void close_menu(wind_t *wind)
{
    if (wind->event.type == sfEvtClosed)
        sfRenderWindow_close(wind->window);
    if (wind->event.type == sfEvtKeyPressed &&
    wind->event.key.code == sfKeyEscape)
    wind->menu = 1;
    if (wind->event.type == sfEvtMouseButtonPressed &&
    sfMouse_getPositionRenderWindow(wind->window).x >= 633 &&
    sfMouse_getPositionRenderWindow(wind->window).x <= 1294 &&
    sfMouse_getPositionRenderWindow(wind->window).y >= 433 &&
    sfMouse_getPositionRenderWindow(wind->window).y <= 560)
        wind->menu = 1;
    if (wind->event.type == sfEvtMouseButtonPressed &&
    sfMouse_getPositionRenderWindow(wind->window).x >= 632 &&
    sfMouse_getPositionRenderWindow(wind->window).x <= 1294 &&
    sfMouse_getPositionRenderWindow(wind->window).y >= 813 &&
    sfMouse_getPositionRenderWindow(wind->window).y <= 942){
        wind->menu = 3;
    }
}

void slider_move(wind_t *wind)
{
    wind->slider_pos = sfMouse_getPositionRenderWindow(wind->window).x - 242;
    if (wind->slider_pos > 564)
        wind->slider_pos = 564;
    if (wind->slider_pos < 1)
        wind->slider_pos = 1;
    sfRectangleShape_setSize(wind->slider, (sfVector2f){wind->slider_pos, 31});
    wind->nb_swpan_plane = wind->slider_pos * 1.776;
    if (wind->nb_swpan_plane < 1)
        wind->nb_swpan_plane = 1;
    sfRenderWindow_clear(wind->window, sfBlack);
    sfRenderWindow_drawSprite(wind->window, wind->settings_sprite, NULL);
    sfRenderWindow_drawRectangleShape(wind->window, wind->slider, NULL);
    if (wind->nb_swpan_plane > 1000)
        wind->nb_swpan_plane = 1000;
    sfText_setString(wind->text_nb, pre_int_to_str(wind->nb_swpan_plane));
    sfRenderWindow_drawText(wind->window, wind->text_nb, NULL);
    sfRenderWindow_display(wind->window);
}
