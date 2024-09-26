/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:19:30 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/13 14:05:06 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destptr;
	unsigned char		*srcptr;

	if (dest == NULL || src == NULL)
		return (NULL);
	destptr = (unsigned char *)dest;
	srcptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destptr[i] = srcptr[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char    *dest1;
		char	*dest2;
		char	*src;
		char	*res1;
		char	*res2;

		dest1 = argv[1];
		dest2 = argv[1];
		src = argv[2];

		printf("String 1: %s\n", dest1);
		printf("String 2: %s\n", src);

		res1 = memcpy(dest1, src, atoi(argv[3]));
		res2 = ft_memcpy(dest2, src, atoi(argv[3]));

		printf("Result_memcpy: %s\n", res1);
		printf("Result_ft_memcpy: %s\n", res2);
	}
	return (0);
}
*/