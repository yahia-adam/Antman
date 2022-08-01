/*
** EPITECH PROJECT, 2022
** Antman
** File description:
** Antman file
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "antman.h"

int compres_digit(char *buffer)
{
    int fd = open("file.txt", O_CREAT | O_WRONLY, 0644);
    char *str = read_file(buffer);
    unsigned char m = 0;
    unsigned char n = 0;
    unsigned char bit = 0;
    unsigned char bitwis = 0;
    unsigned char rest = 0;
    int z = 0;

    if (str[0] == '-' && str[1] == '1')
        return (-1);
    if ((my_strlen(str) % 2) == 1) {
        z++;
        rest = str[my_strlen(str) - 1];
        str[my_strlen(str) - 1] = '\0';
    }
    for (int i = 0; str[i] != '\0'; i += 2) {
        m = str[i];
        n = str[i + 1];
        bit = m << 4;
        bitwis = bit | n;
        write(fd, &bitwis, sizeof(unsigned char));
    }
    if (z == 1)
        write(fd, &rest, sizeof(unsigned char));
    close(fd);
}

void write_file(int str, int count)
{
    my_putnbr(count);
    my_putchar('@');
    my_putnbr(str);
    my_putchar('\n');
}

int antman_img(char *filepath)
{
    char *img = read_file(filepath);
    int a = 0;
    int len_a = 0;
    int i = 0;
    int count = 1;

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
            return 0;
        }
        count = 1;
        a = my_getnbr(img);
        for (len_a = 0; (img[len_a] != '\n' && img[len_a] != '\0'); len_a++);
        img += (len_a + 1);
        while(a == my_getnbr(img)) {
            if (my_getnbr(img) == -1) {
                return 0;
            }
            count++;
            img += (len_a + 1);
        }
        write_file(a, count);
    }
}
