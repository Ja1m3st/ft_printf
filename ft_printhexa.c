/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:01 by jaisanch          #+#    #+#             */
/*   Updated: 2023/06/27 17:16:56 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(size_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

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

int	ft_printhexa(unsigned long long ptr)
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
