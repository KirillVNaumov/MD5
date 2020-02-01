#include "ft_ssl.h"

int     main(int argc, char **argv)
{
    if (argc == 1)
        print_help();
    else
    {
        if (!ft_strcmp(argv[1], "md5"))
            md5(&argv[2]);
        else if (!ft_strcmp(argv[1], "sha256"))
            sha256(&argv[2]);
        else
            error_invalid_command(argv[1]);
    }
    return (1);
}