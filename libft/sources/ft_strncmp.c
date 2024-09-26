/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:58:14 by shaintha          #+#    #+#             */
/*   Updated: 2024/06/17 10:46:31 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int					res;
	unsigned char		*str1ptr;
	unsigned char		*str2ptr;
	size_t				i;

	str1ptr = (unsigned char *)str1;
	str2ptr = (unsigned char *)str2;
	res = 0;
	if (n == 0)
		return (0);
	i = 0;
	while ((str1ptr[i] != '\0' || str2ptr[i] != '\0') && i < n)
	{
		if (str1ptr[i] != str2ptr[i])
		{
			res = str1ptr[i] - str2ptr[i];
			return (res);
		}
		i++;
	}
	return (res);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		int	res1;
		int	res2;
		
		printf("String 1: %s\n", argv[1]);
		printf("String 2: %s\n", argv[2]);
		
		res1 = strncmp(argv[1], argv[2], atoi(argv[3]));
		res2 = ft_strncmp(argv[1], argv[2], atoi(argv[3]));

		printf("Result_strncmp: %i\n", res1);
		printf("Result_ft_strncmp %i\n", res2);
	}
}
*/