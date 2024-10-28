/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:19:19 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/14 14:01:52 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	void	*content;

	newlst = NULL;
	node = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}

// static void del(void *content)
// {
// 	free(content);
// }

// static void	*upper(void *content)
// {
// 	char	*c;

// 	c = (char *)content;
// 	while (*c != '\0')
// 	{
// 		if (*c >= 'a' && *c <= 'z')
// 			*c -= 32;
// 		c++;
// 	}
// 	return (c);
// }

// int	main(void)
// {
// 	t_list *lst = NULL;
// 	t_list *node1 = ft_lstnew("A faZEr A mAiN dIA VINTE e um\n");
// 	void *content = lst->content;

// 	lst = node1;
// 	if(!node1)
// 	{
// 		printf("Memory allocation failed, the node wasn't created\n");
// 		return (1);
// 	}
// 	printf("The node was created and its content before lstmap is: %p\n",
// 		content);
// 	lst = ft_lstmap(lst, &upper, &del); // Remova o & antes de lst
// 	printf("The content of the list after lstmap is: %p\n", content);
// 		// Adicione uma vírgula aqui
// 	free(lst); // Liberar a lista após seu uso
// 	return (0);
// } 