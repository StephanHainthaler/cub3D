/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:06:07 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/12 16:29:25 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	litlen;

	litlen = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < n)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && (big[i + j] == little[j]) && (i + j) < n)
				j++;
			if (j == litlen)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <bsd/string.h>

//compile using -lbsd

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char	*res1;
		char	*res2;

		res1 = strnstr(argv[1], argv[2], atoi(argv[3]));
		printf("strnstr_Result: %s\n", res1);
	
		res2 = ft_strnstr(argv[1], argv[2], atoi(argv[3]));
		printf("ft_strnstr_Result: %s\n", res2);
	}
	return (0);	
}
*/