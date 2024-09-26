/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:28:14 by juitz             #+#    #+#             */
/*   Updated: 2024/08/08 14:29:46 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	**ft_sort_strarr(char **strarray)
{
	char	**arrdup;
	char	*temp;
	size_t	i;
	size_t	j;

	arrdup = ft_strarrdup(strarray);
	if (arrdup == NULL)
		return (NULL);
	i = 0;
	while (arrdup[i])
	{
		j = i + 1;
		while (arrdup[j])
		{
			if (ft_strncmp(arrdup[i], arrdup[j], ft_strlen(arrdup[i])) > 0)
			{
				temp = arrdup[i];
				arrdup[i] = arrdup[j];
				arrdup[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arrdup);
}
