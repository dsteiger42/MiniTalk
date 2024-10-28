/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:01:46 by dsteiger          #+#    #+#             */
/*   Updated: 2024/06/14 17:02:33 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	int	len;

	len = 0;
	len += write(1, &c, 1);
	return (len);
}

int	print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	while (*str)
		len += write(1, str++, 1);
	return (len);
}
