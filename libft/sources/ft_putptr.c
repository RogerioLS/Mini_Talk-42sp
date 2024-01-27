/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:42:28 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/28 21:38:21 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	ft_putptr(unsigned long nbr, int i)
{
	int	count;

	count = 1;
	if (nbr == 0)
		return (ft_putstr("(nil)"));
	if (i == 0)
	{
		ft_putstr("0x");
		count += 2;
	}
	if (nbr > 15)
		count += ft_putptr(nbr / 16, ++i);
	ft_putchar("0123456789abcdef"[nbr % 16]);
	return (count);
}
