/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:54:40 by roglopes          #+#    #+#             */
/*   Updated: 2023/08/20 14:53:05 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_string;
	int		count;
	int		length_string_s1;
	int		length_string_s2;

	length_string_s1 = ft_strlen(s1);
	length_string_s2 = ft_strlen(s2);
	join_string = malloc((length_string_s1 + length_string_s2 + 1));
	if (s1 == NULL || s2 == NULL || join_string == NULL)
		return (NULL);
	count = 0;
	while (s1[count] != '\0')
	{
		join_string[count] = s1[count];
		count++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		join_string[length_string_s1 + count] = s2[count];
		count++;
	}
	join_string[length_string_s1 + length_string_s2] = '\0';
	return (join_string);
}
