/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:33:14 by dsteiger          #+#    #+#             */
/*   Updated: 2024/06/20 13:27:54 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	variable_types(char type, va_list *ap)
{
	int	i;

	i = 0;
	if (type == 'c')
		i += print_char(va_arg(*ap, int));
	else if (type == 's')
		i += print_str(va_arg(*ap, char *));
	else if (type == 'p')
		i += print_ptr(va_arg(*ap, unsigned long int));
	else if (type == 'd' || type == 'i')
		i += print_int(va_arg(*ap, int));
	else if (type == 'u')
		i += print_uint(va_arg(*ap, int));
	else if (type == 'x')
		i += print_hexa((long)va_arg(*ap, unsigned int));
	else if (type == 'X')
		i += print_upperhexa((long)va_arg(*ap, unsigned int));
	else if (type == '%')
		i += print_char('%');
	return (i);
}

static int	check_var_type(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (check_var_type(FLAGS, (*(format + 1))))
			{
				format++;
				len += variable_types(*format, &ap);
			}
			else if (*(++format) == '\0')
				return (-1);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (len);
}

// int	main(void)
// {
// 	printf("byte: %d\n", printf("%"));
// 	printf("byte: %d\n", ft_printf("%"));
// }
