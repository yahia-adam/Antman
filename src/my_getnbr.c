/*
** EPITECH PROJECT, 2021
** display all nbr
** File description:
** my_getnbr.c
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int dest = 0;
    int i = 0, j = 0;

    if (str[0] == '\0')
        return -1;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9' || str[i] != '+' && str[i] != '-')
            break;
        if (str[i] == '-')
            j++;
        i++;
    }
    while (str[i] != '\0') {
        while (str[i] >= '0' && str[i] <= '9')  {
            dest = dest * 10 + (str[i] - '0');
            i++;
        }
        dest = (j % 2 == 1) ? dest * (-1) : dest;
        return (dest);
    }
}
