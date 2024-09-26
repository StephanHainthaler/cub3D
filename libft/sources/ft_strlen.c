/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:44:14 by shaintha          #+#    #+#             */
/*   Updated: 2024/07/31 11:24:59 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[])
{   
    if (argc == 2)
    {
        char    *str;

        str = argv[1];
		printf("strlen: %lu\n", strlen(str));
        printf("ft_strlen: %zu\n", ft_strlen(str));
    }
    return (0);
}
*/