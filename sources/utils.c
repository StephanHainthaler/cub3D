/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:12:38 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/17 13:56:59 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

bool    is_format_valid(char *file, char *format)
{
	size_t i;
	size_t j;

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

void	put_error(char *error_message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_message, 2);
}

int	ft_strncmp_pos(const char *str1, const char *str2, size_t n, size_t *pos)
{
	int					res;
	unsigned char		*str1ptr;
	unsigned char		*str2ptr;
	size_t				i;

	str1ptr = (unsigned char *)str1;
	str2ptr = (unsigned char *)str2;
	res = 0;
	if (n == 0)
		return (0);
	i = 0;
	while ((str1ptr[i] != '\0' || str2ptr[i] != '\0') && i < n)
	{
		if (str1ptr[i] != str2ptr[i])
		{
			res = str1ptr[i] - str2ptr[i];
			return (res);
		}
		i++;
	}
	i = 0;
	while (str1ptr[i] != '\0' && str1ptr[i] != '\n')
		i++;
	// *pos += i;
	*pos += i;
	return (res);
}

char	*ft_strdup_nl(const char *src, size_t *pos)
{
	char	*dup;
	int		count;
	int		i;

	count = 0;
	while (src[count] != '\0')
		count++;
	dup = (char *)malloc((count + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && src[i] != '\n')
	{
		dup[i] = src[i];
		i++;
	}
	*pos += i;
	dup[i] = '\0';
	return (dup);
}

int	skip_spaces_nl(char *str, size_t *pos)
{
	while (str[*pos] == ' ' || str[*pos] == '\n')
		(*pos)++;
	return (*pos);
}

bool	is_color_valid(char *str)
{
	int		count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_isspace(str[i]) == true)
			i++;
		j = i;
		while (str[j] != '\0' && str[j] != ',')
			if (ft_isdigit(str[j++]) == false
				&& str[j - 1] != '-' && str[j - 1] != '+')
				return (false);
		j++;
		if (ft_atoi_n(str + i, j - i) < 0 || ft_atoi_n(str + i, j - i) > 255
			|| ft_isnumber_n(str + i, j - i - 1) == false)
			return (false);
		count++;
		i += (j - i);
	}
	if (count != 3 || str[i - 1] != '\0')
		return (false);
	return (true);
}

int	get_color(char *color_str)
{
	int		red;
	int		green;
	int		blue;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (color_str[i] != ',')
		i++;
	red = ft_atoi_n(color_str + j, i);
	j = i + 1;
	i = 0;
	while (color_str[i] != ',')
		i++;
	green = ft_atoi_n(color_str + j, i);
	j = j + i + 1;
	i = 0;
	while (color_str[i] != '\0')
		i++;
	blue = ft_atoi_n(color_str + j, i);
	return (red << 16 | green << 8 | blue);
}
