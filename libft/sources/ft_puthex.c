/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:32:49 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/28 21:37:55 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_puthex_low(unsigned int n)
{
	int	count;

	count = 1;
	if (n > 15)
		count += ft_puthex_low(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_puthex_upper(unsigned int n)
{
	int	count;

	count = 1;
	if (n > 15)
		count += ft_puthex_upper(n / 16);
	ft_putchar("0123456789ABCDEF"[n % 16]);
	return (count);
}
