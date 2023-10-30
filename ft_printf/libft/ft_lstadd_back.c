#include "libft.h"

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    t_list  *l;

    if (lst)
    {
        if (*lst)
        {
            l = ft_lstlast(*lst);
            l->next = new;
        }
        else
            *lst = new;
    }
}