/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:21:28 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/14 18:26:38 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESRIPTION :
	The function ft_strmapi applies the given function f to each character
	in the given string s and allocates sufficient memory to store the
	resulting new string. 

	RETURN VALUE :
	A pointer to the newly created string. NULL if the memory allocation
	fails.	
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// 39 - f acessa ao idx e ao caracter em 's' no mesmo idx,
// 40 - e copia para o dest

// char	uppercase(unsigned int index, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 	{
// 		return (c - 32);
// 	}
// 	return (c);
// }

// int	main(void)
// {
// 	char *str = "teste St4InG";

// 	printf("Original string: %s\n", str);
// 	char *new_str = ft_strmapi(str, &uppercase);
// 	printf("Modified string: %s\n", new_str);
// 	free(new_str);
// 	return (0);
// }