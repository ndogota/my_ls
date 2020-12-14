/*
** ETNA PROJECT, 11/02/2020 by dogota_n
** my_ls
** File description:
**      my_tools_sort functions
*/

#include <stdio.h>
#include <stdlib.h>

#include "my_options_refractor.h"
#include "my_tools.h"

char *sort_UserAndGroup(char **userAndGroup) {
    char *user = userAndGroup[0];
    char *group = userAndGroup[1];
    my_strcat(user, group);
    return user;
}

void display_l_option(char **arrayOfFiles, char *filePath, int maxSizeLenght, int arrayLenght, int i)
{
    char *pointBackSlash = "./";
    char *filePathString = my_strcat(pointBackSlash, filePath);
    char *backSlashString = "/";
    char *fileNameString = arrayOfFiles[i];
    char *firstConcat = my_strcat(filePathString, backSlashString);
    char *filePathNameString = my_strcat(firstConcat, fileNameString);
    my_putstr(filePermissions(filePathNameString));
    my_putstr(" ");
    my_putnbr(numberOfLinks(filePathNameString));
    my_putstr(" ");
    my_putstr(sort_UserAndGroup(getUserAndGroup(getUid(filePathNameString), getGid(filePathNameString))));
    for (int j = 0; j <= maxSizeLenght - my_intLength(getSize(filePathNameString)); j++) {
        my_putstr(" ");
    }
    my_putnbr(getSize(filePathNameString));
    my_putstr(" ");
    my_putstr(getLastModificationDate(filePathNameString));
    my_putstr(" ");
    my_putstr(arrayOfFiles[i]);
    my_putstr("\n");
    free(firstConcat);
    free(filePathNameString);
}

char **sort_l_function(char **arrayOfFiles, char **arrayOfPaths, int arrayLenght, int arrayOfPathsLenght)
{
    int maxSizeLenght = getMaxSizeFile(arrayOfFiles, arrayLenght);
    if (arrayOfPathsLenght > 0) {
        for (int i = 0; i < arrayOfPathsLenght; i++) {
            for (int j = 0; j < arrayLenght; j++) {
                display_l_option(arrayOfFiles, arrayOfPaths[i], maxSizeLenght, arrayLenght, j);
            }
        }
    } else {
        for (int i = 0; i < arrayLenght; i++) {
            display_l_option(arrayOfFiles, "", maxSizeLenght, arrayLenght, i);
        }
    }
}
