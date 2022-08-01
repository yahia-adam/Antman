/*
** EPITECH PROJECT, 2022
** int to str
** File description:
** int to str
*/

#include <stdlib.h>

static int digit_num(int num)
{
    int count = 10;
    int tmp = num;
    int i = 0;

  for (; num > 10; i++) {
      num = tmp / count;
      count = count * 10;
  }
  if (num > 0)
    ++i;
  return (i);
}

char *my_intostr(int nb)
{
    int count = 1;
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * i);
    i = digit_num(nb);
    while (i > 1) {
        i--;
        count = count * 10;
    }
    for (i = 0; count >= 1; i++) {
        str[i] = (nb / count) + 48;
        nb = nb % count;
        count  = count / 10;
    }
    return (str);
}
