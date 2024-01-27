/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:00:56 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/28 21:38:04 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr(int number)
{
	long int	nb;
	int			count;

	count = 1;
	nb = number;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (count);
}
