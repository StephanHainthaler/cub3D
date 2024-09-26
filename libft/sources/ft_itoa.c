/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:04:59 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/14 11:57:40 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static int	count_number_len(long int nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long int	nb;

	nb = (long int)n;
	count = count_number_len(nb);
	str = (char *)ft_calloc((count + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (count > 0)
	{
		if (n < 0 && count == 1)
			break ;
		str[count - 1] = (nb % 10) + '0';
		nb = nb / 10;
		count--;
	}
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char	*str;
		int		nb;
		
		nb = atoi(argv[1]);
		printf("Number Int: %i\n", nb);
		str = ft_itoa(nb);
		printf("Number String: %s\n", str);
		free(str);
	}
	return (0);
}
*/