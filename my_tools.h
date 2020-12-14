/*
** ETNA PROJECT, 11/02/2020 by dogota_n
** my_ls
** File description:
**      project headers
*/

void my_putchar(char c);
void my_putstr(const char *str);
void my_putnbr(int n);
void my_ls(int argc, char** argv);
void cleanupStrings (char ** strArray, int numberOfStrings);

char *my_strcpy(char *dest, const char *src);
char *my_strcat(const char *str1, const char *str2);
char **my_save_directory_files(char *directory_patch);
char **allocateStrings (int numberOfStrings, int strLength);
char *my_strdup(const char *src);
char *setToZeroString(char *str);

int my_strlen(const char *str);
int	my_strcmp(const char *s1, const char *s2);
int my_strcmpNoCaseDifference(const char *a, const char *b);
int my_intLenghtComparator(unsigned x);
int my_intLength(int x);
