/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:12:38 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/10 13:14:52 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

bool    is_format_valid(char *file, char *format)
{
	size_t i;
	size_t j;

	if (file == NULL || format == NULL)
		return (false);
	if (ft_strchr(file, '.') == NULL)
		return (false);
	i = ft_strlen(file);
	while (file[i] != '.')
		i--;
	j = 0;
	while (file[i] != '\0')
		if (file[i++] != format[j++])
			return (false);
	if (format[j] != '\0')
		return (false);
	return (true);
}

bool	is_color_valid(char *color_str)
{
	char	*n_str;
	int		count;
	size_t	i;
	size_t	j;

	n_str = NULL;
	count = 0;
	i = 0;
	while (color_str[i] != '\0')
	{
		j = 0;
		while (color_str[j] != '\0' && color_str[j] != ',')
		{
			if (ft_isdigit(color_str[j]) == false && color_str[j] != ' ')
				return (false);
			j++;
		}
		ft_strlcpy(n_str, color_str + i, j);
		printf("Number %i: '%s'\n", count, n_str);
		if (ft_atoi(n_str) < 0 || ft_atoi(n_str) > 255 || j == 0)
			return (false);
		count++;
		i = i + j;
	}
	if (count != 3)
		return (false);
	return (true);
}

void	put_error(char *error_message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_message, 2);
}
