/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:30:18 by roglopes          #+#    #+#             */
/*   Updated: 2023/08/20 14:53:05 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	unsigned int	length;
	char			*str;

	count = 0;
	length = ft_strlen(s);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (s == NULL || f == NULL || str == NULL)
		return (NULL);
	while (count < length)
	{
		str[count] = (*f)(count, s[count]);
		count++;
	}
	str[length] = '\0';
	return (str);
}
