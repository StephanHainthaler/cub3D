/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:19:15 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/12 16:52:49 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		*ptr = c;
		ptr++;
		i++;
	}
	return (str);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str1[60] = "Hello World_I am thinking about_ALLLOTOFTHINGS";
	char str2[60] = "Hello World_I am thinking about_ALLLOTOFTHINGS";
	printf("\nOriginal: %s\n", str1);

	memset(str1 + 17, 'Q', 8*sizeof(char));
	ft_memset(str2 + 17, 'Q', 8*sizeof(char));

	printf("New (memset): %s\n", str1);
	printf("New (ft_memset): %s\n", str2);

	return (0);	
}
*/
