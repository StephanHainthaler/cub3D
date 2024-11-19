/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:45:27 by juitz             #+#    #+#             */
/*   Updated: 2024/11/19 11:13:53 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	forward_back(t_cube *cube, t_player	*player, int syskey)
{
	int	new_pos_x;
	int	new_pos_y;

	if (syskey == KEY_W)
	{
		new_pos_x = player->pos_x + player->dir_x * MOV_SPD;
		new_pos_y = player->pos_y + player->dir_y * MOV_SPD;
		if (is_wall(cube, new_pos_x, new_pos_y) == false)
		{
			player->pos_x += player->dir_x * MOV_SPD;
			player->pos_y += player->dir_y * MOV_SPD;
		}
	}
	if (syskey == KEY_S)
	{
		new_pos_x = player->pos_x - player->dir_x * MOV_SPD;
		new_pos_y = player->pos_y - player->dir_y * MOV_SPD;
		if (is_wall(cube, new_pos_x, new_pos_y) == false)
		{
			player->pos_x -= player->dir_x * MOV_SPD;
			player->pos_y -= player->dir_y * MOV_SPD;
		}
	}
}

void	strafe(t_cube *cube, t_player *player, int syskey)
{
	int	new_pos_x;
	int	new_pos_y;

	if (syskey == KEY_A)
	{
		new_pos_x = player->pos_x + player->dir_y * MOV_SPD;
		new_pos_y = player->pos_y - player->dir_x * MOV_SPD;
		if (is_wall(cube, new_pos_x, new_pos_y) == false)
		{
			player->pos_x += player->dir_y * MOV_SPD;
			player->pos_y += -player->dir_x * MOV_SPD;
		}
	}
	if (syskey == KEY_D)
	{
		new_pos_x = player->pos_x - player->dir_y * MOV_SPD;
		new_pos_y = player->pos_y + player->dir_x * MOV_SPD;
		if (is_wall(cube, new_pos_x, new_pos_y) == false)
		{
			player->pos_x += -player->dir_y * MOV_SPD;
			player->pos_y += player->dir_x * MOV_SPD;
		}
	}
}

void	movement(t_cube *cube, t_player	*player, int syskey)
{
	if (syskey == KEY_W || syskey == KEY_S)
		forward_back(cube, player, syskey);
	if (syskey == KEY_A || syskey == KEY_D)
		strafe(cube, player, syskey);
}

void	rotate_pov(t_player *p, int syskey)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	if (syskey == KEY_LEFT)
	{
		p->dir_x = old_dir_x * cos(-ROT_SPD) - p->dir_y * sin(-ROT_SPD);
		p->dir_y = old_dir_x * sin(-ROT_SPD) + p->dir_y * cos(-ROT_SPD);
		p->plane_x = old_plane_x * cos(-ROT_SPD) - p->plane_y * sin(-ROT_SPD);
		p->plane_y = old_plane_x * sin(-ROT_SPD) + p->plane_y * cos(-ROT_SPD);
	}
	if (syskey == KEY_RIGHT)
	{
		p->dir_x = old_dir_x * cos(ROT_SPD) - p->dir_y * sin(ROT_SPD);
		p->dir_y = old_dir_x * sin(ROT_SPD) + p->dir_y * cos(ROT_SPD);
		p->plane_x = old_plane_x * cos(ROT_SPD) - p->plane_y * sin(ROT_SPD);
		p->plane_y = old_plane_x * sin(ROT_SPD) + p->plane_y * cos(ROT_SPD);
	}
}
