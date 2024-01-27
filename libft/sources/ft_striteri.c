/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:32:44 by roglopes          #+#    #+#             */
/*   Updated: 2023/08/20 14:53:05 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;

	count = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[count] != '\0')
	{
		(*f)(count, &s[count]);
		count++;
	}
	return ;
}
