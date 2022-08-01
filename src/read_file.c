/*
** EPITECH PROJECT, 2022
** read_file
** File description:
** read_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/antman.h"

int get_file_size(const char *filename)
{
    int i = 0;
    struct stat st;
    i = stat(filename, &st);
    i = st.st_size;
    return (i);
}

char *read_file(char *filepath)
{
    struct stat file;
    int fd;
    int len_read;
    char *buffer;

    buffer = malloc(sizeof(char) * (get_file_size(filepath) + 1));
    if ((lstat(filepath, &file) == -1) || ( S_ISREG( file.st_mode ) == 0))
        return "-1";
    if (buffer == NULL)
        return ("-1");
    fd = open(filepath, O_RDONLY);
    if (fd == - 1)
        return ("-1");
    len_read = read(fd, buffer, get_file_size(filepath));
    if (len_read == -1)
        return ("-1");
    if (my_strlen(buffer) == 0)
        return "-1";
    buffer[get_file_size(filepath)] = '\0';
    return (buffer);
}