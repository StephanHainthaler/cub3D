/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:33:58 by juitz             #+#    #+#             */
/*   Updated: 2024/11/13 16:11:17 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	draw_pov(t_cube *cube)
{
	size_t	x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		calculate_ray_dir(&cube->rays, &cube->player, x);
		calculate_distances(&cube->player, &cube->rays);
		search_for_next_wall(cube, &cube->rays);
		calculate_wall_height(&cube->player, &cube->rays);
		draw_textures(cube, &cube->rays, x);
		x++;
	}
}

void	calculate_ray_dir(t_rays *rays, t_player *player, size_t x)
{
	float camera_x;
	
	camera_x = (x * 2) / (float)WINDOW_WIDTH - 1;
	rays->dir_x = player->dir_x + player->plane_x * camera_x;
	rays->dir_y = player->dir_y + player->plane_y * camera_x;
}

void	calculate_distances(t_player *p, t_rays *rays)
{
	rays->delta_dist_x = fabs(1 / rays->dir_x);
	rays->delta_dist_y = fabs(1 / rays->dir_y);
	rays->map_x = (int)p->pos_x;
	rays->map_y = (int)p->pos_y;
	if (rays->dir_x < 0)
	{
		rays->step_x = -1;
		rays->init_step_x = (p->pos_x - rays->map_x) * rays->delta_dist_x;
	}
	else
	{
		rays->step_x = 1;
		rays->init_step_x = (rays->map_x + 1 - p->pos_x) * rays->delta_dist_x;
	}
	if (rays->dir_y < 0)
	{
		rays->step_y = -1;
		rays->init_step_x = (p->pos_y - rays->map_y) * rays->delta_dist_y;
	}
	else
	{
		rays->step_y = 1;
		rays->init_step_y = (rays->map_y + 1 - p->pos_y) * rays->delta_dist_y;
	}
}

void	search_for_next_wall(t_cube *cube, t_rays *rays)
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
		//x and y are correct or not?!?
		if (cube->map[rays->map_y][rays->map_x] == '1')
			break ;
	}
}

void	calculate_wall_height(t_player *p, t_rays *rays)
{
	float	wall_dist;

	if (rays->side == 0)
		wall_dist = (rays->map_x - p->pos_x + (float)(1 - rays->step_x) / 2) / rays->dir_x;
	if (rays->side == 1)
		wall_dist = (rays->map_y - p->pos_y + (float)(1 - rays->step_y) / 2) / rays->dir_y;
	rays->line_height = (int)(WINDOW_HEIGHT / wall_dist);
	rays->draw_start = -rays->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rays->draw_start < 0)
		rays->draw_start = 0;
	rays->draw_end = rays->line_height / 2 + WINDOW_HEIGHT / 2;
	if (rays->draw_end >= WINDOW_HEIGHT)
		rays->draw_end = WINDOW_HEIGHT - 1;
	if (rays->side == 0)
		rays->wall_hit = p->pos_y + wall_dist * rays->dir_y;
	else
	 	rays->wall_hit = p->pos_x + wall_dist * rays->dir_x;
	rays->wall_hit -= floor(rays->wall_hit);
}

void	draw_textures(t_cube *cube, t_rays *rays, size_t x)
{
	int 	texX;
	int 	texY;
	double	step;
	double	texPos;
	int		y;
	int		tex_color;
	
	texX = rays->wall_hit * IMAGE_WIDTH;
    if (rays->side == 0 && rays->dir_x > 0)
	{
    	texX = IMAGE_WIDTH - texX - 1;
	}
    if (rays->side == 1 && rays->dir_y < 0)
	{
    	texX = IMAGE_WIDTH - texX - 1;
	}
	step = 1.0 * IMAGE_HEIGHT / rays->line_height;
	texPos = (rays->draw_start - WINDOW_HEIGHT / 2 + rays->line_height / 2) * step;
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
		if (rays->side == 1)
		{
			if (rays->dir_x < 0)
				tex_color = cube->wall_east.addr[IMAGE_HEIGHT * texY + texX];
			else
				tex_color = cube->wall_west.addr[IMAGE_HEIGHT * texY + texX];
		}
		else
		{
			if (rays->dir_y < 0)
				tex_color = cube->wall_north.addr[IMAGE_HEIGHT * texY + texX];
			else
				tex_color = cube->wall_south.addr[IMAGE_HEIGHT * texY + texX];
		}
		// if (rays->side == 1)
        // 	tex_color = (tex_color >> 1) & 8355711;
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
