/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:22:42 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/10 14:17:07 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the number of nodes in a list

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// int main()
// {
//     // Creating a linked list with 3 nodes
//     t_list *node1;
//     t_list *node2;
//     t_list *node3;
//     t_list *list = NULL;
//     int size;

// 	node1 = ft_lstnew("hello");
// 	node2 = ft_lstnew("cavalo");
// 	node3 = ft_lstnew("amarelo");

// 	list = node1;
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     if (!node1 || !node2 || !node3)
//     {
//         printf("Memory allocation failed.\n");
//         return (1);
//     }
//     size = ft_lstsize(list);
//     printf("Size of the list: %d\n", size);
// 	free(list);
// 	return (0);
// }