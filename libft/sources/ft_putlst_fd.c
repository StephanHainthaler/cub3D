/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:34:39 by shaintha          #+#    #+#             */
/*   Updated: 2024/09/26 09:34:57 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_putlst_fd(t_list *lst, int fd)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		if (temp->attr == NULL)
			ft_putendl_fd("(NULL)", fd);
		else
			ft_putendl_fd(temp->attr, fd);
		temp = temp->next;
	}
}
