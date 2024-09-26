/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:35:38 by shaintha          #+#    #+#             */
/*   Updated: 2024/05/27 12:07:10 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_putstrarr_fd(char **strarr, int fd)
{
	int	i;

	i = 0;
	while ((size_t)i < ft_strarrlen(strarr))
	{
		if (strarr[i][0] == '\0')
			ft_putendl_fd("(null)", fd);
		else
			ft_putendl_fd(strarr[i], fd);
		i++;
	}
}
