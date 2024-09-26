/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:53:28 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/12 17:28:35 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1ptr;
	unsigned char	*str2ptr;

	str1ptr = (unsigned char *)str1;
	str2ptr = (unsigned char *)str2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < (n - 1))
	{
		if (str1ptr[i] != str2ptr[i])
			return (str1ptr[i] - str2ptr[i]);
		i++;
	}
	return (str1ptr[i] - str2ptr[i]);
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
		
		res1 = memcmp(argv[1], argv[2], atoi(argv[3]));
		res2 = ft_memcmp(argv[1], argv[2], atoi(argv[3]));

		printf("Result (memcmp): %i\n", res1);
		printf("Result (ft_memcmp): %i\n", res2);
	}
}
*/
