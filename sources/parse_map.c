/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:09 by juitz             #+#    #+#             */
/*   Updated: 2024/10/09 12:37:42 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	get_identifier(t_cube *cube, char *map_str)
{
	int	counter;
	int	pos;
	int	i;

	counter = 0;
	i = 0;
	while (map_str[i])
	{
		if (ft_strncmp_pos(&map_str[i], "NO ", 3, &pos) == 0 && cube->n_path == NULL)
		{
			skip_spaces(map_str, &pos);
			cube->n_path = ft_strdup_nl (&map_str[pos]);
		}
		if (ft_strncmp_pos(&map_str[i], "SO ", 3, &pos) == 0 && cube->s_path == NULL)
		{
			skip_spaces(map_str, &pos);
			cube->s_path = ft_strdup_nl(&map_str[pos]);
		}
		if (ft_strncmp_pos(&map_str[i], "WE ", 3, &pos) == 0 && cube->w_path == NULL)
		{
			skip_spaces(map_str, &pos);
			cube->w_path = ft_strdup_nl (&map_str[pos]);
		}
		if (ft_strncmp_pos(&map_str[i], "EA ", 3, &pos) == 0 && cube->e_path == NULL)
		{
			skip_spaces(map_str, &pos);
			cube->e_path = ft_strdup_nl (&map_str[pos]);
		}
		if (ft_strncmp_pos(&map_str[i], "C ", 2, &pos) == 0 && cube->c_color == NULL)
		{
			skip_spaces(map_str, &pos);
			cube->c_color = ft_strdup_nl (&map_str[pos]);
		}
		if (ft_strncmp_pos(&map_str[i], "F ", 2, &pos) == 0 && cube->f_color == NULL)
		{
			skip_spaces(map_str, &pos);
			cube->f_color = ft_strdup_nl (&map_str[pos]);
		}
		i++;
	}
	if (cube->n_path || cube->s_path || cube->w_path || cube->e_path
		|| cube->c_color || cube->f_color == NULL)
		return (put_error("Invalid Identifiers"), 1);
	return (0);
}


int		parse_map(t_cube *cube, char *map_str)
{
	if (get_identifier(cube, map_str) == 1)
		return (1);
}