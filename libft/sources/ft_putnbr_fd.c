/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:36:50 by shaintha          #+#    #+#             */
/*   Updated: 2023/09/13 16:51:35 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static void	ft_putspecialnbr_fd(int nb, int fd)
{
	if (nb == 0)
		write(fd, "0", 1);
	if (nb == -2147483648)
		write(fd, "2147483648", 10);
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	c[10];
	int		i;

	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb == 0 || nb == -2147483648)
		ft_putspecialnbr_fd(nb, fd);
	i = 0;
	while (nb > 0)
	{
		c[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &c[i], 1);
		i--;
	}
}
