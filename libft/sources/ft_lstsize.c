/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:33:59 by shaintha          #+#    #+#             */
/*   Updated: 2023/11/13 10:34:00 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (count);
}

/*
//cc ft_lstsize.c ft_lstnew.c ft_lstadd_back.c ft_putnbr_fd.c ft_lstlast.c

int	main(void)
{
	t_list *lst;
	t_list *new1;
	t_list *new2;
	int		size;

	lst = NULL;
	new1 = ft_lstnew(1);
	new2 = ft_lstnew(2);
	ft_lstadd_back(&lst, new1);
	ft_lstadd_back(&lst, new2);
	size = ft_lstsize(lst);
	ft_putnbr_fd(size, 1);

	return (0);
}
*/