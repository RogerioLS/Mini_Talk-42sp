/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:08:17 by roglopes          #+#    #+#             */
/*   Updated: 2023/08/20 14:53:05 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	word_count;
	int	count;

	word_count = 0;
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] != c)
		{
			word_count++;
			while (s[count] != '\0' && s[count] != c)
				count++;
		}
		else
			count++;
	}
	return (word_count);
}

static void	*ft_free_split(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		count++;
	}
	free(arr);
	return (NULL);
}

static char	**ft_put_word(char **words, char const *s, char c)
{
	size_t	length;
	size_t	count;

	count = 0;
	while (*s)
	{
		length = 0;
		while (s[length] != c && s[length])
			length++;
		words[count] = (char *)malloc(length * sizeof(char) + 1);
		if (words[count] == NULL)
			return (ft_free_split(words));
		words[count][length] = '\0';
		while (length > 0)
		{
			words[count][length - 1] = s[length - 1];
			length--;
		}
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		count++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		word_length;

	if (s == NULL)
		return (NULL);
	word_length = ft_count_word(s, c);
	new = (char **)malloc(sizeof(char *) * (word_length + 1));
	if (new == NULL)
		return (NULL);
	while (*s == c && *s)
		s++;
	new = ft_put_word(new, s, c);
	new[word_length] = NULL;
	return (new);
}
