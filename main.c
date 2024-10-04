/*
** EPITECH PROJECT, 2024
** file hanlder
** File description:
** main
*/

#include "./src/file_handler.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int nb_node = 1;
    int size = 0;
    buffer_t *content = get_content(argv[1], &nb_node, &size);

    while (content->index < content->next->index) {
        printf("%s", content->buffer);
        content = content->next;
    }
    printf("%s", content->buffer);
    printf("index:size : [%i]\nnb_node : [%i]\n", size, nb_node);
    free(content);
    return argc;
}
