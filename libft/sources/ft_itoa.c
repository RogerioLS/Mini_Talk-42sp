/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:28:23 by roglopes          #+#    #+#             */
/*   Updated: 2023/08/20 14:53:05 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	ft_get_length(long nbr)
{
	int	length;

	length = 0;
	if (nbr <= 0)
		length++;
	while (nbr != 0)
	{
		length++;
		nbr = nbr / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	length;

	length = ft_get_length(n);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	result[length] = '\0';
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		length--;
		result[length] = ft_absolute_value(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
