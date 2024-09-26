/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:54 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/11 16:19:02 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

bool	ft_isalnum(int c)
{
	if (ft_isalpha(c) == true || ft_isdigit(c) == true)
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
		int alnum = 0;
		int i;

		str = argv[1];
		i = 0;
		while (str[i])
		{
			if (ft_isalnum(str[i]) != 0)
				alnum++;
			i++;
		}
		printf("Alphabethic Letters & Digits: %d\n", alnum);
	}
	return (0);
}
*/
