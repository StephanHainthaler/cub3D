/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_layout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:17:30 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/20 10:00:20 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

bool	is_layout_valid(char **map, size_t x, size_t y, bool found)
{
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (is_map_element(map[y][x]) == false)
				return (put_error("Invalid map elements!"), false);
			if (map[y][x] == 'N' || map[y][x] == 'E'
				|| map[y][x] == 'S' || map[y][x] == 'W')
			{
				if (found == false)
					found = true;
				else
					return (put_error("Too many players!"), false);
			}
			if (is_in_border(map, x, y) == false)
				return (put_error("Incorrect map border!"), false);
			x++;
		}
		y++;
	}
	if (found == false)
		return (put_error("No player!"), false);
	return (true);
}

bool	is_in_border(char **map, size_t x, size_t y)
{
	size_t	i;

	i = ft_strarrlen(map);
	if (y == 0 || y == i - 1 || x == 0 || x == ft_strlen(map[y]) - 1)
		if (map[y][x] != '1' && map[y][x] != ' ')
			return (false);
	if (y > 0 && y < (i - 1))
	{
		if (((map[y][x] != '1' && map[y][x] != ' ')
			&& ft_strlen(map[y - 1]) - 1 < x)
			|| ((map[y][x] != '1' && map[y][x] != ' ') && map[y - 1][x] == ' '))
			return (false);
		if (((map[y][x] != '1' && map[y][x] != ' ')
			&& ft_strlen(map[y + 1]) - 1 < x)
			|| ((map[y][x] != '1' && map[y][x] != ' ') && map[y + 1][x] == ' '))
			return (false);
	}
	if ((map[y][x] != '1' && map[y][x] != ' ')
		&& (map[y][x + 1] == ' ' || map[y][x + 1] == '\0'))
		return (false);
	return (true);
}

bool	is_map_element(char e)
{
	if (e == '0' || e == '1' || e == 'N'
		|| e == 'E' || e == 'S' || e == 'W'
		|| e == ' ')
		return (true);
	return (false);
}

bool	is_wall(t_cube *cube, float x, float y)
{
	char	**map;
	int		ix;
	int		iy;

	map = cube->map;
	ix = x;
	iy = y;
	if (cube->map[iy][ix] == '1'
		|| cube->map[iy][ix] == '\0' || cube->map[iy][ix] == ' ')
		return (true);
	return (false);
}

bool	is_map_too_big(char **map, int x, int y)
{
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (x > MAX_MAP_X)
				return (put_error("Map too big"), true);
			x++;
		}
		if (y > MAX_MAP_Y)
			return (put_error("Map too big"), true);
		y++;
	}
	return (false);
}
