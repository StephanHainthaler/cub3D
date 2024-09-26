/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:01:01 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/11 16:16:21 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char    *str;
		int n = 0;
		int i;

		str = argv[1];
		i = 0;
		while (str[i])
		{
			if (ft_isdigit(str[i]) != 0)
				n++;
			i++;
		}
		printf("Digits: %d\n", n);
	}
	return (0);
}
*/
