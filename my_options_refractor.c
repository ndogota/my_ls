/*
** ETNA PROJECT, 11/02/2020 by dogota_n
** my_ls
** File description:
**      my_options_refractor functions
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#include "my_tools.h"
#include "my_display_tools.h"
#include "my_tools_sort.h"
#include "my_tools_directory.h"

void interpretOptions(char **arrayOfPaths, char **arrayOfMultipleDirectoryFiles, char **arrayOfOptions, int arrayOfOptionsLenght, int arrayOfPathsLenght, int countFiles, int argc) {
    for (int i = 0; i < arrayOfOptionsLenght && arrayOfOptionsLenght > 0; i++) {
        int optionLenght = my_strlen(arrayOfOptions[i]);
        if (optionLenght > 1 && optionLenght < 3) {
            switch(arrayOfOptions[i][1]) {
                case 'l':
                    sort_l_function(arrayOfMultipleDirectoryFiles, arrayOfPaths, countFiles, arrayOfPathsLenght);
                    break;
                case 'r':
                    sort_alpha_reversed(arrayOfMultipleDirectoryFiles, countFiles);
                    my_ls_display(arrayOfMultipleDirectoryFiles, countFiles);
                    break;
                default:
                    my_putstr("ls: invalid option -- '");
                    my_putchar(arrayOfOptions[i][1]);
                    my_putstr("'\nTry 'ls --help' for more information.\n");
                    break;
            }
        }
    }
}

char *filePermissions(char *nameOfFile) {
    char *filePermissionsString = malloc(sizeof(10));
    struct stat fileStat;
    if(stat(nameOfFile, &fileStat) == 0) {
        filePermissionsString[0] = ((S_ISDIR(fileStat.st_mode)) ? 'd' : '-');
        filePermissionsString[1] = ((fileStat.st_mode & S_IRUSR) ? 'r' : '-');
        filePermissionsString[2] = ((fileStat.st_mode & S_IWUSR) ? 'w' : '-');
        filePermissionsString[3] = ((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
        filePermissionsString[4] = ((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
        filePermissionsString[5] = ((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
        filePermissionsString[6] = ((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
        filePermissionsString[7] = ((fileStat.st_mode & S_IROTH) ? 'r' : '-');
        filePermissionsString[8] = ((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
        filePermissionsString[9] = ((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
        filePermissionsString[10] = '\0';
    } else {
        perror("");
        exit(1);
    }
    return filePermissionsString;
}

char **getUserAndGroup(int uid, int gid) {
    char **arrayOfUserAndGroup = (char **)malloc(sizeof(char *) * 2);
    struct group *grp;
    struct passwd *pwd;

    pwd = getpwuid(uid);
    grp = getgrgid(gid);

    arrayOfUserAndGroup[0] = pwd->pw_name;
    my_strcat(arrayOfUserAndGroup[0], " ");
    arrayOfUserAndGroup[1] = grp->gr_name;

    return arrayOfUserAndGroup;
}

int numberOfLinks(char *nameOfFile) {
    struct stat fileStat;
    stat(nameOfFile, &fileStat);
    return fileStat.st_nlink;
}

int getUid(char *nameOfFile) {
    struct stat fileStat;
    stat(nameOfFile, &fileStat);
    return fileStat.st_uid;
}

int getGid(char *nameOfFile) {
    struct stat fileStat;
    stat(nameOfFile, &fileStat);
    return fileStat.st_gid;
}

int getSize(char *nameOfFile) {
    struct stat fileStat;
    stat(nameOfFile, &fileStat);
    return fileStat.st_size;
}

char *getLastModificationDate(char *nameOfFile) {
    struct stat attrib;
    char *time = malloc(50);

    stat(nameOfFile, &attrib);
    strftime(time, 50, "%b %d %H:%M", localtime(&attrib.st_mtime));

    return time;
}

int getMaxSizeFile(char **arrayOfFiles, int arrayLenght) {
    int maxSizeFile = 0;
    for (int i = 0; i < arrayLenght; i++) {
        if (getSize(arrayOfFiles[i]) > maxSizeFile) {
            maxSizeFile = getSize(arrayOfFiles[i]);
        }
    }
    return my_intLength(maxSizeFile);
}
