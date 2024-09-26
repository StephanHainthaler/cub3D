/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:18:58 by shaintha          #+#    #+#             */
/*   Updated: 2024/09/26 13:54:26 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

bool    is_format_valid(char *file, char *format)
{
	int i;
	int j;

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

bool	check_map_elements(char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '0' && map[y][x] != '1'
				&& map[y][x] != 'N' && map[y][x] != 'E'
				&& map[y][x] != 'S' && map[y][x] != 'W'
				&& map[y][x] != ' ')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}


bool	is_map_border_valid(char **map)
{
	int	x;
	int	y;
	
	//Part 1: per x_axxis
	y = 0;
	while (map[y] != NULL)
	{
		if (map[y][0] != '1' || map[y][0] != ' ')
			return (false);
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == ' ' && (map[y][x + 1] != '1'
				|| map[y][x + 1] != ' ' || map[y][x + 1] != '\0'))
				return (false);
			x++;
		}
		y++;
	}
	//Part 2: per y_axxis
	return (true);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	if (is_format_valid(argv[1], ".cub") == false)
		return (printf("Wrong format\n"), 1);
	//initialzie struct
	printf("Welcome to cube3D\n");
	printf("Map_Name: %s\n", argv[1]);
	return (0);
}
