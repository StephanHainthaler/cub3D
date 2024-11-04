/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:05:07 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/04 13:51:27 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void    render_pov2(t_cube *cube)
{
	
}

void    render_pov(t_cube *cube, t_player player)
{
	(void)player;
	int			x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;

	cube->player.dir_x = -1.0;
	cube->player.dir_y = 0;
	plane_x = 0;
	plane_y = 0.66;
	camera_x = 1;
	
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ray_dir_x = cube->player.dir_x + plane_x * camera_x;
		ray_dir_y = cube->player.dir_y + plane_y * camera_x;
		//x++; //maybe outcomment
	
		int map_x = (int)cube->player.pos_x;
		int map_y = (int)cube->player.pos_y;

		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);

		int step_x;
		int step_y;

		double side_dist_x;
		double side_dist_y;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (cube->player.pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - cube->player.pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (cube->player.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - cube->player.pos_y) * delta_dist_y;
		}
		
		int side;
		while (true)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (cube->map[map_y][map_x] == '1') //maybe switch x and y
				break;
		}

		//get distance from wall
		double wall_x;
		double wall_dist;

		if (side == 0)
			wall_dist = (map_x - cube->player.pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			wall_dist = (map_y - cube->player.pos_y + (1 - step_y) / 2) / ray_dir_y;

		int line_height = (int)(SCREEN_HEIGHT / wall_dist);

		int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;

		int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;

		if (side == 0)
			wall_x = cube->player.pos_y + wall_dist * ray_dir_y;
		else
			wall_x = cube->player.pos_x + wall_dist * ray_dir_x;
		//wall_x -= floor(wall_x);
		

		
	}
}
