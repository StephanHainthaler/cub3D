/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:14:07 by shaintha          #+#    #+#             */
/*   Updated: 2023/12/18 09:14:08 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

bool	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]) == true)
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (false);
			i++;
		}
		if (str[i] != '\0')
			return (false);
	}
	return (true);
}
