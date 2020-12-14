/*
** ETNA PROJECT, 11/02/2020 by dogota_n
** my_ls
** File description:
**      my_ls functions
*/

#include <stdio.h>
#include <dirent.h>
#include <errno.h>

#include "my_tools.h"
#include "my_tools_directory.h"
#include "my_tools_arguments.h"
#include "my_options_refractor.h"
#include "my_display_tools.h"

int main(int argc, char** argv) {
    my_ls(argc, argv);
    return 0;
}

void my_ls(int argc, char** argv) {
    char **arrayOfArgv = my_save_arguments(argc, argv);
    char **arrayOfPaths = my_save_paths(argc, arrayOfArgv);
    char **arrayOfOptions = my_save_options(argc, arrayOfArgv);
    char **arrayOfMultipleDirectoryFiles = my_saveMultipleDirectoryFiles(arrayOfPaths, my_count_paths(argc, arrayOfArgv));
    int countOptions = my_count_options(argc, arrayOfArgv);
    int countPaths = my_count_paths(argc, arrayOfArgv);
    int countFiles = my_countMultipleDirectoryFiles(arrayOfPaths, countPaths);
    if (argc > 1) {
        if (countOptions > 0) {
            interpretOptions(arrayOfPaths, arrayOfMultipleDirectoryFiles, arrayOfOptions, countOptions, countPaths, countFiles, argc);
        } else {
            my_basicDisplay(arrayOfMultipleDirectoryFiles, countFiles);
        }
    } else {
        my_basicDisplay(arrayOfMultipleDirectoryFiles, my_count_directory_files("."));
    }
    cleanupStrings(arrayOfMultipleDirectoryFiles, countFiles);
    cleanupStrings(arrayOfPaths, countPaths);
    cleanupStrings(arrayOfOptions, countOptions);
    cleanupStrings(arrayOfArgv, argc);
}
