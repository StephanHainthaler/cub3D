/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:33:58 by juitz             #+#    #+#             */
/*   Updated: 2024/11/13 13:32:44 by juitz            ###   ########.fr       */
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
		calc_distances(player, rays);
		check_next_wall(cube, rays);
		calc_wall_height(player, rays);
		draw_pov(cube, rays, x);
		x++;
	}
}

void	calc_distances(t_player *player, t_rays *rays)
{
	rays->map_x = (int)player->pos_x;
	rays->map_y = (int)player->pos_y;
	rays->delta_dist_x = fabs(1 / rays->ray_dir_x);
	rays->delta_dist_y = fabs(1 / rays->ray_dir_y);

	if (rays->ray_dir_x < 0)
	{
		rays->step_x = -1;
		rays->init_step_x = (player->pos_x - rays->map_x) * rays->delta_dist_x;
	}
	else //else if (player->dir_x > 0)
	{
		rays->step_x = 1;
		rays->init_step_x = (rays->map_x + 1.0 - player->pos_x) * rays->delta_dist_x;
	}
	if (rays->ray_dir_y < 0)
	{
		rays->step_y = -1;
		rays->init_step_x = (player->pos_y - rays->map_y) * rays->delta_dist_y;
	}
	else //if (player->dir_y > 0)
	{
		rays->step_y = 1;
		rays->init_step_y = (rays->map_y + 1.0 - player->pos_y) * rays->delta_dist_y;
	}
}

void	check_next_wall(t_cube *cube, t_rays *rays)
{
	while (true)
	{
		if (rays->init_step_x < rays->init_step_y)
		{
			rays->init_step_x += rays->delta_dist_x;
			rays->map_x += rays->step_x;
			rays->side = 0;
		}
		else 
		{
			rays->init_step_y += rays->delta_dist_y;
			rays->map_y += rays->step_y;
			rays->side = 1;
		}
		if (cube->map[rays->map_y][rays->map_x] == '1') //x and y are correct or not?!?
			break ;
	}
}

void	calc_wall_height(t_player *player, t_rays *rays)
{
	float	wall_dist;

	if (rays->side == 0)
		wall_dist = (rays->map_x - player->pos_x + (float)(1 - rays->step_x) / 2) / rays->ray_dir_x;
	if (rays->side == 1)
		wall_dist = (rays->map_y - player->pos_y + (float)(1 - rays->step_y) / 2) / rays->ray_dir_y;
	rays->line_height = (int)(WINDOW_HEIGHT / wall_dist);

	rays->draw_start = -rays->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rays->draw_start < 0)
		rays->draw_start = 0;
	rays->draw_end = rays->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rays->draw_end >= WINDOW_HEIGHT)
		rays->draw_end = WINDOW_HEIGHT - 1;
	if (rays->side == 0)
		rays->wall_hit = player->pos_y + wall_dist * rays->ray_dir_y;
	else
	 	rays->wall_hit = player->pos_x + wall_dist * rays->ray_dir_x;
	rays->wall_hit -= floor(rays->wall_hit);
}

void	draw_pov(t_cube *cube, t_rays *rays, int x)
{
	int 	texX;
	int 	texY;
	double	step;
	double	texPos;
	int		y;
	int		tex_color;
	
	texX = rays->wall_hit * IMAGE_WIDTH;
    if (rays->side == 0 && rays->ray_dir_x > 0)
	{
    	texX = IMAGE_WIDTH - texX - 1;
	}
    if (rays->side == 1 && rays->ray_dir_y < 0)
	{
    	texX = IMAGE_WIDTH - texX - 1;
	}
	step = 1.0 * IMAGE_HEIGHT / rays->line_height;
	texPos = (rays->draw_start /*- pitch == 100*/ - WINDOW_HEIGHT / 2 + rays->line_height / 2) * step;
	y = 0;
	while (y < rays->draw_start)
	{
		mlx_pixel_put(cube->mlx_ptr, cube->window_ptr, x, y, cube->ceiling_color);
		y++;
	}
	while (y < rays->draw_end)
	{
		texY = (int)texPos & (IMAGE_HEIGHT - 1);
		texPos = texPos + step;
		//differentiate between N/E/S/W
		tex_color = cube->wall_north.addr[IMAGE_HEIGHT * texY + texX];
		if (rays->side == 1)
        	tex_color = (tex_color >> 1) & 8355711;
		if (tex_color > 0)
			mlx_pixel_put(cube->mlx_ptr, cube->window_ptr, x, y, tex_color);
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
		mlx_pixel_put(cube->mlx_ptr, cube->window_ptr, x, y, cube->floor_color);
		y++;
	}
	
}



bool	is_wall(t_cube *cube, float x, float y)
{
	char **map;
	int		ix;
	int		iy;

	map = cube->map;
	ix = x;
	iy = y;
	if (cube->map[iy][ix] == '1')
		return (true);
	return (false);
}
