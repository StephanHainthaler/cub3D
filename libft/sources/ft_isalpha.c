/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:54:34 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/11 16:12:30 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

bool	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (true);
	else
		return (false);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char	*str;
		int	alpha = 0;
		int	i;

		str = argv[1];
		i = 0;
		while (str[i])
		{
			if (ft_isalpha(str[i]) != 0)
				alpha++;
			i++;
		}
		printf("Alphabethic Letters: %d\n", alpha);
	}
	return (0);
}
*/
