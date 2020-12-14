/*
** ETNA PROJECT, 11/02/2020 by dogota_n
** my_ls
** File description:
**      my_tools_arguments functions
*/

#include <stdio.h>
#include <stdlib.h>

#include "my_tools.h"

char **my_save_arguments(int argc, char** argv) {
    char **arrayOfArgv = (char **)malloc(sizeof(char *) * argc);
    if (argc > 1) {
        for (int i = 0; i < argc; i++) {
            if (i > 0) {
                arrayOfArgv[i - 1] = malloc(sizeof(argv[i]));
                my_strcpy(arrayOfArgv[i - 1], argv[i]);
            }
        }
    }
    return arrayOfArgv;
}

int my_count_paths(int argc, char **arrayOfArgv) {
    int countPaths = 0;
    for (int i = 0; i < argc - 1; i++) {
        if (arrayOfArgv[i][0] != '-') {
            countPaths++;
        }
    }
    return countPaths;
}

int my_count_options(int argc, char **arrayOfArgv) {
    int countOptions = 0;
    for (int i = 0; i < argc - 1; i++) {
        if (arrayOfArgv[i][0] == '-') {
            countOptions++;
        }
    }
    return countOptions;
}

char **my_save_paths(int argc, char **arrayOfArgv) {
    char **arrayOfPaths = (char **)malloc(sizeof(char *) * my_count_paths(argc, arrayOfArgv));
    for (int i = 0, j = 0; i < argc - 1; i++) {
        if (arrayOfArgv[i][0] != '-') {
            arrayOfPaths[j] = malloc(sizeof(arrayOfArgv[j]));
            my_strcpy(arrayOfPaths[j], arrayOfArgv[i]);
            j++;
        }
    }
    return arrayOfPaths;
}

char **my_save_options(int argc, char **arrayOfArgv) {
    char **arrayOfOptions = (char **)malloc(sizeof(char *) * my_count_paths(argc, arrayOfArgv));
    for (int i = 0, j = 0; i < argc - 1; i++) {
        if (arrayOfArgv[i][0] == '-') {
            arrayOfOptions[j] = malloc(sizeof(arrayOfArgv[j]));
            my_strcpy(arrayOfOptions[j], arrayOfArgv[i]);
            j++;
        }
    }
    return arrayOfOptions;
}

void my_check_arguments(int argc, char **arrayOfArgv) {
    for (int i = 0; i < argc - 1; i ++) {
        printf("%s\n", arrayOfArgv[i]);
    }
}
