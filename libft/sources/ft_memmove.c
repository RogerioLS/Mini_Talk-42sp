/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:17:59 by roglopes          #+#    #+#             */
/*   Updated: 2023/08/20 14:53:05 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char			*cdest;
	char			*csrc;
	unsigned int	i;

	cdest = (char *)dest;
	csrc = (char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (cdest > csrc)
	{
		while (len-- > 0)
		{
			cdest[len] = csrc[len];
		}
	}
	else
	{
		while (i < len)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}
