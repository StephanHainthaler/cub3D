/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:45:21 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/12 09:39:01 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char	*str;
		char	c;
		char	*res1;
		char	*res2;

		str = argv[1];
		c = argv[2][0];
		printf("String: %s\n", str);
		
		res1 = strrchr(str, c);
		printf("strrchr: %s\n", res1);

		res2 = ft_strrchr(str, c);
		printf("ft_strrchr: %s\n", res2);
		return (0);
	}
}
*/