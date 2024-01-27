/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:01:47 by roglopes          #+#    #+#             */
/*   Updated: 2023/08/20 14:49:21 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalnum(int argument)
{
	if ((argument >= 'A' && argument <= 'Z') || \
		(argument >= 'a' && argument <= 'z') || \
		(argument >= '0' && argument <= '9'))
		return (1);
	else
		return (0);
}
