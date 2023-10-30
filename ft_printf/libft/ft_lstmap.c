#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list	*list;
    t_list	*new;

    if (!f || !del)
        return (NULL);
    while (lst)
    {
        if (!(new = ft_lstnew((*f)(lst->content))))
        {
            ft_lstclear(&list, *del);
            return (NULL);
        }
        ft_lstadd_back(&list, new);
        lst = lst->next;
    }
    return (list);
}