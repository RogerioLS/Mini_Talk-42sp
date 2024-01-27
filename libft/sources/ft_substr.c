/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:07:34 by roglopes          #+#    #+#             */
/*   Updated: 2023/08/20 15:52:20 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	length;
	char	*sub_string;

	length = ft_strlen(s);
	count = 0;
	if (s == NULL)
		return (NULL);
	if (start >= length)
		return (ft_strdup(""));
	if (length - start < len)
		len = length - start;
	sub_string = malloc((len + 1) * sizeof(char));
	if (sub_string == NULL)
		return (NULL);
	while (len--)
	{
		sub_string[count] = s[start];
		count++;
		start++;
	}
	sub_string[count] = '\0';
	return (sub_string);
}
