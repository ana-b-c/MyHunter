/*
** EPITECH PROJECT, 2024
** utils.c
** File description:
** utils
*/
#include "game.h"

static int get_num_length(int num)
{
    int temp = num;
    int len = 0;

    if (num == 0)
        return 1;
    while (temp != 0) {
        temp /= 10;
        len++;
    }
    return len;
}

static void handle_negative(int *num, int *is_negative)
{
    if (*num < 0) {
        *is_negative = 1;
        *num = - *num;
    }
}

static char *allocate_str(int len, int is_negative)
{
    char *str = malloc(len + is_negative + 1);

    if (!str)
        return NULL;
    str[len + is_negative] = '\0';
    return str;
}

static void convert_to_str(int num, char *str, int len, int is_negative)
{
    int temp_len = len;
    int index;

    while (temp_len > 0) {
        temp_len--;
        index = temp_len + is_negative;
        str[index] = (num % 10) + '0';
        num /= 10;
    }
}

static void add_negative_sign(char *str, int is_negative)
{
    if (is_negative)
        str[0] = '-';
}

char *int_to_str(int num)
{
    int len = get_num_length(num);
    int is_negative = 0;
    char *str;

    handle_negative(&num, &is_negative);
    str = allocate_str(len, is_negative);
    if (!str)
        return NULL;
    convert_to_str(num, str, len, is_negative);
    add_negative_sign(str, is_negative);
    return str;
}
