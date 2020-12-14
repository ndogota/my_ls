/*
** ETNA PROJECT, 11/02/2020 by dogota_n
** my_ls
** File description:
**      my_tools functions
*/

#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

void my_putchar(char c) {
    write(1, &c, 1);
}

void my_putstr(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

void my_putnbr(int n) {
    if (n > 2147483647 || n < -2147483648)
        return;
    if (n == -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    if (n < 0) {
        n = n * -1;
        my_putchar('-');
    }
    if (n < 10) {
        my_putchar(n + '0');
        return;
    }
    my_putnbr(n / 10);
    my_putchar((n % 10) + '0');
    return;
}

char *my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int my_strlen(const char *str) {
    int i = 0;
    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_strcat(const char *str1, const char *str2) {
    size_t s1, s2, s3, i = 0;
    char *a;

    s1 = my_strlen(str1);
    s2 = my_strlen(str2);
    s3 = s1+s2+2;
    a = malloc(s3);

    while(*str1 != '\0') {
        a[i] = *str1;
        str1++;
        i++;
    }
    while(*str2 != '\0') {
        a[i] = *str2;
        str2++;
        i++;
    }

    a[i] = '\0';

    return a;
}

char *setToZeroString(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = '0';
    }
}

int my_intLenghtComparator(unsigned x) {
    if (x >= 1000000000) return 10;
    if (x >= 100000000)  return 9;
    if (x >= 10000000)   return 8;
    if (x >= 1000000)    return 7;
    if (x >= 100000)     return 6;
    if (x >= 10000)      return 5;
    if (x >= 1000)       return 4;
    if (x >= 100)        return 3;
    if (x >= 10)         return 2;
    return 1;
}

int my_intLength(int x) {
    return x < 0 ? my_intLenghtComparator(-x) + 1 : my_intLenghtComparator(x);
}

int	my_strcmp(const char *s1, const char *s2) {
    int	i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        ++i;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int my_strcmpNoCaseDifference(const char *a, const char *b) {
    int ca, cb;
    do {
        ca = (unsigned char) *a++;
        cb = (unsigned char) *b++;
        ca = tolower(toupper(ca));
        cb = tolower(toupper(cb));
    } while (ca == cb && ca != '\0');
    return ca - cb;
}

void cleanupStrings(char **strArray, int numberOfStrings) {
    for (int i = 0; i < numberOfStrings; i++) {
        free(strArray[i]);
    }
    free(strArray);
}
