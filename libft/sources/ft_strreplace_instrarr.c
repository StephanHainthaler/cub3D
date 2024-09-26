/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_instrarr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:18:54 by shaintha          #+#    #+#             */
/*   Updated: 2024/07/22 15:04:36 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	**ft_strreplace_instrarr(char **strarr, char *new_str, int pos)
{
	int		i;

	if (pos < 0 || new_str == NULL)
		return (strarr);
	i = 0;
	while (i < (int)ft_strarrlen(strarr))
	{
		if (i == pos)
		{
			ft_free(strarr[pos]);
			strarr[pos] = ft_strdup(new_str);
			if (strarr[pos] == NULL)
				return (ft_free_strarr(strarr), NULL);
			return (strarr);
		}
		i++;
	}
	return (strarr);
}
