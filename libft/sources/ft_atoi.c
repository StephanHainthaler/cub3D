/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:36:06 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/12 16:39:07 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	minus;
	int	i;

	res = 0;
	minus = 0;
	i = 0;
	while (ft_isspace(str[i]) == true)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (minus == 1)
		res = res * -1;
	return (res);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int	n1;
		int	n2;

		n1 = atoi(argv[1]);
		n2 = ft_atoi(argv[1]);
		
		printf("atoi: %d\n", n1);
		printf("ft_atoi: %d\n", n2);
	}
	return (0);
}
*/
