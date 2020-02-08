#include "utils.h"

char        *convert_decimal_to_binary(long long c, long long length)
{
    char    *str;
    int     index;
    int     power_of_two;
    char    *prepand;

    power_of_two = 1;
    index = 1;
    while (power_of_two < c)
    {
        ++index;
        power_of_two *= 2;
    }
    str = malloc(sizeof(char) * (index + 1));
    str[index] = '\0';
    index = 0;
    while (power_of_two)
    {
        str[index++] = (c >= power_of_two) ? '1' : '0';
        if (c >= power_of_two)
            c -= power_of_two;
        power_of_two /= 2;
    }
    if (length > (int)ft_strlen(str))
    {
        prepand = ft_bchar(length - ft_strlen_md5(str), '0');
        str = ft_update(str, ft_strjoin(prepand, str));
        free(prepand);
    }
    return (str);
}

char        *convert_srting_to_binary(char *string)
{
    char    *binary_string;
    char    *binary_char;
    int     i;
  
    i = -1;
    binary_string = ft_strnew(1);
    while (string[++i])
    {
        binary_char = convert_decimal_to_binary((int)string[i], 8);
        binary_string = ft_update(binary_string, ft_strjoin(binary_string, binary_char));
        free(binary_char);
    }
    return (binary_string);
}