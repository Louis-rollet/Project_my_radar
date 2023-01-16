/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** create_chained_list
*/
#include "my.h"

list_plane *init_airplaine(void)
{
    list_plane *list_plane = malloc(sizeof(*list_plane));
    list_plane->first = NULL;
    return (list_plane);
}

list_tower *init_tower(void)
{
    list_tower *list_tower = malloc(sizeof(*list_tower));
    list_tower->first = NULL;
    return (list_tower);
}

int read_file(char *file, wind_t *wind)
{
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return (84);
    int size1 = get_file_size(file);
    wind->buffer = malloc(sizeof(char) * size1 + 1);
    if (wind->buffer == NULL)
        return (84);
    int size = read(fd, wind->buffer, size1);
    if (size == -1)
        return (84);
    wind->buffer[size1 + 1] = '\0';
    close(fd);
}

void in_linked_list_plane(int nb, plane_t *plane, int count)
{
    if (count == 0)
        plane->pos_start.x = nb;
    if (count == 1)
        plane->pos_start.y = nb;
    if (count == 2)
        plane->pos_end.x = nb;
    if (count == 3)
        plane->pos_end.y = nb;
    if (count == 4)
        plane->speed = nb;
    if (count == 5)
        plane->delay = nb;
}

int search_num(wind_t *wind, int i, list_plane *list_plane, plane_t *plane)
{
    int count = 0, v = 0, nb = 0;
    for (; wind->buffer[i] != '\0' && wind->buffer[i] != '\n'; i++) {
        nb = 0, v = 0;
        for (;wind->buffer[i] >= '0' && wind->buffer[i] <= '9' &&
        wind->buffer[i] != '\n'; i++){
            nb = nb * 10 + wind->buffer[i] - 48;
            v = 1;
        }
        in_linked_list_plane(nb, plane, count);
        if (v == 1)
            count++;
    }
}
