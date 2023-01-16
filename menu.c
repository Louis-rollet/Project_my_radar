/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** menu
*/

#include "my.h"

void settings(wind_t *wind)
{
    while (sfRenderWindow_pollEvent(wind->window, &wind->event)){
        close_menu(wind);
        while (wind->event.type == sfEvtMouseButtonPressed &&
        sfMouse_getPositionRenderWindow(wind->window).x >= 242 &&
        !(wind->event.type == sfEvtMouseButtonReleased) &&
        sfMouse_getPositionRenderWindow(wind->window).x <= 806 &&
        sfMouse_getPositionRenderWindow(wind->window).y >= 591 &&
        sfMouse_getPositionRenderWindow(wind->window).y <= 621){
            slider_move(wind);
        }
    }
    print_settins(wind);
}

void menu_main(wind_t *wind)
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
        sfRenderWindow_close(wind->window);
    }
}

void menu(wind_t *wind)
{
    while (sfRenderWindow_pollEvent(wind->window, &wind->event)){
        menu_main(wind);
        if (wind->event.type == sfEvtMouseButtonPressed &&
        sfMouse_getPositionRenderWindow(wind->window).x >= 632 &&
        sfMouse_getPositionRenderWindow(wind->window).x <= 1294 &&
        sfMouse_getPositionRenderWindow(wind->window).y >= 622 &&
        sfMouse_getPositionRenderWindow(wind->window).y <= 753){
            wind->menu = 4;
        }
    }
    sfRenderWindow_clear(wind->window, sfBlack);
    sfRenderWindow_drawSprite(wind->window, wind->menu_sprite, NULL);
    sfRenderWindow_display(wind->window);
}

void menu_p_start(wind_t *wind)
{
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
        sfRenderWindow_close(wind->window);
    }
    if (wind->event.type == sfEvtMouseButtonPressed &&
    sfMouse_getPositionRenderWindow(wind->window).x >= 632 &&
    sfMouse_getPositionRenderWindow(wind->window).x <= 1294 &&
    sfMouse_getPositionRenderWindow(wind->window).y >= 622 &&
    sfMouse_getPositionRenderWindow(wind->window).y <= 753){
        wind->menu = 4;
    }
}

void menu_paused(wind_t *wind)
{
    while (sfRenderWindow_pollEvent(wind->window, &wind->event)){
        if (wind->event.type == sfEvtClosed)
            sfRenderWindow_close(wind->window);
        if (wind->event.type == sfEvtKeyPressed &&
        wind->event.key.code == sfKeyEscape)
        wind->menu = 1;
        menu_p_start(wind);
    }
    sfRenderWindow_clear(wind->window, sfBlack);
    sfRenderWindow_drawSprite(wind->window, wind->menu_sprite, NULL);
    sfRenderWindow_display(wind->window);
}
