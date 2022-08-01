/*
** EPITECH PROJECT, 2022
** Giantman
** File description:
** file
*/

#include "antman.h"
#include <stdlib.h>

void giantman_img(char *filepath)
{
    char *img = read_file(filepath);
    int i = 0;
    int data = 0;
    int count = 0;
    int len_a = 0;

    for (int j = 0; j != 3; i++) {
        my_putchar(img[i]);
        if (img[i] == '\n')
            j++;
    }
    img += (i);
    while (1) {
        if (img[len_a] == '\n' && img[len_a + 1] == '\0') {
            my_putchar('\n');
            img += 0;
            free(img);
            return;
        }
        if ((count = my_getnbr(img)) == -1)
            return;
        for (len_a = 0; img[len_a] != '@'; len_a++);
        img += len_a + 1;
        if ((data = my_getnbr(img)) == -1)
            return;
        for (len_a = 0; img[len_a] != '\n'; len_a++);
        img += len_a + 1;
        for (int z = 0; z != count; z++) {
            my_putnbr(data);
            my_putchar('\n');
        }
    }
}
