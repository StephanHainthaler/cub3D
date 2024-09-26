/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:03:26 by shaintha          #+#    #+#             */
/*   Updated: 2024/08/05 13:37:05 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;
	int		count;

	count = ft_strlen(str1) + ft_strlen(str2);
	strjoin = (char *)malloc((count + 1) * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[j] != '\0')
		strjoin[i++] = str1[j++];
	j = 0;
	while (str2[j] != '\0')
		strjoin[i++] = str2[j++];
	strjoin[i] = '\0';
	return (strjoin);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char	*str1;
		char	*str2;
		char	*strjoin;		
	
		str1 = argv[1];
		str2 = argv[2];
		printf("Prefix-String: %s\n", str1);
		printf("Suffix-String: %s\n", str2);
		strjoin = ft_strjoin(str1, str2);
		printf("Substring: %s\n", strjoin);
		free(strjoin);
	}
	return (0);
}
*/