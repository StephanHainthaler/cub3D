/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:54:43 by shaintha          #+#    #+#             */
/*   Updated: 2024/05/20 10:54:22 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	**ft_strarrdup(char **src)
{
	char	**dup;
	int		arrcount;
	int		i;

	arrcount = ft_strarrlen(src);
	dup = (char **)malloc((arrcount + 1) * sizeof(char *));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] != NULL)
	{
		dup[i] = ft_strdup(src[i]);
		if (dup[i] == NULL)
		{
			ft_free_strarr(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
