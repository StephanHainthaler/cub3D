/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:35:26 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/15 16:34:53 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	parse_map(t_cube *cube, char *map_name)
{
	char	*map_str;
	int		start;

	map_str = get_map_str(map_name);
	if (map_str == NULL)
		return (1);
	start = get_map_startline(map_str);
	if (start == -1)
		return (free(map_str), 1);
	if (has_empty_line(map_str + start) == true || map_str[0] == '\n')
		return (free(map_str), 1);
	if (identifier_check(cube, map_str) == 1)
		return (free(map_str), 1);
	cube->map = ft_split(map_str + start, '\n');
	if (cube->map == NULL)
		return (free(map_str), 1);
	free(map_str);
	if (is_map_valid(cube->map, 0, 0, false) == false)
		return (free_cube(cube), 1);
	return (0);
}

char	*get_map_str(char *map_name)
{
	char	*map_str;
	char	*line;
	char	*temp;
	int		bytes_read;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (put_error("Failed to find/open the file!"), NULL);
	line = ft_strdup("");
	if (line == NULL)
		return (close(fd), put_error("Malloc error!"), NULL);
	temp = (char *)malloc((1 + 1) * sizeof(char));
	if (temp == NULL)
		return (close(fd), free(line), put_error("Malloc error!"), NULL);
	bytes_read = 1;
	map_str = read_map(fd, line, temp, bytes_read);
	if (map_str == NULL)
		return (close(fd), NULL);
	return (close(fd), map_str);
}

char	*read_map(int fd, char *line, char *temp, int bytes_read)
{
	int	i;

	i = 0;
	while (bytes_read > 0 && !(ft_strchr(line, EOF)))
	{
		bytes_read = read(fd, temp, 1);
		if (bytes_read == -1)
		{
			if (line)
				free(line);
			line = NULL;
			return (free(temp), put_error("Read error!"), NULL);
		}
		if (i == 0)
		{
			if (bytes_read == 0)
				return (free(temp), free(line), put_error("Empty file!"), NULL);
			i = 1;
		}
		temp[bytes_read] = '\0';
		line = ft_strjoin_gnl(line, temp);
		if (!line)
			return (put_error("Malloc error!"), NULL);
	}
	return (free(temp), line);
}

bool	is_map_valid(char **map, size_t x, size_t y, bool found)
{
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '0' && map[y][x] != '1'
				&& map[y][x] != 'N' && map[y][x] != 'E'
				&& map[y][x] != 'S' && map[y][x] != 'W'
				&& map[y][x] != ' ')
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

	i = 0;
	while (map[i] != NULL)
		i++;
	if (y == 0)
		if (map[y][x] != '1' && map[y][x] != ' ')
			return (false);
	if (y > 0 && y != i - 1)
	{
		if ((map[y][x] != '1' && map[y][x] != ' ') && map[y - 1][x] == ' ')
			return (false);
		if ((map[y][x] != '1' && map[y][x] != ' ') && map[y + 1][x] == ' ')
			return (false);
	}
	if (y == i - 1)
		if (map[y][x] != '1' && map[y][x] != ' ')
			return (false);
	if ((map[y][x] != '1' && map[y][x] != ' ')
		&& (map[y][x + 1] == ' ' || map[y][x + 1] == '\0'))
		return (false);
	return (true);
}

int	get_map_startline(char *map_str)
{
	int		i;
	int		j;
	bool	is_starting_line;
	bool	found;

	i = 0;
	while (map_str[i] != '\0')
	{
		is_starting_line = false;
		found = false;
		j = i;
		while (map_str[j] != '\0')
		{
			if (map_str[j] == '\n')
				break ;
			if (map_str[j] == '1')
			{
				found = true;
				is_starting_line = true;
			}
			if (map_str[j] != '1' && map_str[j] != ' ')
				is_starting_line = false;
			j++;
		}
		j++;
		if (is_starting_line == true && found == true)
			return (i);
		i = j;
	}
	return (-1);
}

bool	has_empty_line(char *map_str)
{
	int	i;

	i = 0;
	if (map_str[0] == '\n')
		return (put_error("Map contains empty line(s)!"), true);
	if (map_str[ft_strlen(map_str) - 1] == '\n')
		return (put_error("Map contains empty line(s)!"), true);
	while (map_str[i] != '\0')
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
			return (put_error("Map contains empty line(s)!"), true);
		i++;
	}
	return (false);
}
