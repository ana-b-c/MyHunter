/*
** EPITECH PROJECT, 2024
** lib.c
** File description:
** lib
*/
#include "game.h"

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0') {
    length++;
    }
    return length;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *dest, const char *src)
{
    char *ptr;
    int dest_length;

    dest_length = my_strlen(dest);
    ptr = dest + dest_length;
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
    }
    return *s1 - *s2;
}

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
    my_putchar(str[i]);
    i++;
    }
    return 0;
}
