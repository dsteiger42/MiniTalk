/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:03:53 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/20 17:23:40 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memcpy copies n bytes from memory area src to memory
	area dst.
	Does not account for memory overlaps. Use ft_memmove if the memory areas
	overlap or might overlap.

	RETURN VALUE :
	A pointer to dst. NULL if src and dst are both NULL.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*new;
	const unsigned char	*old;
	size_t				i;

	i = 0;
	old = (const unsigned char *)src;
	new = (unsigned char *)dest;
	while (i < n && (dest || src))
	{
		new[i] = old[i];
		i++;
	}
	return (dest);
}
// int	main(void)
// {
// 	char src[] = "cavalo";
// 	char dest[] = "madeira";

// 	printf("%s\n", ft_memcpy(dest, src, 3));
// 	return (0);
// }