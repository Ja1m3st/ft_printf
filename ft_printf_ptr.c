/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:01 by jaisanch          #+#    #+#             */
/*   Updated: 2023/06/28 16:29:33 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(size_t ptr)
{
	if (ptr >= 16)
	{
		ft_convert(ptr / 16);
		ft_convert(ptr % 16);
	}
	else if (ptr <= 9)
	{
		ft_putchar(ptr + '0');
	}
	else
	{
		ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (ptr == 0)
	{
		i += write(1, "0", 1);
	}
	else
	{
		ft_convert(ptr);
		i += ft_ptrlen(ptr);
	}
	return (i);
}
