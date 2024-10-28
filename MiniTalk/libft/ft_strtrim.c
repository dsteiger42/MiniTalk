/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:23:18 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/08 18:47:31 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strtrim removes any characters of the given set from
	the beginning and end of the given string s1, and allocates sufficient
	memory to store the trimmed copy of the string.

	RETURN VALUE :
	A pointer to the trimmed copy of the string.
	NULL if the memory allocation fails.
*/

int	is_char(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*dest;

	i = 0;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && is_char(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_char(set, s1[end - 1]))
		end--;
	dest = (char *)malloc(end - start + 1);
	if (!dest)
		return (NULL);
	while (start < end)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char *test;

// 	test = ft_strtrim("12345abc123456", "1234567890");
// 	printf("%s\n", test);
// 	free(test);
// }