/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:03:09 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/20 18:11:20 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memmove copies n bytes from memory area src to memory
	area dst. The memory areas may overlap: if the dst pointer is found
	to be between the src pointer and the index n, copying will be done
	back to front to prevent data being modified before being copied.
	Otherwise it will be done front to back	to preserve data.

	RETURN VALUE :
	A pointer to dst.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*new;
	const unsigned char	*temp;

	if (src == dest)
		return (dest);
	temp = (const unsigned char *)src;
	new = (unsigned char *)dest;
	if (temp < new)
	{
		while (n-- > 0 && (src || dest))
			new[n] = temp[n];
		return (dest);
	}
	else
		ft_memcpy(dest, src, n);
	return (new);
}
// int	main(void)
// {
// 	char src[] = "cavalo";
// 	char dest[] = "madeira";

// 	printf("%s\n", ft_memmove(dest, src, 3));
// 	return (0);
// }
