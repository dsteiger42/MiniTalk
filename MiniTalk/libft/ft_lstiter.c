/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:56:05 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/08 18:42:20 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates the list ’lst’ and applies the function /
// ’f’ on the content of each node
// 24 - updates de pointer lst to point to the next node

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// void upper(void *content)
// {
//     char *c = (char *)content;
//     if (*c >= 'a' && *c <= 'z')
//         c -= 32;
// }

// int main()
// {
// 	t_list *node;

// 	node = ft_lstnew("eheeheh");
// 	if (!node)
// 	{
// 		printf("memory allocation failed, the new node wasn't created\n");
// 		return (1);
// 	}
// 	printf("New node was created: %s\n", node
// 		-> content);
// 	ft_lstiter(node, upper);
// 	free(node);
// 	return (0);
// }