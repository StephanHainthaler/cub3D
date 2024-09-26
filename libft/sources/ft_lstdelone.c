/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:34:53 by shaintha          #+#    #+#             */
/*   Updated: 2024/09/26 09:36:06 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstdelone(t_list **lst, t_list *node)
{
	t_list	*to_delete;

	if (*lst == NULL)
		return ;
	if (node != NULL)
	{
		to_delete = node;
		node = node->next;
		free(to_delete);
		*lst = node;
	}
}
