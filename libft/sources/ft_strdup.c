/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:20:32 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/12 16:44:32 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		count;
	int		i;

	count = 0;
	while (src[count] != '\0')
		count++;
	dup = (char *)malloc((count + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char * argv[])
{
	char	*dup1;
	char	*dup2;

	if (argc == 2)
	{
		dup1 = strdup(argv[1]);
		dup2 = ft_strdup(argv[1]);
		printf("%s\n", dup1);
		printf("%s\n", dup2);
		free(dup1);
		free(dup2);
	}
}
*/
