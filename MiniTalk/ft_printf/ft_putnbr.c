/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:01:02 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/10 13:53:27 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(long int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
		len += print_int(nb);
	}
	else if (nb > 9)
	{
		len += print_int(nb / 10);
		len += print_int(nb % 10);
	}
	else
	{
		nb = nb + 48;
		len += write(1, &nb, 1);
	}
	return (len);
}

int	print_uint(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += print_uint(nb / 10);
		len += print_uint(nb % 10);
	}
	if (nb <= 9)
	{
		nb = nb + 48;
		len += write(1, &nb, 1);
	}
	return (len);
}
