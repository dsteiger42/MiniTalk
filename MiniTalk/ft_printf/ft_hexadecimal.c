/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:00:21 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/09 18:09:56 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned long int nb)
{
	int		len;
	char	*symbols;

	len = 0;
	symbols = "0123456789abcdef";
	if (nb >= 16)
	{
		len += print_hexa(nb / 16);
		len += print_hexa(nb % 16);
	}
	else
		len += print_char(symbols[nb]);
	return (len);
}

int	print_upperhexa(unsigned long int nb)
{
	int		len;
	char	*symbols;

	len = 0;
	symbols = "0123456789ABCDEF";
	if (nb >= 16)
	{
		len += print_upperhexa(nb / 16);
		len += print_upperhexa(nb % 16);
	}
	else
		len += print_char(symbols[nb]);
	return (len);
}

int	print_ptr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (!nb)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	else
	{
		len += write(1, "0x", 2);
		len += print_hexa(nb);
	}
	return (len);
}
