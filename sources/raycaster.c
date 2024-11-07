/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:33:58 by juitz             #+#    #+#             */
/*   Updated: 2024/11/07 18:19:25 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	calc_rays(t_cube *cube, t_player *player, t_rays *rays)
{
	int x;
	float camera_x;
	
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		camera_x = 2 * x / (float)WINDOW_WIDTH - 1;
		rays->ray_dir_x = player->dir_x + player->plane_x * camera_x;
		rays->ray_dir_y = player->dir_y + player->plane_y * camera_x;
		calc_distances(cube, player, rays);
		check_next_wall(cube, player, rays);
		calc_wall_height(cube, player, rays);
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

void	check_next_wall(t_cube *cube, t_player *player, t_rays *rays)
{
	while(1)
	{
		if (rays->init_step_x > rays->init_step_y)
		{
			rays->side = 0;
			rays->init_step_x += rays->delta_dist_x;
			rays->map_x = rays->step_x;
		}
		else 
		{
			rays->side = 1;
			rays->init_step_y += rays->delta_dist_y;
			rays->map_y = rays->step_y;
		}
		if (cube->map[rays->map_x][rays->map_y] == '1')
			break ;
	}
}

void	calc_wall_height(t_cube *cube, t_player *player, t_rays * rays)
{
	float	wall_dist;
	float	wall_hit;
	int		line_height;
	int		draw_start;
	int		draw_end;

	if (rays->side == 0)
		wall_dist = (rays->map_x - player->pos_x + (float)(1 - rays->step_x) / 2) / rays->ray_dir_x;
	else if (rays->side == 1)
		wall_dist = (rays->map_y - player->pos_y + (float)(1 - rays->step_y) / 2) / rays->ray_dir_y;
	line_height = (int)(WINDOW_HEIGHT / wall_dist);
	draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	if (rays->side == 0)
		wall_hit = player->pos_y + wall_dist * rays->ray_dir_y;
	else
	 	wall_hit = player->pos_x + wall_dist * rays->ray_dir_x;
	wall_hit -= floor(wall_hit);
}
