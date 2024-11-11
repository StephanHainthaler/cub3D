#include "../headers/cub3D.h"

int	skip_spaces(char *str, size_t *pos)
{
	while (str[*pos] == ' ')
		(*pos)++;
	return (*pos);
}

int	skip_nl(char *str, size_t *pos)
{
	while (str[*pos] == '\n')
		(*pos)++;
	return (*pos);
}

int	skip_spaces_nl(char *str, size_t *pos)
{
	while (str[*pos] == ' ' || str[*pos] == '\n')
		(*pos)++;
	return (*pos);
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

/* void	change_direction(t_cube *cube, int syskey)
{
    t_player	player;
    double		old_dir_x;
    double		old_plane_x;

    player = cube->player;
    old_dir_x = player.dir_x;
    old_plane_x = player.plane_x;

    if (syskey == KEY_LEFT)
    {
        player.dir_x = old_dir_x * cos(-ROT_SPD) - player.dir_y * sin(-ROT_SPD);
        player.dir_y = old_dir_x * sin(-ROT_SPD) + player.dir_y * cos(-ROT_SPD);
        player.plane_x = old_plane_x * cos(-ROT_SPD) - player.plane_y * sin(-ROT_SPD);
        player.plane_y = old_plane_x * sin(-ROT_SPD) + player.plane_y * cos(-ROT_SPD);
    }
    if (syskey == KEY_RIGHT)
    {
        player.dir_x = old_dir_x * cos(ROT_SPD) - player.dir_y * sin(ROT_SPD);
        player.dir_y = old_dir_x * sin(ROT_SPD) + player.dir_y * cos(ROT_SPD);
        player.plane_x = old_plane_x * cos(ROT_SPD) - player.plane_y * sin(ROT_SPD);
        player.plane_y = old_plane_x * sin(ROT_SPD) + player.plane_y * cos(ROT_SPD);
    }
    cube->player = player;
    printf("Current DIR: x = %f, y = %f\n", cube->player.dir_x, cube->player.dir_y);
} */