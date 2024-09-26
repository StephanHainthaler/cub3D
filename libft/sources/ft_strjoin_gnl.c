/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:03:26 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/14 13:41:07 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	if (str1 == NULL)
	{
		str1 = (char *)malloc(sizeof(char));
		if (str1 == NULL)
			return (free(str1), free(str2), NULL);
		str1[0] = '\0';
	}
	i = ft_strlen(str1) + ft_strlen(str2);
	strjoin = (char *)malloc((i + 1) * sizeof(char));
	if (strjoin == NULL)
		return (free(str1), free(str2), NULL);
	i = 0;
	j = 0;
	while (str1[j] != '\0')
		strjoin[i++] = str1[j++];
	j = 0;
	while (str2[j] != '\0')
		strjoin[i++] = str2[j++];
	strjoin[i] = '\0';
	free(str1);
	return (strjoin);
}
