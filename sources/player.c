/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:30:10 by juitz             #+#    #+#             */
/*   Updated: 2024/11/08 14:52:19 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	move_pov(t_cube *cube, int syskey)
{
	t_player	player;

	player = cube->player;
	if (syskey == KEY_W)
		if (is_wall(cube, player.pos_x, player.pos_y - 0.1) == false)
			player.pos_y = player.pos_y - 0.1;
	if (syskey == KEY_A)
		if (is_wall(cube, player.pos_x - 0.1, player.pos_y) == false)
			player.pos_x = player.pos_x - 0.1;
	if (syskey == KEY_S)
		if (is_wall(cube, player.pos_x, player.pos_y + 0.1) == false)
			player.pos_y = player.pos_y + 0.1;
	if (syskey == KEY_D)
		if (is_wall(cube, player.pos_x + 0.1, player.pos_y) == false)
			player.pos_x = player.pos_x + 0.1;
	cube->player = player;
	printf("Current POS: x = %f, y = %f\n", cube->player.pos_x, cube->player.pos_y);
}

void	change_direction(t_cube *cube, int syskey)
{
	t_player	player;

	player = cube->player;
	if (syskey == KEY_LEFT)
	{
		player.dir_x = player.dir_x * cos(-PI / 2) - player.dir_y * sin(-PI / 2);
		player.dir_y = player.dir_x * sin(-PI / 2) + player.dir_y * cos(-PI / 2);
		player.plane_x = player.plane_x * cos(-PI / 2) - player.plane_y * sin(-PI / 2);
		player.plane_y = player.plane_x * sin(-PI / 2) + player.plane_y * cos(-PI / 2);
	}
	if (syskey == KEY_RIGHT)
	{
		player.dir_x = player.dir_x * cos(PI / 2) - player.dir_y * sin(PI / 2);
		player.dir_y = player.dir_x * sin(PI / 2) + player.dir_y * cos(PI / 2);
		player.plane_x = player.plane_x * cos(PI / 2) - player.plane_y * sin(PI / 2);
		player.plane_y = player.plane_x * sin(PI / 2) + player.plane_y * cos(PI / 2);
	}
	cube->player = player;
}

bool	is_wall(t_cube *cube, float x, float y)
{
	char **map;
	int		ix;
	int		iy;

	map = cube->map;
	ix = x;
	iy = y;
	if (cube->map[iy][ix] == '1')// || map[iy][ix] == ' ')
		return (true);
	return (false);
}

void	get_player_info(t_player *player, char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'N' || map[y][x] == 'E'
				|| map[y][x] == 'S' || map[y][x] == 'W')
			{
				init_player_dir(player, map[y][x]);
				player->pos_x = x;
				player->pos_y = y;
				// player->pos_x = player->pos_x - 0.5;
				// player->pos_y = player->pos_y - 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_player_dir_ns(t_player *player, char dir_char)
{
	if (dir_char == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	if (dir_char == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}
void	init_player_dir_ew(t_player *player, char dir_char)
{
	if (dir_char == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	if (dir_char == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

void	init_player_dir(t_player *player, char dir_char)
{
	if (dir_char == 'N' || dir_char == 'S')
		init_player_dir_ns(player, dir_char);
	if (dir_char == 'E' || dir_char == 'W')
		init_player_dir_ew(player, dir_char);
}