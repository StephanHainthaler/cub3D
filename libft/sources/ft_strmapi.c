/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:05:33 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/14 10:33:24 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*newstr;
	int		i;

	newstr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = (*f)(i, str[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
#include <stdio.h>

static char	test(unsigned int n, char c)
{
	c = c + n;
	return (c);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char	*str;
		char	*res;

		str = argv[1];
		res = ft_strmapi(str, test);
		printf("%s\n", res);

		free(res);
	}
	return (0);
}
*/