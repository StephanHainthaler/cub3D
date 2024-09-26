/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_tostrarr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:53:43 by shaintha          #+#    #+#             */
/*   Updated: 2024/07/22 15:00:21 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	**ft_stradd_tostrarr(char **strarr, char *str)
{
	char	**new_strarr;
	int		arr_size;
	int		i;

	arr_size = ft_strarrlen(strarr);
	new_strarr = (char **)malloc((arr_size + 1 + 1) * sizeof(char *));
	if (new_strarr == NULL)
		return (ft_free_strarr(strarr), NULL);
	i = 0;
	while (i < arr_size)
	{
		new_strarr[i] = ft_strdup(strarr[i]);
		if (new_strarr[i] == NULL)
			return (ft_free_strarr(new_strarr), ft_free_strarr(strarr), NULL);
		i++;
	}
	new_strarr[i++] = ft_strdup(str);
	if (new_strarr[i - 1] == NULL)
		return (ft_free_strarr(new_strarr), ft_free_strarr(strarr), NULL);
	new_strarr[i] = NULL;
	return (ft_free_strarr(strarr), new_strarr);
}

// int	main(void)
// {
// 	char	**split;
// 	char	*str;

// 	split = ft_split("Hello1 World1", ' ');
// 	//split = NULL;
// 	str = "HELLO2_WORLD2";
// 	ft_putstrarr_fd(split, 1);
// 	ft_putendl_fd(str, 1);
// 	split = ft_stradd_tostrarr(split, str);
// 	ft_putendl_fd("test1", 1);
// 	ft_putstrarr_fd(split, 1);
// 	ft_putendl_fd("test2", 1);
// 	ft_free_strarr(split);
// }
