/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:50:49 by roglopes          #+#    #+#             */
/*   Updated: 2023/08/20 14:45:08 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalpha(int argument)
{
	if ((argument >= 'A' && argument <= 'Z'))
		return (1);
	else if
		((argument >= 'a' && argument <= 'z'))
		return (1);
	else
		return (0);
}
