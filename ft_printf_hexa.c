/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:08:29 by jaisanch          #+#    #+#             */
/*   Updated: 2023/06/28 16:40:09 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_to_hexa(size_t nb, char format)
{
	if (nb >= 16)
	{
		ft_to_hexa(nb / 16, format);
		ft_to_hexa(nb % 16, format);
	}
	else if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		if (format == 'x')
			ft_putchar(nb - 10 + 'a');
		else if (format == 'X')
			ft_putchar(nb - 10 + 'A');
	}
}

int	ft_printf_hexa(unsigned int nb, char format)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		i += write(1, "0", 1);
	}
	else
	{
		ft_to_hexa(nb, format);
		i += ft_ptrlen(nb);
	}
	return (i);
}
