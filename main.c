/*
** EPITECH PROJECT, 2024
** file hanlder
** File description:
** main
*/

#include "./src/file_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int nb_node = 1;
    int size = 0;
    int fd = open(argv[1], O_RDONLY);
    buffer_t *content = get_content(fd, &nb_node, &size);

    printf("%d\n", nb_node);
    free_buffer(content);
    close(fd);
    return argc;
}
