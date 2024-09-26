/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:56:07 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/14 10:31:34 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*str;
	unsigned char	*ptr;

	if (nmemb == 0)
		return (malloc(0));
	str = malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	ptr = (unsigned char *)str;
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
		char	*str1;
		char	*str2;
		size_t	nmemb;
		size_t	size;
		
	
		nmemb = 10;
		size = 5;
		str1 = calloc(nmemb, size);
		str2 = ft_calloc(nmemb, size);
		
		printf("Result: %s - calloc\n", str1);
		printf("Result: %s - ft_calloc\n", str2);
		free (str1);
		free (str2);
}
*/