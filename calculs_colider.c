/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** calculs_colider
*/

#include "my.h"

int check_if_overlap(int rad, sfVector2i tower, sfVector2i one, sfVector2i two)
{
    int xn = max(one.x, min(tower.x, two.x));
    int yn = max(one.y, min(tower.y, two.y));
    int dx = xn - tower.x;
    int dy = yn - tower.y;
    return (dx * dx + dy * dy <= rad * rad ? 1 : 0);
}

int max(int a, int b)
{
    return (a >= b ? a : b);
}

int min(int a, int b)
{
    return (a <= b ? a : b);
}

int intersecting_circle_and_square(plane_t *plane, list_tower *list_tower)
{
    tower_t *tower = list_tower->first;
    while (tower != NULL) {
        if (check_if_overlap(tower->range,
        (sfVector2i){tower->pos.x + 20, tower->pos.y + 20},
        (sfVector2i){plane->pos_rect.x, plane->pos_rect.y},
        (sfVector2i){plane->pos_rect.x, plane->pos_rect.y}) == 1)
            return (1);
        tower = tower->next;
    }
    return (0);
}

int coliding_plane_with_plane(sfVector2f pos, sfVector2f pos2)
{
    if (pos.x + 20 >= pos2.x && pos.x <= pos2.x + 20 &&
    pos.y + 20 >= pos2.y && pos.y <= pos2.y + 20)
        return (1);
    return (0);
}
