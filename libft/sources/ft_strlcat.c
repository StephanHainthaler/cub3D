/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:04:19 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/12 14:54:53 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	destlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = destlen;
	j = 0;
	while (src[j] != '\0' && n > (i + 1))
		dest[i++] = src[j++];
	dest[i] = '\0';
	if (n > destlen)
		len = destlen + srclen;
	else
		len = n + srclen;
	return (len);
}
/*
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

//compile using -lbsd

int	main(void)
{
	char    dest1[100] = "H";
	char    dest2[100] = "H";
	char	src[] = "ello";

	printf("String 1: %s\n", dest1);
	printf("String 2: %s\n", src);

	printf("Result_strlcat: %zu\n", strlcat(dest1, src, 9));
	printf("Result_ft_strlcat: %zu\n", ft_strlcat(dest2, src, 9));

	return (0);
}
*/