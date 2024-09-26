/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:42:17 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/11 16:22:21 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

bool	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
		int print = 0;
		int i;

		str = argv[1];
		i = 0;
		while (str[i])
		{
			if (ft_isprint(str[i]) != 0)
				print++;
			i++;
		}
		printf("Printable Characters: %d\n", print);
	}
	return (0);
}
*/
