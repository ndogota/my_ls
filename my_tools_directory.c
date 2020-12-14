/*
** ETNA PROJECT, 11/02/2020 by dogota_n
** my_ls
** File description:
**      my_tools_directory functions
*/

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_tools.h"

void my_ls_display(char **arrayOfFiles, int directory_file_count)
{
    for (int i = 0; i < directory_file_count; i++) {
        if (arrayOfFiles[i][0] != '.') {
            printf("%s\n", arrayOfFiles[i]);
        }
    }
}

int my_count_directory_files(char *directory_patch)
{
    DIR* rep = opendir(directory_patch);
    int directory_file_count = 0;
    if (rep == NULL) {
        perror("");
        exit(1);
    } else {
        struct dirent * ent;
        for (; (ent = readdir(rep)) != NULL; directory_file_count++) {
            ent->d_name;
        }
        closedir(rep);
    }
    return directory_file_count;
}

void sort_alpha(char **arrayOfFiles, int directory_file_count)
{
    char *tmp;
    for(int i = 0; i < directory_file_count; i++) {
        for(int j = 0; j < directory_file_count; j++) {
            if(my_strcmp(arrayOfFiles[i], arrayOfFiles[j]) < 0) {
                tmp = arrayOfFiles[i];
                arrayOfFiles[i] = arrayOfFiles[j];
                arrayOfFiles[j] = tmp;
            }
        }
    }
}

void sort_alpha_reversed(char **arrayOfFiles, int directory_file_count)
{
    char *tmp;
    for(int i = 0; i < directory_file_count; i++) {
        for(int j = 0; j < directory_file_count; j++) {
            if(my_strcmp(arrayOfFiles[i], arrayOfFiles[j]) > 0) {
                tmp = arrayOfFiles[i];
                arrayOfFiles[i] = arrayOfFiles[j];
                arrayOfFiles[j] = tmp;
            }
        }
    }
}

char **my_save_directory_files(char *directory_patch)
{
    DIR* rep = opendir(directory_patch);
    int directory_file_count = my_count_directory_files(directory_patch);
    char **arrayOfFiles = (char **)malloc(sizeof(char *) * directory_file_count);
    if (rep == NULL) {
        perror("");
        exit(1);
    } else {
        struct dirent * ent;
        for (int i = 0; i < directory_file_count && (ent = readdir(rep)) != NULL; i++) {
            arrayOfFiles[i] = malloc(sizeof(ent->d_name));
            my_strcpy(arrayOfFiles[i], ent->d_name);
        }
        closedir(rep);
    }
    sort_alpha(arrayOfFiles, directory_file_count);
    return arrayOfFiles;
}

int my_countMultipleDirectoryFiles(char **arrayOfPaths, int arrayOfPathsLenght) {
    int counter = 0;
    if (arrayOfPathsLenght > 0) {
        for (int i = 0; i < arrayOfPathsLenght; i++) {
            DIR* rep = opendir(arrayOfPaths[i]);
            if (rep == NULL) {
                perror("");
                exit(1);
            } else {
                struct dirent * ent;
                for (int i = 0;(ent = readdir(rep)) != NULL; i++) {
                    ent->d_name;
                    counter++;
                }
                closedir(rep);
            }
        }
    } else {
        DIR* rep = opendir(".");
        if (rep == NULL) {
            perror("");
            exit(1);
        } else {
            struct dirent * ent;
            for (int i = 0;(ent = readdir(rep)) != NULL; i++) {
                ent->d_name;
                counter++;
            }
            closedir(rep);
        }
    }
    return counter;
}

char **my_saveMultipleDirectoryFiles(char **arrayOfPaths, int arrayOfPathsLenght) {
    char **returnedArray;
    if (arrayOfPathsLenght > 0) {
        char **arrayOfMultipleDirectoryFiles = (char **)malloc(sizeof(char *) * my_countMultipleDirectoryFiles(arrayOfPaths, arrayOfPathsLenght));
        int counter = 0;
        for (int i = 0; i < arrayOfPathsLenght; i++) {
            char **arrayOfDirectoryFiles = my_save_directory_files(arrayOfPaths[i]);
            sort_alpha(arrayOfDirectoryFiles, my_count_directory_files(arrayOfPaths[i]));
            DIR* rep = opendir(arrayOfPaths[i]);
            if (rep == NULL) {
                perror("");
                exit(1);
            } else {
                struct dirent * ent;
                for (int i = 0;(ent = readdir(rep)) != NULL; i++) {
                    arrayOfMultipleDirectoryFiles[counter] = malloc(sizeof(ent->d_name));
                    my_strcpy(arrayOfMultipleDirectoryFiles[counter], arrayOfDirectoryFiles[i]);
                    counter++;
                }
                closedir(rep);
            }
        }
        returnedArray = arrayOfMultipleDirectoryFiles;
    } else {
        returnedArray = my_save_directory_files(".");
    }
    return returnedArray;
}
