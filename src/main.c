/*
** LAROUS PROJECT, 2020
** CSFML_Good_Practice
** FiIe description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "core.h"

static int check_error(int argc, char const *argv[])
{
    if (argc == 2 && !strcmp("-h", argv[1]))
        return (-1);
    if (argc != 1 || argv == NULL)
        return (84);
    return (0);
}

static int display_help(int argc, char const *argv[])
{
    if (argc == 0)
        return (84);
    printf("USAGE:\n\t%s\n\n", argv[0]);
    printf("DESCRIPTION:\n\t\n");
    return (0);
}

static int display_error(int error_code, int argc, char const *argv[])
{
    if (error_code == -1)
        error_code = display_help(argc, argv);
    if (error_code > 0)
        printf("The program as ended with the error code : %d\n", error_code);
    return (error_code);
}

int main(int argc, char const *argv[])
{
    int error_code = check_error(argc, argv);

    if (error_code)
        return (display_error(error_code, argc, argv));
    return (core(argc, argv));
}
