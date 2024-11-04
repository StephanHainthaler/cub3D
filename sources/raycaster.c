/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:33:58 by juitz             #+#    #+#             */
/*   Updated: 2024/11/04 15:19:48 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	calc_rays(t_cube *cube, t_player *player, t_rays *rays)
{
	int x;
	float camera_x;
	
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = 2 * x / (float)SCREEN_WIDTH - 1;
		rays->ray_dir_x = player->dir_x + player->plane_x * camera_x;
		rays->ray_dir_y = player->dir_y + player->plane_y * camera_x;
		calc_distances(cube, player, rays);
		x++;
	}
}

void	calc_distances(t_cube *cube, t_player *player, t_rays *rays)
{
	rays->map_x = (int)player->pos_x;
	rays->map_y = (int)player->pos_y;
	rays->delta_dist_x = fabs(1 / rays->ray_dir_x);
	rays->delta_dist_y = fabs(1 / rays->ray_dir_y);

	if (player->dir_x < 0)
	{
		rays->step_x = -1;
		rays->init_step_x = (player->pos_x - rays->map_x) * rays->delta_dist_x;
	}
	else if (player->dir_x > 0)
	{
		rays->step_x = 1;
		rays->init_step_x = (rays->map_x + 1 - player->pos_x) * rays->delta_dist_x;
	}
	if (player->dir_y < 0)
	{
		rays->step_y = -1;
		rays->init_step_x = (player->pos_y - rays->map_y) * rays->delta_dist_y;
	}
	else if (player->dir_y > 0)
	{
		rays->step_y = 1;
		rays->init_step_y = (rays->map_y + 1 - player->pos_y) * rays->delta_dist_y;
	}
}
