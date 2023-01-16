/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-louis.rollet
** File description:
** concat_text
*/
#include "my.h"

int my_strlongueur(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int verifnull(char *str)
{
    if (str == NULL)
        return 1;
    return 0;
}

char * str_conca(char *a, char *b)
{
    int k = 0;
    char *deli = malloc(sizeof(char) * (my_strlongueur(a) +
    my_strlongueur(b) + 2));
    for (int j = 0; a[j] != '\0' && verifnull(a) != 1; j++){
        if (a[j] != '-') {
            deli[k] = a[j];
            k++;
        }
    }
    deli[k] = '\0';
    for (int i = 0; b[i] != '\0' && verifnull(b) != 1; i++){
        if (b[i] != '-'){
            deli[k] = b[i];
            k++;
        }
    }
    deli[k] = '\0';
    return deli;
}

char *pre_int_to_str(int nb)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * 100);
    while (nb > 0) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i++;
    }
    str[i] = '\0';
    char *str2 = malloc(sizeof(char) * 100);
    for (int j = i - 1; j >= 0; j--) {
        str2[k] = str[j];
        k++;
    }
    str2[k] = '\0';
    return str2;
}

void actualiser_number_plane(wind_t *wind, list_plane *list_plane)
{
    char *str = malloc(sizeof(char) * 100);
    char *str2 = pre_int_to_str(wind->nb_plane);
    str = str_conca("Number of plane: ", str2);
    sfText_setString(wind->text, str);
}
