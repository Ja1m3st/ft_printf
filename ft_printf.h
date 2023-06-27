/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaisanch <jaisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:55:24 by jaisanch          #+#    #+#             */
/*   Updated: 2023/06/27 18:44:05 by jaisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_printhexa(unsigned long long ptr);
int	ft_printnbr(int nb);
int	ft_printstr(char *str);
int	ft_print_unsigned(unsigned int nb);
int	ft_printporcent(void);

#endif