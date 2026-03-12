#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*pah;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		pah = ft_lstnew(f(lst->content));
		if (!pah)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, pah);
		lst = lst->next;
	}
	return (res);
}
