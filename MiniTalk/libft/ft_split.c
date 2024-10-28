/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:14:18 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/08 18:48:06 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words);
}

static char	*word_aloc(const char *str, char c)
{
	char	*dest;
	int		word_len;
	int		i;

	i = -1;
	word_len = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	dest = (char *)malloc(word_len + 1);
	if (!dest)
		return (NULL);
	while (++i < word_len)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

static void	*free_str(char **dest, int i)
{
	while (i >= 0)
		free(dest[i--]);
	free(dest);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	dest = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			dest[i] = word_aloc(s, c);
			if (!dest[i])
				return (free_str(dest, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	dest[i] = 0;
	return (dest);
}

// word_aloc function goes word by word
// After extracting a word, the function moves the 
// pointer s to the next character after the current word.
// 59 - frees each index of the string
// 60 - frees the memory for the array itself
// 70 - "**" bcs it stores an array of strings
// int	main(void)
// {
// 	int i = 0;
// 	const char *str = "";
// 	char delimiter = 'z';

// 	char **result = ft_split(str, delimiter);

// 	if (result)
// 	{
// 		while (result[i] != NULL)
// 		{
// 			printf("Substring %d: \"%s\"\n", i + 1, result[i]);
// 			i++;
// 		}
// 	}
// 	else
// 		printf("Memory allocation failed or input string is empty.\n");
// 	free_str(result, count_word(str , delimiter));
// 	return (0);
// }