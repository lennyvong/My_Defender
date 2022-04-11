/*
** EPITECH PROJECT, 2022
** get_map.c
** File description:
** get_map
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_structures.h"
#include "my_lib.h"
#include "my_macro.h"
#include <unistd.h>

static int open_map(char *map_name, game_scene_t *game, const int i)
{
    int fd = 0;
    int ret = 0;
    char *map = NULL;

    fd = open(my_strcat("maps/", map_name), O_RDONLY);
    if (fd == -1)
        return ERROR;
    map = malloc(sizeof(char) * 171);
    if (read(fd, map, 170) == - 1)
        return (ERROR);
    map[170] = '\0';
    game->maps->maps[i] = my_str_to_word_array(map, '\n');
    free(map);
    return (SUCCESS);
}

static int count_maps(void)
{
    DIR *dp;
    struct dirent *dirp;
    int nb_maps = 0;

    dp = opendir("maps");
    if (dp == NULL)
        return (ERROR);
    while ((dirp = readdir(dp)) != NULL)
        if (dirp->d_name[0] != '.')
            nb_maps += 1;
    return nb_maps;
}

void get_map(game_scene_t *game, int i_map)
{
    DIR *dp;
    struct dirent *dirp;
    int nb_map = count_maps();
    int read_i = 0;

    dp = opendir("maps");
    game->maps->maps = malloc(sizeof(char **) * nb_map + 100);
    for (; (dirp = readdir(dp)) != NULL;) {
        if (dirp->d_name[0] != '.') {
            if (open_map(dirp->d_name, game, read_i) == ERROR)
                return;
            read_i += 1;
        }
    }
    game->maps->maps[read_i] = NULL;
    game->maps->map_use = game->maps->maps[i_map];
}
