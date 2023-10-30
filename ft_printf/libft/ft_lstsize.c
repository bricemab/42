#include "libft.h"

static int length(t_list *lst, int size)
{
    if (lst->next)
        return (length(lst, size+1));
    return (size);
}

int ft_lstsize(t_list *lst)
{
    return (length(lst, 0));
}