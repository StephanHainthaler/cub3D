/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:35:06 by shaintha          #+#    #+#             */
/*   Updated: 2024/05/23 13:37:38 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current_node;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		current_node = *lst;
		if (current_node != NULL)
			ft_lstdelone(lst, current_node);
	}
	*lst = NULL;
}
