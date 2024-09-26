/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:46:24 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/11 16:36:29 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
    	char	*str;
    	char	c;
		int		i;

		str = argv[1];
		i = 0;
		while (str[i] != '\0')
		{
			c = str[i];
			putchar(toupper(c));
			i++;
    	}
	}
    return (0);
}
*/
