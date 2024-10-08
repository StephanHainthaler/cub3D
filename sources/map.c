/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:35:26 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/08 13:00:04 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	parse_map(t_cube *cube, char *map_name)
{
	char	*map_str;
	
	(void)cube;
	map_str = get_map_str(map_name);
	if (map_str == NULL)
		return (1);
	printf("%s\n", map_str);
	free(map_str);
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
	unsigned int	x;
	unsigned int	y;

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
	return (true);
}

bool	is_in_border(char **map, unsigned int x, unsigned int y)
{
	unsigned int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	if (y == 0)
		if (map[y][x] != ' ' || map[y][x] != '1')
			return (false);
	if (y > 0)
	{
		if ((map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'E' || map[y][x] == 'S' || map[y][x] == 'W') &&
			(map[y - 1][x] != ' ' && map[y - 1][x] != '1')) //maybe not && but ||
			return (false);
	}
	if (y == i)
		if (map[y][x] != ' ' || map[y][x] != '1')
			return (false);
	return (true);
}