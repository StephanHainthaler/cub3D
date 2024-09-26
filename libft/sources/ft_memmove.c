/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:07:37 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/13 16:47:13 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destptr;
	unsigned char	*srcptr;
	size_t			size;
	size_t			i;

	if (dest == NULL || src == NULL)
		return (NULL);
	destptr = (unsigned char *)dest;
	srcptr = (unsigned char *)src;
	size = n;
	i = 0;
	while (i < n)
	{
		if (destptr > srcptr)
		{
			destptr[size - 1] = srcptr[size - 1];
			size--;
		}
		else
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

		res1 = memmove(dest1, src, atoi(argv[3]));
		printf("Result_memmove: %s\n", res1);

		res2 = ft_memmove(dest2, src, atoi(argv[3]));
		printf("Result_ft_memmove: %s\n", res2);
	}
	return (0);
}
*/