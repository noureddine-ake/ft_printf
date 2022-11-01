/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:34:00 by nakebli           #+#    #+#             */
/*   Updated: 2022/11/01 21:29:49 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_check(char c, int *len, void *value)
{
	if (c == 'c')
		ft_putchar((char)value,len);
	else if (c == 's')
		ft_putstr((char *)value, len);
	else if (c == 'p')
	{
		ft_putstr("0x",len);
		ft_printphd((unsigned long)value, len);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr((int)value,len);
	if (c == 'u')
		ft_putnbr((int)value,len);
	else if (c == 'x' || c == 'X')
		ft_puthexadecimal((int)value, c, len);
}

int ft_printf(const char *format, ...)
{
	int     i;
	int len;

	len = 0;
	va_list lst;
	va_start(lst, format);
	i = 0;
	while (format[i])
	{
		if(format[i] == '%')
		{
			i++;
			if (format[i] != '%')
			{
				ft_check(format[i],&len,va_arg(lst,void *));
			}
			else
				ft_putchar('%',&len);
		}
		else
			ft_putchar(format[i],&len);
		i++;
	}
	va_end(lst);
	return (len);
}