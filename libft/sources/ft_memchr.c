/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:14:17 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/12 17:03:39 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*strptr;
	unsigned char	to_find_c;

	strptr = (unsigned char *)str;
	to_find_c = (unsigned char)c;
	if ((int)n <= 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (strptr[i] == to_find_c)
			return (&strptr[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char	*res1;
		char	*res2;

		printf("String: %s\n", argv[1]);
		
		res1 = memchr(argv[1], 'o', atoi(argv[2])*sizeof(char));
		printf("memchr: %s\n", res1);

		res2 = ft_memchr(argv[1], 'o', atoi(argv[2])*sizeof(char));
		printf("ft_memchr: %s\n", res2);
		return (0);
	}
}
*/