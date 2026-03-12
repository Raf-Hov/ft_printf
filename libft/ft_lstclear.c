#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		prev = *lst;
		*lst = (*lst)->next;
		del(prev->content);
		free(prev);
	}
	*lst = NULL;
}
