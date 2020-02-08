#include "ft_ssl.h"

// void        append_padding(char **binary_rep)
// {

// }

// void        process_into_hash_md5(char **binary_rep)
// {
    
// }

void        append_length(char **binary_rep, char *string)
{
    char    *length_binary;

    length_binary = convert_decimal_to_binary(ft_strlen_md5(string), 64); // make modulo 2**64
    (*binary_rep) = ft_update((*binary_rep), ft_strjoin((*binary_rep), length_binary));
    free(length_binary);
}

char        *transform_md5(char *string)
{
    char    *binary_rep;
    
    if (!string)
        return (ft_strdup("d41d8cd98f00b204e9800998ecf8427e"));
    binary_rep = convert_srting_to_binary(string);

    // append_padding(&binary_rep);
    // append_length(&binary_rep, string);
    // return (process_into_hash_md5(&binary_rep));
    return (binary_rep);
}

void        md5(char **args)
{
    int     index;
    t_md5   flags;
    char    *transformation;

    index = 0;
    while (args[index])
    {
        if (!ft_strcmp(args[index], "-r"))
            flags.flag_r = 1;
        else if (!ft_strcmp(args[index], "-q"))
            flags.flag_q = 1;
        else if (!ft_strcmp(args[index], "-p"))
            flags.flag_p = 1;
        else if (args[index][0] && args[index][0] == '-' && \
                 args[index][1] && args[index][1] == 's')
        {
            if (args[index][2])
                transformation = transform_md5(&args[index][2]);
            else if (args[index + 1])
                transformation = transform_md5(args[++index]);
            else
                error_requires_argument(args[index]);
            ft_printf("'%s' - %d - %s\n", args[index], ft_strlen_md5(transformation), transformation);
            free (transformation);
        }
        else
            error_illegal_option(args[index]);
        ++index;
    }
}