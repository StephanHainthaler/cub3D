/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:09 by juitz             #+#    #+#             */
/*   Updated: 2024/10/08 15:29:03 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	get_identifier(t_cube *cube, char *map_str)
{
	int	counter;
	int	pos;
	int	i;

	counter = 0;
	i = 0;

	while (map_str[i])
	{
		if (ft_strncmp_pos(map_str, "NO ", 3, &pos) == 0)
			ft_strjoin(cube->n_path, &map_str[pos + 1]);
		if (ft_strncmp_pos(map_str, "SO ", 3, &pos) == 0)
			ft_strjoin(cube->s_path, &map_str[pos + 1]);
		if (ft_strncmp_pos(map_str, "WE ", 3, &pos) == 0)
			ft_strjoin(cube->w_path, &map_str[pos + 1]);
		if (ft_strncmp_pos(map_str, "EA ", 3, &pos) == 0)
			ft_strjoin(cube->e_path, &map_str[pos + 1]);
		if (ft_strncmp_pos(map_str, "C ", 2, &pos) == 0)
			ft_strjoin(cube->c_color, &map_str[pos + 1]);
		if (ft_strncmp_pos(map_str, "F ", 2, &pos) == 0)
			ft_strjoin(cube->f_color, &map_str[pos + 1]);
		i++;
	}
	if (cube->n_path || cube->s_path || cube->w_path || cube->e_path == NULL)
}