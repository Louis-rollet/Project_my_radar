/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** file_and_plane
*/

#include "my.h"

void colide_plane( plane_t *plane, plane_t *plane2, wind_t *wind)
{
    while (plane2->next != NULL) {
        while (plane2->next != NULL &&
        (plane == plane2 || plane2->in_cirlce == 1))
            plane2 = plane2->next;
        if (
        coliding_plane_with_plane(plane->pos_rect, plane2->pos_rect) == 1 &&
        plane->delay <= wind->time.microseconds / 1000000 &&
        plane2->delay <= wind->time.microseconds / 1000000 &&
        plane->time_flight > 0 && plane2->time_flight > 0 &&
        plane->in_cirlce == 0 && plane2->in_cirlce == 0) {
            plane->time_flight = 0;
            plane2->time_flight = 0;
        }
        if (plane2->next != NULL)
            plane2 = plane2->next;
        }
}

void verif_in_circle(wind_t *wind, list_plane *list_plane,
list_tower *list_tower, plane_t *plane1)
{
    while (plane1 != NULL) {
        plane1->in_cirlce = 0;
        if (intersecting_circle_and_square(plane1, list_tower) == 1)
            plane1->in_cirlce = 1;
        plane1 = plane1->next;
    }
}

void colide_plane_test(plane_t *plane, plane_t *plane2, wind_t *wind,
list_plane *list_plane)
{
    while (plane->next != NULL) {
        while (plane->next != NULL && plane->in_cirlce == 1)
            plane = plane->next;
        colide_plane(plane, plane2, wind);
        plane2 = list_plane->first;
        if (plane->next != NULL)
            plane = plane->next;
    }
    while (plane != NULL) {
        while (plane->next != NULL && plane2->in_cirlce == 1)
            plane2 = plane2->next;
        colide_plane(plane, plane2, wind);
        plane = plane->next;
    }
}

int plane_colision(wind_t *wind, list_plane *list_plane, list_tower *list_tower)
{
    plane_t *plane1 = list_plane->first;
    if (plane1->next == NULL)
        return (0);
    verif_in_circle(wind, list_plane, list_tower, plane1);
    plane_t *plane = list_plane->first;
    plane_t *plane2 = list_plane->first->next;
    if (plane->next->next == NULL && plane->in_cirlce == 0 &&
    plane2->in_cirlce == 0 &&
    coliding_plane_with_plane(plane->pos_rect, plane->next->pos_rect) == 1 &&
    plane->delay <= wind->time.microseconds / 1000000 &&
    plane2->delay <= wind->time.microseconds / 1000000){
            plane->time_flight = 0;
            plane->next->time_flight = 0;
            return 0;
    }
    colide_plane_test(plane, plane2, wind, list_plane);
}
