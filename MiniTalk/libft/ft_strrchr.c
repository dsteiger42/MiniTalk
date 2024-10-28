/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:35:13 by dsteiger          #+#    #+#             */
/*   Updated: 2024/04/29 20:42:43 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strrchr finds the last occurrence of character c in
	string str.

	RETURN VALUE :
	A pointer to the last occurrence of c in str.
	NULL if c is not found.
*/

char	*ft_strrchr(const char *str, int c)
{
	char	*s1;
	char	c1;
	int		i;

	i = 0;
	s1 = (char *)str;
	c1 = (char)c;
	while (s1[i])
		i++;
	while (i >= 0)
	{
		if (s1[i] == c1)
			return (s1 + i);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char c = 'r';
// 	char *str = "hjdshjdhjgrrkrkkkd\n";
// 	char	*result = ft_strrchr(str, c);

// 	printf("%s", result);
// 	return (0);
// }