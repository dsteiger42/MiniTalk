/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:16:01 by dsteiger          #+#    #+#             */
/*   Updated: 2024/04/29 20:58:02 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strncmp compares the first n bytes of the given strings
	s1 and s2.

	RETURN VALUE :
	An integer less than, equal to, or greater than zero if one of the first
	n bytes of s1 is found to be less than, to match, or to be greater than
	s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && (str1[i] || str2[i]) && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

// int	main(void)
// {
// 	printf("%d\n", ft_strncmp("", "yest2", 5));
// 	return (0);
// }
