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
    char *userWithSpace = my_strcat(user, " ");
    char *userAndGroupString = my_strcat(userWithSpace, group);
    free(userWithSpace);
    return userAndGroupString;
}

void display_l_option(char **arrayOfFiles, char *filePath, int maxSizeLenght, int arrayLenght, int i)
{
    (void)arrayLenght;
    char *pointBackSlash = "./";
    char *filePathString = my_strcat(pointBackSlash, filePath);
    char *backSlashString = "/";
    char *fileNameString = arrayOfFiles[i];
    char *firstConcat = my_strcat(filePathString, backSlashString);
    char *filePathNameString = my_strcat(firstConcat, fileNameString);
    char *permissions = filePermissions(filePathNameString);
    char **userAndGroup = getUserAndGroup(getUid(filePathNameString), getGid(filePathNameString));
    char *userAndGroupString = sort_UserAndGroup(userAndGroup);
    char *modificationDate = getLastModificationDate(filePathNameString);
    my_putstr(permissions);
    my_putstr(" ");
    my_putnbr(numberOfLinks(filePathNameString));
    my_putstr(" ");
    my_putstr(userAndGroupString);
    for (int j = 0; j <= maxSizeLenght - my_intLength(getSize(filePathNameString)); j++) {
        my_putstr(" ");
    }
    my_putnbr(getSize(filePathNameString));
    my_putstr(" ");
    my_putstr(modificationDate);
    my_putstr(" ");
    my_putstr(arrayOfFiles[i]);
    my_putstr("\n");
    free(modificationDate);
    free(userAndGroupString);
    cleanupStrings(userAndGroup, 2);
    free(permissions);
    free(filePathString);
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
    return arrayOfFiles;
}
