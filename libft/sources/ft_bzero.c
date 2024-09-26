/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:39:46 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/12 17:09:30 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		*ptr = '\0';
		ptr++;
		i++;
	}
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str1[60] = "Hello World_I am thinking about_ALLLOTOFTHINGS";
	char str2[60] = "Hello World_I am thinking about_ALLLOTOFTHINGS";
	printf("\nOriginal: %s\n", str1);

	bzero(str1 + 17, 8*sizeof(char));
	ft_bzero(str2 + 17, 8*sizeof(char));

	printf("New (bzero): %s\n", str1);
	printf("New (ft_bzero): %s\n", str2);

	return (0);	
}
*/
