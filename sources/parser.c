/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:09 by juitz             #+#    #+#             */
/*   Updated: 2024/10/17 13:49:44 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	get_identifier(t_cube *cube, char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i])
	{
		if (ft_strncmp(&map_str[i], "NO ", 3) == 0)
		{
			skip_spaces_nl(map_str, &i);
			i += 3;
			if (cube->n_path != NULL)
				return (1);
			skip_spaces_nl(map_str, &i);
			cube->n_path = ft_strdup_nl (&map_str[i], &i);
			printf("%s\n", cube->n_path);
		}
		if (ft_strncmp(&map_str[i], "EA ", 3) == 0)
		{
			skip_spaces_nl(map_str, &i);
			i += 3;
			if (cube->e_path != NULL)
				return (1);
			skip_spaces_nl(map_str, &i);
			cube->e_path = ft_strdup_nl(&map_str[i], &i);
			printf("%s\n", cube->e_path);
		}
		if (ft_strncmp(&map_str[i], "SO ", 3) == 0)
		{
			skip_spaces_nl(map_str, &i);
			i += 3;
			if (cube->s_path != NULL)
				return (1);
			skip_spaces_nl(map_str, &i);
			cube->s_path = ft_strdup_nl (&map_str[i], &i);
			printf("%s\n", cube->s_path);
		}
		if (ft_strncmp(&map_str[i], "WE ", 3) == 0)
		{
			skip_spaces_nl(map_str, &i);
			i += 3;
			if (cube->w_path != NULL)
				return (1);
			skip_spaces_nl(map_str, &i);
			cube->w_path = ft_strdup_nl (&map_str[i], &i);
			printf("%s\n", cube->w_path);
		}
		if (ft_strncmp(&map_str[i], "C ", 2) == 0)
		{
			skip_spaces_nl(map_str, &i);
			i += 2;
			if (cube->c_color != NULL)
				return (1);
			skip_spaces_nl(map_str, &i);
			cube->c_color = ft_strdup_nl (&map_str[i], &i);
			printf("%s\n", cube->c_color);
		}
		if (ft_strncmp(&map_str[i], "F ", 2) == 0)
		{
			skip_spaces_nl(map_str, &i);
			i += 2;
			if (cube->f_color != NULL)
				return (1);
			skip_spaces_nl(map_str, &i);
			cube->f_color = ft_strdup_nl (&map_str[i], &i);
			printf("%s\n", cube->f_color);
		}
		/* if(ft_strncmp(&map_str[i], "\n", 1) == 0)
			skip_spaces_nl(map_str, &i); */
		else
			return (1);
		i++;
	}
	if (!cube->n_path || !cube->s_path || !cube->w_path || !cube->e_path
		|| !cube->c_color || !cube->f_color)
		return (1);
	return (0);
}

/* int	check_duplicate_id(t_cube *cube, char *map_str)
{
	int	i;
	int	i;

	i = 0;
	i = 0;
	while (map_str[i])
	{
		if (ft_strncmp(&map_str[i], "NO ", 3, &i) == 0 && cube->n_path != NULL)
			return (1);
		if (ft_strncmp(&map_str[i], "SO ", 3, &i) == 0 && cube->s_path != NULL)
			return (1);
		if (ft_strncmp(&map_str[i], "WE ", 3, &i) == 0 && cube->w_path != NULL)
			return (1);
		if (ft_strncmp(&map_str[i], "EA ", 3, &i) == 0 && cube->e_path != NULL)
			return (1);
		if (ft_strncmp(&map_str[i], "C ", 2, &i) == 0 && cube->c_color != NULL)
			return (1);
		if (ft_strncmp(&map_str[i], "F ", 2, &i) == 0 && cube->f_color != NULL)
			return (1);
	}
	return (0);
} */

int		identifier_check(t_cube *cube, char *map_str)
{
	if (get_identifier(cube, map_str) == 1)
		return (put_error("Invalid Identifiers"), 1);
	/* if (check_duplicate_id(cube, map_str) == 1)
		return (put_error("Duplicate Identifiers"), 1); */
	return (0);
}