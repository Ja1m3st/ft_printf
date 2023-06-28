/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:19:09 by jaisanch          #+#    #+#             */
/*   Updated: 2023/06/28 16:46:25 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_array(char *str, unsigned int number, long int len)
{
	while (number > 0)
	{
		str[len--] = 48 + (number % 10);
		number /= 10;
	}
	return (str);
}

long int	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		len = 1;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	long int		len;
	char			*str;
	unsigned int	number;

	len = ft_len(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		number = nb * -1;
		str[0] = '-';
	}
	else
		number = nb;
	str = ft_array(str, number, len);
	return (str);
}

int	ft_printf_nbr(int nb)
{
	char	*num;
	int		len;

	num = ft_itoa(nb);
	len = ft_printstr(num);
	free(num);
	return (len);
}
