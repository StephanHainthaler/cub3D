/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:49:10 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/12 12:01:10 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && i < (n - 1) && n != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
		dest[i] = '\0';
	return (len);
}
/*
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

//compile using -lbsd

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char    *dest1 = argv[1];
		char	*dest2 = argv[1];
		char	*src1 = argv[2];
 		char	*src2 = argv[2];
		size_t	n = atoi(argv[3]);	

		printf("String 1: %s\n", dest1);
		printf("String 2: %s\n", src2);

		printf("Result of strlcpy: %zu\n", strlcpy(dest1, src1, n));
		printf("dest1 after strlcpy: %s\n", dest1);
		printf("src1 after strlcpy: %s\n", src1);

		printf("Result of ft_strlcpy: %zu\n", ft_strlcpy(dest2, src2, n));
		printf("dest2 after ft_strlcpy: %s\n", dest2);
		printf("src2 after ft_strlcpy: %s\n", src2);
	}
	return (0);
}
*/