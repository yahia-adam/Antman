/*
** EPITECH PROJECT, 2022
** Giantman
** File description:
** main.c
*/

#include "antman.h"

int main(int ac , char **av)
{
    if (ac == 2 && (av[1][0] =='-' && av[1][1] == 'h')) {
        my_putstr("USAGE\n");
        my_putstr("    ./giantman/giantman file [1 || 2 || 3]\n\n");
        my_putstr("DESCRIPTION\n\n");
        my_putstr("    1       corresponds to text files containing song lyrics.\n\
            They are series of words, spaces, punctuation and new-lines.\n\
            Other characters can appear but are not common.\n");
        my_putstr("    2       corresponds to HTML files. They can contain any character.\n");
        my_putstr("    3       corresponds to P3 PPM images.\n");
    }
    if (ac != 3)
        return 84;
    if (ac ==  3) {
        if (av[2][0] == '3' && av[2][1] == '\0')
            giantman_img(av[1]);
    }
    return 0;
}
