/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:09 by juitz             #+#    #+#             */
/*   Updated: 2024/10/09 11:54:04 by juitz            ###   ########.fr       */
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
			cube->n_path = ft_strjoin(cube->n_path, &map_str[pos + 1]);
		if (ft_strncmp_pos(&map_str[i], "SO ", 3, &pos) == 0 && cube->s_path == NULL)
			cube->s_path = ft_strjoin(cube->s_path, &map_str[pos + 1]);
		if (ft_strncmp_pos(&map_str[i], "WE ", 3, &pos) == 0 && cube->w_path == NULL)
			cube->w_path = ft_strjoin(cube->w_path, &map_str[pos + 1]);
		if (ft_strncmp_pos(&map_str[i], "EA ", 3, &pos) == 0 && cube->e_path == NULL)
			cube->e_path = ft_strjoin(cube->e_path, &map_str[pos + 1]);
		if (ft_strncmp_pos(&map_str[i], "C ", 2, &pos) == 0 && cube->c_color == NULL)
			cube->c_color = ft_strjoin(cube->c_color, &map_str[pos + 1]);
		if (ft_strncmp_pos(&map_str[i], "F ", 2, &pos) == 0 && cube->f_color == NULL)
			cube->f_color = ft_strjoin(cube->f_color, &map_str[pos + 1]);
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