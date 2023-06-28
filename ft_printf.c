/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:46:34 by jaisanch          #+#    #+#             */
/*   Updated: 2023/06/28 17:15:47 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, char format)
{
	int	value;

	value = 0;
	if (format == 'c')
		value += ft_printchar(va_arg(args, int));
	else if (format == 's')
		value += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		value += ft_printf_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		value += ft_printf_nbr(va_arg(args, int));
	else if (format == 'u')
		value += ft_printf_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		value += ft_printf_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		value += ft_putchar('%');
	return (value);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	args;
	int		value;

	i = 0;
	value = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			value += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			value += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (value);
}
