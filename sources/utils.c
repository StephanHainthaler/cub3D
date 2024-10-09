/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:12:38 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/09 12:32:26 by juitz            ###   ########.fr       */
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

void	put_error(char *error_message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_message, 2);
}

int	ft_strncmp_pos(const char *str1, const char *str2, size_t n, int *pos)
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
	*pos = i;
	return (res);
}

char	*ft_strdup_nl(const char *src)
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
	dup[i] = '\0';
	return (dup);
}

int	skip_spaces(char *str, int *pos)
{
	while (str[*pos] == ' ')
		(*pos)++;
	return (*pos);
}