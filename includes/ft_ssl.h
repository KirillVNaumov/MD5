#ifndef FT_SSL_H
# define FT_SSL_H

#include "utils.h"

/*
** Flag structures for hash functions
*/

typedef struct  s_md5 {
    int         flag_p;
    int         flag_q;
    int         flag_r;
}               t_md5;

/*
** Error Call Function
*/

void    print_help();
void    error_illegal_option(char *option);
void    error_invalid_command(char *command);
void    error_requires_argument(char *option);


/*
** Hash Functions
*/

void        md5(char **args);
void        sha256(char **args);

#endif