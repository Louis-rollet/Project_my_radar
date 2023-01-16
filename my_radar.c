/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** my_radar
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
    return (0);
}

void create_randome_plane(wind_t *wind, list_plane *list_plane)
{
    plane_t *plane = malloc(sizeof(*plane));
    init_plane(plane);
    if (plane->pos_start.x == plane->pos_end.x &&
    plane->pos_start.y == plane->pos_end.y){
        free(plane);
        create_randome_plane(wind, list_plane);
        return;
    }
    create_plane(wind, list_plane, plane);
    if (plane->time_flight < 20){
        free(plane);
        create_randome_plane(wind, list_plane);
        return;
    }
    wind->nb_plane++;
    plane->id = wind->nb_plane;
    plane->next = list_plane->first;
    list_plane->first = plane;
    light_on_plane(wind, list_plane, plane);
}

void light_on_plane(wind_t *wind, list_plane *list_plane, plane_t *plane)
{
    sfRectangleShape *light = sfRectangleShape_create();
    sfRectangleShape_setSize(light, (sfVector2f){5, 5});
    sfRectangleShape_setFillColor(light, sfGreen);
    sfRectangleShape_setOutlineColor(light, sfGreen);
    sfRectangleShape_setOutlineThickness(light, 1);
    plane->pos_light.x = plane->pos.x + 10;
    plane->pos_light.y = plane->pos.y + 5;
    sfRectangleShape_setPosition(light, plane->pos_light);
    sfRectangleShape_setRotation(light, 90);
    plane->light = light;
}

void desciption(void)
{
    my_putstr("USAGE : ./my_radar [file]\n");
    my_putstr("DESCRIPTION : file is a file containing planes and towers\n");
    my_putstr("You can exit with the Quit button in the menu\n");
    my_putstr("You can go to the menu with the ESC button\n");
    my_putstr("You can change settings in the menu\n");
}

int main(int argc, char **argv)
{
    if (argv[1] == NULL)
        return (0);
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0'){
        desciption();
        return (0);
    }
    struct wind wind;
    wind.nb_plane = 0;
    srand(time(NULL));
    struct list_plane *list_plane = init_airplaine();
    struct list_tower *list_tower = init_tower();
    if (argc < 2)
        return (0);
    read_file(argv[1], &wind);
    search_in_file(&wind, list_plane, list_tower);
    start_window(&wind, list_plane, list_tower);
    free(list_plane);
    free(list_tower);
    sfRenderWindow_destroy(wind.window);
    return (0);
}
