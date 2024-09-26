/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:34:39 by shaintha          #+#    #+#             */
/*   Updated: 2023/11/13 10:34:40 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (lst != NULL)
	{
		if (*lst == NULL)
		{
			*lst = new;
			return ;
		}
		last = ft_lstlast(*lst);
		last->next = new;
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
	ft_lstadd_back(&lst, new1);
	ft_lstadd_back(&lst, new2);
	ft_putlst_fd(lst, 1);
}
*/