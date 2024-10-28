/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:14:01 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/08 18:42:30 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Takes as a parameter a node and frees the memory of /
// the node’s content using the function

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	else
	{
		del(lst->content);
		free(lst);
	}
}

// void del_content(void *content)
// {
//     free(content);
// }

// int main() {
//     t_list *node = malloc(sizeof(t_list)); // Create a new node
//     node->content = malloc(sizeof(int)); // Allocate memory for content
//     *(int *)(node->content) = 42; // Assign some data to the content
//     node->next = NULL; // Set next pointer to NULL as it's the only node

//     // Delete the content of the node
//     ft_lstdelone(node, del_content); 
//     return (0);
// }

// funcao *del aponta para a funcao que /
//foi passada como 2o argumneto (del_content)
// funcao del_content liberta o espaco