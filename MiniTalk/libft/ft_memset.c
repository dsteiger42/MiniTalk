/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:40:02 by dsteiger          #+#    #+#             */
/*   Updated: 2024/04/24 17:20:13 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memset fills the first n bytes of the memory area
	pointed	to by str with the byte c.
	RETURN VALUE :
	A pointer to memory area s.
*/

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = str;
	while (i < n)
		mem[i++] = c;
	return (mem);
}
// int	main(void)
// {
// 	char src[] = "cavalo";
// 	int	c = 'z';

// 	printf("%s\n", ft_memset(src, c, 4));
// 	return (0);
// }