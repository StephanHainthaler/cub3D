/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:50:58 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/11 16:39:00 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{   
    if (argc == 2)
    {
        char    *str;
        char    c;
        int     i;
 
        str = argv[1];
        i = 0;
        while (str[i] != '\0')
        {
            c = str[i];
            putchar(tolower(c));
            i++;
        }
    }
    return (0);
}
*/
