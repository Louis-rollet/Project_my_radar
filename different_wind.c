/*
** EPITECH PROJECT, 2023
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** different_wind
*/
#include "my.h"

void wind_start(wind_t *wind, list_plane *list_plane,
list_tower *list_tower, int b)
{
    if (wind->menu == 1){
        first_menu(wind, list_plane, list_tower);
    }
    if (wind->menu == 2){
        menu(wind);
    }
    if (wind->menu == 3){
        menu_paused(wind);
    }
    if (wind->menu == 4)
        settings(wind);
}
