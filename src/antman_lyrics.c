/*
** EPITECH PROJECT, 2022
** Antman
** File description:
** Compressing lyrics
*/

#include "antman.h"
#include <stdlib.h>

char *spec_ascii(char c, char *dest, int i)
{
    if (c == ',')
        dest[i] = 53;
    if (c == ':')
        dest[i] = 54;
    if (c == ';')
        dest[i] = 55;
    if (c == '!')
        dest[i] = 56;
    if (c == '.')
        dest[i] = 57;
    if (c == '\'')
        dest[i] = 58;
    if (c == '?')
        dest[i] = 59;
    if (c == '-')
        dest[i] = 60;
    if (c == ' ')
        dest[i] = 61;
    if (c == '\n')
        dest[i] = 62;
    return (dest);
}

char *creat_new_lyrics(char *filepath)
{
    char *lyrics = read_file(filepath);
    char *dest = malloc(sizeof(char) * (my_strlen(lyrics) + 1));

    dest [(my_strlen(lyrics) + 1)] = '\0';
    for (int i = 0; lyrics[i] != '\0'; i++) {
        if (lyrics[i] <= 'z' && lyrics[i] >= 'a')
            dest[i] = (lyrics[i] - (96));
        if (lyrics[i] <=  'Z' && lyrics[i] >= 'A')
            dest[i] = (lyrics[i] - 38);
        dest = spec_ascii(lyrics[i], dest, i);    
    }
    return (dest);
}

int antman_lyrics(char *filepath)
{
    int i = 0;
    int n = 0;
    int count = 1;
    unsigned char a = 0;
    unsigned char b = 0;
    unsigned char tmp = 0;
    unsigned char bitwise = 0;
    char *lyrics = creat_new_lyrics(filepath);
    unsigned char *dest = malloc(sizeof(my_strlen(lyrics)));

    while (lyrics[i] != '\0') {
        if (count == 1) {
            a = lyrics[i];
            a = a << 2;
            if (lyrics[i + 1] == '\0') {
                dest[n] = a;
                dest[n + 1] = '\0';
                break;
            }
            b = lyrics[i + 1];
            bitwise = b >> 4;
            bitwise = a | bitwise;
            b = b << 4;
            dest[n] = bitwise;
            n++;
            i += 2;
            if (lyrics[i] == '\0') {
                bitwise = b >> 4;
                dest[n] = bitwise;
                dest[n + 1] = '\0';
                break;
            }
        }
        if (count == 2) {
            a = b;
            b = lyrics[i];
            bitwise = b >> 2;
            bitwise = a | bitwise;
            b = b << 6;
            dest[n] = bitwise;
            n++;
            i++;
            if (lyrics[i] == '\0') {
                bitwise = b >> 6;
                dest[n] = bitwise;
                dest[n + 1] = '\0';
                break;
            }
        }
        if (count == 3) {
            a = b;
            b = lyrics[i];
            bitwise = b | a;
            dest[n] = bitwise;
            n++;
            i++;
            count = 0;
        }
        count++;
        if (lyrics[i] == '\0') {
            dest[n] = '\0';
            break;
        }
    }
    for (int i = 0; dest[i] != '\0'; i++)
        my_putchar(dest[i]);
    return (0);
}
