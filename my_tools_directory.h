void my_putstr(const char *str);
void sort_alpha(char **arrayOfFiles, int directory_file_count);
void sort_alpha_reversed(char **arrayOfFiles, int directory_file_count);
void my_ls_display(char **arrayOfFiles, int directory_file_count);

char **my_save_directory_files(char *directory_patch);
char **my_saveMultipleDirectoryFiles(char **arrayOfPaths, int arrayOfPathsLenght);

int my_count_directory_files(char *directory_patch);
int	my_strcmp(const char *s1, const char *s2);
int my_countMultipleDirectoryFiles(char **arrayOfPaths, int arrayOfPathsLenght);
