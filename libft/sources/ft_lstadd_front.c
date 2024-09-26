/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:33:45 by shaintha          #+#    #+#             */
/*   Updated: 2023/11/13 10:33:46 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (lst != NULL)
	{
		if (*lst != NULL)
			new->next = *lst;
		*lst = new;
	}
}

/*
int	main(void)
{
	t_list *lst;
	t_list *new1;
	t_list *new2;

	lst = NULL;
	new1 = ft_lstnew(1);
	new2 = ft_lstnew(2);
	ft_lstadd_front(&lst, new1);
	ft_lstadd_front(&lst, new2);
	ft_putlst_fd(lst, 1);
}
*/