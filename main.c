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
#include <string.h>
#include <errno.h>
#include <sys/time.h>

double now()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.;
}

char *map_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat buff = {0};

    if (fd < 0) {
        printf("Error : %s\n", strerror(errno));
        return NULL;
    }

    if (stat(filepath, &buff) < 0) {
        printf("Error : %s\n", strerror(errno));
        return NULL;
    }
    return mmap(0, buff.st_size, PROT_READ, MAP_SHARED, fd, 0);
}

int main(int argc, char **argv)
{
    file_t *file = init_file(argv[1]);
    char *str = file_to_str(file);
    // map_file(argv[1]);
    file->content = file->content->next;
    printf("%s\n", str);
    free_file(file);
    free(str);
    return argc;
}
