/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:00:38 by jaisanch          #+#    #+#             */
/*   Updated: 2023/06/28 17:12:16 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

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

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		i += write(1, "(null)", 6);
	else
	{
		while (str[i] != 0)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}
