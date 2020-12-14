void interpretOptions(char **arrayOfPaths, char **arrayOfMultipleDirectoryFiles, char **arrayOfOptions, int arrayOfOptionsLenght, int arrayOfPathsLenght, int countFiles, int argc);
void sortFromOptions(char **optionSelected);

char *filePermissions(char *nameOfFile);
char *getLastModificationDate(char *nameOfFile);
char **getUserAndGroup(int uid, int gid);

int my_statRefractor(char *nameOfFile);
int numberOfLinks(char *nameOfFile);
int getMaxSizeFile(char **arrayOfFiles, int arrayLenght);
int getUid(char *nameOfFile);
int getGid(char *nameOfFile);
int getSize(char *nameOfFile);
