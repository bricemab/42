#include <stdio.h>
#include "stdlib.h"

static int  count_nbr(int n)
{
    int     i;

    i = 1;
    if (n < 0)
        n *= -1;
    while (n > 10)
    {
        n = n / 10;
        i++;
    }
    return (i);
}

static char*    write_number(int nbr, char *str)
{
    int index;

    index = 0;
    if (nbr < 0)
        nbr *= -1;

    while (nbr > 10)
    {
        str[index] = (nbr % 10) + '0';
        index++;
        nbr = nbr / 10;

    }
    str[index] = (nbr % 10) + '0';
    str[index+1] = '\0';
    return (str);
}

static  char*   reverse_str(const char *str, int length, int initial_number)
{
    int     i;
    int     init;
    char    *string;

    i = 0;
    string = malloc(sizeof(char) * (length + 2));
    if (string == NULL)
        return (NULL);
    init = length;
    if (initial_number < 0)
    {
        init++;
        string[i] = '-';
        i++;
    }
    while (i < init)
    {
        string[i] = str[length - 1];
        length--;
        i++;
    }
    string[i] = '\0';
    return (string);
}

char    *ft_itoa(int n)
{
    char    *str = NULL;
    int     i;

    if (n == -2147483648)
        return ("-2147483648");
    i = count_nbr(n);
    str = malloc(sizeof(char) * (i + 2));
    if (str == NULL)
        return (NULL);
    str = write_number(n, str);
    str = reverse_str(str, i, n);
    return (str);
}

int main() {
    printf("%s\n", ft_itoa(2147483647));
    printf("%s\n", ft_itoa(-2147483648));
    return 0;
}
