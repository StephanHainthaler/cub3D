/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_fromstrarr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:04:11 by shaintha          #+#    #+#             */
/*   Updated: 2024/07/22 15:01:05 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	**ft_strdel_fromstrarr(char **strarr, int pos)
{
	char	**new_strarr;
	int		i;
	int		j;

	if (pos < 0)
		return (strarr);
	new_strarr = (char **)malloc((\
		ft_strarrlen(strarr) - 1 + 1) * sizeof(char *));
	if (new_strarr == NULL)
		return (ft_free_strarr(strarr), NULL);
	i = 0;
	j = 0;
	while (i < (int)ft_strarrlen(strarr))
	{
		if (i == pos)
		{
			i++;
			continue ;
		}
		new_strarr[j++] = ft_strdup(strarr[i++]);
		if (new_strarr[j - 1] == NULL)
			return (ft_free_strarr(new_strarr), ft_free_strarr(strarr), NULL);
	}
	new_strarr[j] = NULL;
	return (ft_free_strarr(strarr), new_strarr);
}

// int	main(void)
// {
// 	char	**strarr;
// 	char	*str;

// 	strarr = ft_split("USER=Hello1 PATH=World1 BLABLA=Hello2 d=World2", ' ');
// 	str = "P";
// 	ft_putendl_fd("Before:\n", 1);
// 	ft_putstrarr_fd(strarr, 1);
// 	strarr = ft_strdel_fromstrarr(strarr, str);
// 	ft_putendl_fd("After:\n", 1);
// 	ft_putstrarr_fd(strarr, 1);
// 	ft_free_strarr(strarr);
// }
