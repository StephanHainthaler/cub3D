/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_information.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:09 by juitz             #+#    #+#             */
/*   Updated: 2024/11/11 12:58:49 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

bool	is_information_valid(t_cube *cube, char *map_str, size_t end)
{
	if (parse_information(cube, map_str, end, 0) == 1)
		return (1);
	if (is_color_valid(cube->f_color) == false)
		return (put_error("Invalid floor color configuration!"), 1);
	if (is_color_valid(cube->c_color) == false)
		return (put_error("Invalid ceiling color configuration!"), 1);
	cube->floor_color = get_color(cube->f_color);
	cube->ceiling_color = get_color(cube->c_color);
	return (0);
}

int	parse_information(t_cube *cube, char *map_str, size_t end, size_t i)
{
	while (map_str[i] && i < end)
	{
		if (ft_strncmp(map_str + i, "NO ", 3) == 0)
			cube->n_path = get_id_content(cube, "NO ", cube->n_path, &i);
		else if (ft_strncmp(map_str + i, "EA ", 3) == 0)
			cube->e_path = get_id_content(cube, "EA ", cube->e_path, &i);
		else if (ft_strncmp(map_str + i, "SO ", 3) == 0)
			cube->s_path = get_id_content(cube, "SO ", cube->s_path, &i);
		else if (ft_strncmp(map_str + i, "WE ", 3) == 0)
			cube->w_path = get_id_content(cube, "WE ", cube->w_path, &i);
		else if (ft_strncmp(map_str + i, "F ", 2) == 0)
			cube->f_color = get_id_content(cube, "F ", cube->f_color, &i);
		else if (ft_strncmp(map_str + i, "C ", 2) == 0)
			cube->c_color = get_id_content(cube, "C ", cube->c_color, &i);
		else if (ft_strncmp(map_str + i++, "\n", 1) == 0)
			continue ;
		else
			return (put_error("Invalid Identifier!"), 1);
		if (cube->error_code > 0)
			return (1);
	}
	if (!cube->n_path || !cube->s_path || !cube->w_path || !cube->e_path
		|| !cube->c_color || !cube->f_color)
		return (put_error("Missing Identifier!"), 1);
	return (0);
}

char	*get_id_content(t_cube *cube, char *id_str, char *id_content, size_t *i)
{
	if (id_content != NULL)
		return (put_error("Duplicate Identifier!"),
			cube->error_code = 2, id_content);
	*i += ft_strlen(id_str);
	while (cube->map_str[*i] != '\0' && cube->map_str[*i] == ' ')
		*i = *i + 1;
	id_content = ft_strdup_until(cube->map_str + *i, '\n');
	if (id_content == NULL)
	{
		cube->error_code = 1;
		put_error("Malloc Error!");
	}
	while (cube->map_str[*i] != '\0' && cube->map_str[*i] != '\n')
		*i = *i + 1;
	if (cube->map_str[*i] == '\n')
		*i = *i + 1;
	return (id_content);
}
