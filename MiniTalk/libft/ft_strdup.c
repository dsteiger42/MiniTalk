/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:25:15 by dsteiger          #+#    #+#             */
/*   Updated: 2024/04/24 12:30:30 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strdup duplicates the given string s1 by allocating 
	memory and performing a copy of the given string.

	RETURN VALUE :
	A pointer to the new string. NULL if the memory allocation fails.
*/

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	return (dest);
}
// int main() {
//     const char *original = "Hello, world!";
//     char *duplicate = ft_strdup(original);

//     if (duplicate) {
//         printf("Original string: %s\n", original);
//         printf("Duplicate string: %s\n", duplicate);
//         free(duplicate);
//     }

//     return (0);
// }