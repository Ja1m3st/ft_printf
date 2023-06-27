/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:05:36 by jaisanch          #+#    #+#             */
/*   Updated: 2023/06/27 18:35:20 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	ft_ulen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nb)
{
	int		len;
	char	*str;

	len = ft_ulen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str[len] = '\0';
	while (nb != 0)
	{
		str[len - 1] = nb % 10 + 48;
		nb /= 10;
		len--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int nb)
{
	char	*num;
	int		len;

	len = 0;
	if (nb == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(nb);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}
