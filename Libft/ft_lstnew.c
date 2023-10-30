#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *c;

    c = malloc(sizeof(c));
    if (!c)
        return (NULL);
    c->content = content;
    c->next = NULL;
    return (c);
}