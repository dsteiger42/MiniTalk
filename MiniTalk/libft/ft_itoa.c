/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:59:18 by dsteiger          #+#    #+#             */
/*   Updated: 2024/04/30 14:59:00 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int to str

int	length(long int nb)
{
	long int	len;

	len = 1;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb / 10 > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*dest;
	long int	nb;
	int			len;

	nb = n;
	len = length(nb);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	len--;
	if (nb < 0)
	{
		dest[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		dest[0] = '0';
	while (nb > 0 && len >= 0)
	{
		dest[len] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	*test;

// 	test = ft_itoa(0);
// 	printf("%s\n", test);
// 	free(test);
// 	return (0);
// }