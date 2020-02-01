#include "ft_ssl.h"

void    print_help()
{
    ft_printf("usage: ./ft_ssl [md5/sha256] [command args]\n");
}

void    error_invalid_command(char *command)
{
    ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", command);
    ft_printf("Standard commands:\n\n");
    ft_printf("\tMessage Digest commands:\n\t- md5\n\t- sha256\n");
}

void    error_illegal_option(char *option)
{
    ft_printf("ft_ssl: illegal option -- %c\n", option[1]);
    ft_printf("usage: ./ft_ssl md5 [-pqr] [-s string] [files ...]\n");
}

void    error_requires_argument(char *option)
{
    ft_printf("ft_ssl: option requires an argument -- %c\n", option[1]);
    ft_printf("usage: ./ft_ssl md5 [-pqr] [-s string] [files ...]\n");
}