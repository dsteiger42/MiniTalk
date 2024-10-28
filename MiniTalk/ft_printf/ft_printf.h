/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:08:28 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/09 18:14:45 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define FLAGS "cspdiuxX%"

int	print_char(char c);
int	print_str(char *str);
int	print_ptr(unsigned long int nb);
int	print_int(long int n);
int	print_uint(unsigned int nb);
int	print_hexa(unsigned long int nb);
int	print_upperhexa(unsigned long int nb);
int	variable_types(char specifier, va_list *ap);
int	ft_printf(const char *format, ...);

#endif