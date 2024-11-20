/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:45:27 by juitz             #+#    #+#             */
/*   Updated: 2024/11/20 10:51:12 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	movement(t_cube *cube, t_player	*player, int syskey)
{
	if (syskey == KEY_W || syskey == KEY_S)
		forward_back(cube, player, syskey);
	if (syskey == KEY_A || syskey == KEY_D)
		strafe(cube, player, syskey);
}

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
