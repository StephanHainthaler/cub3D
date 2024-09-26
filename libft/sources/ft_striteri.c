/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:06:00 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/13 16:59:27 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char const *str, void (*f)(unsigned int, char *))
{
	char	*newstr;
	int		i;

	newstr = (char *)str;
	i = 0;
	while (newstr[i] != '\0')
	{
		(*f)(i, &newstr[i]);
		i++;
	}
}
/*
#include <stdio.h>

static void	test(unsigned int n, char *str)
{	
	n = n * 1;
	printf("%s\n", str);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char	*str;

		str = argv[1];
		ft_striteri(str, test);
	}
	return (0);
}
*/