/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:20:53 by roglopes          #+#    #+#             */
/*   Updated: 2023/08/20 14:53:05 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		if (s[length] == (unsigned char) c)
			return ((char *)s + length);
		length++;
	}
	if (s[length] == (unsigned char) c)
		return ((char *) s + length);
	return (NULL);
}
