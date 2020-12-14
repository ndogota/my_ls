/*
** ETNA PROJECT, 11/02/2020 by dogota_n
** my_ls
** File description:
**      my_display_tools functions
*/

#include "my_tools.h"

void my_basicDisplay(char **arrayOfFiles, int arrayLenght) {
    for (int i = 0; i < arrayLenght; i++) {
        if (arrayOfFiles[i][0] != '.') {
            my_putstr(arrayOfFiles[i]);
            my_putchar('\n');
        }
    }
}
