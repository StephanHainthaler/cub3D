/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:33:58 by juitz             #+#    #+#             */
/*   Updated: 2024/10/31 17:27:11 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	calc_ray_direction(t_cube *cube, t_player *player, t_rays *rays)
{
	int x;
	float camera_x;
	
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = 2 * x / (float)SCREEN_WIDTH - 1;
		rays->ray_dir_x = player->dir_x + player->plane_x * camera_x;
		rays->ray_dir_y = player->dir_y + player->plane_y * camera_x;
		x++;
	}
}

void	calc_distances(t_cube *cube, t_player *player, t_rays *rays)
{
	rays->delta_dist_x = fabs(1 / rays->ray_dir_x);
	rays->delta_dist_y = fabs(1 / rays->ray_dir_y);

	if (player->dir_x < 0)
	{
		rays->step_x = -1;
		rays->init_step_x = player->pos_x - cube->map
		
	}
}