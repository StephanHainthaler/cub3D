/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:08:42 by shaintha          #+#    #+#             */
/*   Updated: 2024/05/27 12:08:39 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

size_t	ft_strarrlen(char **strarr)
{
	size_t	count;

	if (strarr == NULL)
		return (0);
	count = 0;
	while (strarr[count] != NULL)
		count++;
	return (count);
}
