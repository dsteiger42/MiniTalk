/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:17:37 by dsteiger          #+#    #+#             */
/*   Updated: 2024/04/24 12:18:44 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// transform characters into null bytes

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	s1 = str;
	while (i < n)
		s1[i++] = '\0';
}
// int main()
// {
// 	char test[] = "testing string";
// 	printf("before function: %s\n", test);
// 	ft_bzero (test, 14);
// 	printf("after function: %s\n", test);
// }