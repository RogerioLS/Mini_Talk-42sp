/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:12:50 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/28 21:37:16 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	convert_params(char *str, int position, va_list args)
{
	int	count;

	count = 0;
	if (str[position] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (str[position] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (str[position] == 'p')
		count += ft_putptr(va_arg(args, unsigned long), 0);
	else if (str[position] == 'd' || str[position] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (str[position] == 'u')
		count += ft_putunsign(va_arg(args, unsigned long));
	else if (str[position] == 'x')
		count += ft_puthex_low(va_arg(args, unsigned long));
	else if (str[position] == 'X')
		count += ft_puthex_upper(va_arg(args, unsigned long));
	else if (str[position] == '%')
		count += ft_putchar('%');
	return (count);
}

static int	read_args(const char *str, va_list args)
{
	int	position;
	int	count;

	position = 0;
	count = 0;
	while (str[position] != '\0')
	{
		if (str[position] == '%')
		{
			position++;
			count += convert_params((char *)str, position, args);
		}
		else
			count += ft_putchar(str[position]);
		position++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		return_params;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	return_params = read_args(str, args);
	va_end(args);
	return (return_params);
}
