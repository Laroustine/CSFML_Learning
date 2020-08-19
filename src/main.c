/*
** EPITECH PROJECT, 2020
** CSFML_Good_Practice
** File description:
** main
*/

#include <stdio.h>

static int check_error(int argc, char const *argv[])
{
    if (argc != 1 || argv == NULL)
        return (84);
    return (0);
}

static int display_error(int error_code)
{
    if (error_code)
        printf("The program as ended with the error code : %d\n", error_code);
    return (error_code);
}

static int core(int argc, char const *argv[])
{
    return (0);
}

int main(int argc, char const *argv[])
{
    int error_code = check_error(argc, argv);

    if (error_code)
        return (display_error(error_code));
    return (core(argc, argv));
}
