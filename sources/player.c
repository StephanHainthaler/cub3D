/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:30:10 by juitz             #+#    #+#             */
/*   Updated: 2024/11/18 10:27:54 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

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
				if (map[y][x] == 'N' || map[y][x] == 'S')
					get_player_direction_1(player, map[y][x]);
				else
					get_player_direction_2(player, map[y][x]);
				player->pos_x = x + 0.5;
				player->pos_y = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_player_direction_1(t_player *player, char dir_char)
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

void	get_player_direction_2(t_player *player, char dir_char)
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

void	move_pov(t_cube *cube, t_player	*player, int syskey)
{
	int			new_pos_x;
	int			new_pos_y;
	
	if (syskey == KEY_W)
	{
		new_pos_x = player->pos_x + player->dir_x * MOV_SPD;
		new_pos_y = player->pos_y + player->dir_y * MOV_SPD;
		if (is_wall(cube, new_pos_x, new_pos_y) == false)
		{
			player->pos_y += player->dir_y * MOV_SPD;
			player->pos_x += player->dir_x * MOV_SPD;
		}
	}
	if (syskey == KEY_A)
	{
		new_pos_x = player->pos_x + player->dir_y * MOV_SPD;
		new_pos_y = player->pos_y - player->dir_x * MOV_SPD;
		if (is_wall(cube, new_pos_x, new_pos_y) == false)
		{
			player->pos_y += -player->dir_x * MOV_SPD;
			player->pos_x += player->dir_y * MOV_SPD;
		}
	}
	if (syskey == KEY_S)
	{
		new_pos_x = player->pos_x - player->dir_x * MOV_SPD;
		new_pos_y = player->pos_y - player->dir_y * MOV_SPD;
		if (is_wall(cube, new_pos_x, new_pos_y) == false)
		{
			player->pos_y -= player->dir_y * MOV_SPD;
			player->pos_x -= player->dir_x * MOV_SPD;
		}
	}
	if (syskey == KEY_D)
	{
		new_pos_x = player->pos_x - player->dir_y * MOV_SPD;
		new_pos_y = player->pos_y + player->dir_x * MOV_SPD;
		if (is_wall(cube, new_pos_x, new_pos_y) == false)
		{
			player->pos_y += player->dir_x * MOV_SPD;
			player->pos_x += -player->dir_y * MOV_SPD;
		}
	}
	printf("Current POS: x = %f, y = %f\n",
		player->pos_x, player->pos_y);
}

void	rotate_pov(t_cube *cube, t_player *player, int syskey)
{
	float		old_dir_x;
	float		old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	if (syskey == KEY_LEFT)
	{
		player->dir_x = old_dir_x * cos(-ROT_SPD) - player->dir_y * sin(-ROT_SPD);
		player->dir_y = old_dir_x * sin(-ROT_SPD) + player->dir_y * cos(-ROT_SPD);
		player->plane_x = old_plane_x * cos(-ROT_SPD) - player->plane_y * sin(-ROT_SPD);
		player->plane_y = old_plane_x * sin(-ROT_SPD) + player->plane_y * cos(-ROT_SPD);
	}
	if (syskey == KEY_RIGHT)
	{
		player->dir_x = old_dir_x * cos(ROT_SPD) - player->dir_y * sin(ROT_SPD);
		player->dir_y = old_dir_x * sin(ROT_SPD) + player->dir_y * cos(ROT_SPD);
		player->plane_x = old_plane_x * cos(ROT_SPD) - player->plane_y * sin(ROT_SPD);
		player->plane_y = old_plane_x * sin(ROT_SPD) + player->plane_y * cos(ROT_SPD);
	}
	printf("Current DIR: x = %f, y = %f\n",
		cube->player.dir_x, cube->player.dir_y);
}
