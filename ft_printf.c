/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesanchez <jaimesanchez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:59:23 by jaisanch           #+#    #+#           */
/*   Updated: 2022/12/14 09:57:49 by jaisanch          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int ft_printchar(char c){
	write(1, &c, 1);
	return 1;
}

int ft_printstr(char *str){
	int i;

	i = 0;
	while (str[i] != 0){
		write(1, &str[i], 1);
		i++;
	}
	return i;
}

void ft_convert(size_t ptr){
	if (ptr >= 16){
		ft_convert(ptr%16);
		ft_convert(ptr/16);
	}
	else if ( ptr <= 9 ){
		ft_printchar(ptr + '0');
	}
	else {
		ft_printchar(ptr - 10 + 'a');
	}
}

int ft_printhexa(unsigned long long ptr){
	int i;

	i = 0;
	i += write(1, "0x", 2);
	if (ptr == 0){
		i += write(1, "0", 1);
	}
	else{
		ft_convert(ptr);
	}
	return (i);
}

int ft_formats(va_list args, char format){
	int value;

	value = 0;
	if (format == 'c'){
		value += ft_printchar(va_arg(args, int));
	}
	else if (format == 's'){
		value += ft_printstr(va_arg(args, char *));
	}
	else if (format == 'p'){
		value += ft_printhexa(va_arg(args, unsigned long long));
	}
	return value;
}



int	ft_printf(char const *str, ...)
{
	int i;
	va_list args;
	int value;

	i = 0;
	value = 0;
	va_start(args, str);
	while (str[i] )
	{
		if (str[i] == '%')
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


int main(){
	// char c;
	// char *str;

	// str = "Hola que tal";
	// c = 'a';
	ft_printf("%c %c", '1', '2');
}

