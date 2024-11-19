/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:35:26 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/19 16:58:01 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	parse_map(t_cube *cube, char *map_name)
{
	size_t	start;

	cube->map_str = get_map_content(map_name);
	if (cube->map_str == NULL)
		return (1);
	start = get_map_startline(cube->map_str, 0, 0);
	if (start == 0)
		return (put_error("Wrong Map Format"), free_cube(cube), 1);
	if (has_map_empty_line(cube->map_str + start, cube->map_str[0]) == true)
		return (free_cube(cube), 1);
	if (is_information_valid(cube, cube->map_str, start - 1) == 1)
		return (free_cube(cube), 1);
	cube->map = ft_split(cube->map_str + start, '\n');
	if (cube->map == NULL)
		return (free_cube(cube), 1);
	if (is_layout_valid(cube->map, 0, 0, false) == false)
		return (free_cube(cube), 1);
	if (is_map_too_big(cube->map, 0, 0) == true)
		return (free_cube(cube), 1);
	return (0);
}

char	*get_map_content(char *file_name)
{
	int		fd;
	char	*line;
	char	*temp;
	int		bytes_read;
	char	*content;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (put_error("Failed to find/open the file!"), NULL);
	line = ft_strdup("");
	if (line == NULL)
		return (close(fd), put_error("Malloc error!"), NULL);
	temp = (char *)malloc((1 + 1) * sizeof(char));
	if (temp == NULL)
		return (close(fd), free(line), put_error("Malloc error!"), NULL);
	bytes_read = 1;
	content = read_map(fd, line, temp, bytes_read);
	if (content == NULL)
		return (close(fd), NULL);
	return (close(fd), content);
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

size_t	get_map_startline(char *map_str, size_t i, size_t j)
{
	bool	is_starting_line;
	bool	found;

	while (map_str[i] != '\0')
	{
		is_starting_line = false;
		found = false;
		j = i;
		while (map_str[j] != '\0' && map_str[j] != '\n')
		{
			if (map_str[j] == '1' && found == false)
			{
				found = true;
				is_starting_line = true;
			}
			if (is_map_element(map_str[j++]) == false)
				is_starting_line = false;
		}
		if (is_starting_line == true && found == true)
			return (i);
		if (map_str[j] != '\0')
			j++;
		i = j;
	}
	return (0);
}

bool	has_map_empty_line(char *str, char first_char_of_file)
{
	int	i;

	if (first_char_of_file == '\n')
		return (put_error("Map contains empty line(s)!"), true);
	i = 0;
	if (str[i] == '\n')
		return (put_error("Map contains empty line(s)!"), true);
	if (str[ft_strlen(str) - 1] == '\n')
		return (put_error("Map contains empty line(s)!"), true);
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (put_error("Map contains empty line(s)!"), true);
		i++;
	}
	return (false);
}
