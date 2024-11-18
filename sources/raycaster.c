/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:33:58 by juitz             #+#    #+#             */
/*   Updated: 2024/11/18 08:52:47 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	draw_pov(t_cube *cube)
{
	int	x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		calculate_ray_dir(&cube->rays, &cube->player, x);
		calculate_distances(&cube->player, &cube->rays);
		search_for_next_wall(cube, &cube->rays);
		calculate_wall_height(&cube->player, &cube->rays);
		draw_textures(cube, &cube->rays, x, 0);
		x++;
	}
}

void	calculate_ray_dir(t_ray *rays, t_player *player, int x)
{
	double camera_x;
	
	camera_x = (x * 2) / (double)WINDOW_WIDTH - 1;
	rays->dir_x = player->dir_x + player->plane_x * camera_x;
	rays->dir_y = player->dir_y + player->plane_y * camera_x;
}

void	calculate_distances(t_player *p, t_ray *rays)
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

void	search_for_next_wall(t_cube *cube, t_ray *rays)
{
	while (true)
	{
		if (rays->init_step_x < rays->init_step_y)
		{
			rays->side = 0;
			rays->map_x += rays->step_x;
			rays->init_step_x += rays->delta_dist_x;
		}
		else 
		{
			rays->side = 1;
			rays->map_y += rays->step_y;
			rays->init_step_y += rays->delta_dist_y;
		}
		if (cube->map[rays->map_y][rays->map_x] == '1')
		{
			//printf("Wall hit at [%i,%i]\n", rays->map_x, rays->map_y);
			break ;
		}
	}
}

void	calculate_wall_height(t_player *p, t_ray *rays)
{
	double	wall_dist;

	if (rays->side == 0)
		wall_dist = ((double)rays->map_x - p->pos_x + (double)(1 - rays->step_x) / 2) / rays->dir_x;
	if (rays->side == 1)
		wall_dist = ((double)rays->map_y - p->pos_y + (double)(1 - rays->step_y) / 2) / rays->dir_y;
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
	rays->wall_hit = rays->wall_hit - floor((rays->wall_hit));
}

void	draw_textures(t_cube *cube, t_ray *rays, int x, int y)
{
	int 	tex_x;
	int 	tex_y;
	double	tex_pos;
	int		tex_color;
	double	step;
	
	tex_x = rays->wall_hit * IMAGE_WIDTH;
    if (rays->side == 0 && rays->dir_x > 0)
    	tex_x = tex_x - IMAGE_WIDTH - 1; //SWITCH AROUND THE MIRROR THE E texture
    if (rays->side == 1 && rays->dir_y < 0)
    		tex_x = tex_x - IMAGE_WIDTH - 1; //SWITCH AROUND THE MIRROR THE  texture
	step = IMAGE_HEIGHT * 1.0 / rays->line_height;
	tex_pos = (rays->draw_start - WINDOW_HEIGHT / 2 + rays->line_height / 2) * step;
	while (y < rays->draw_start)
		mlx_pixel_put(cube->mlx_ptr, cube->window_ptr, x, y++, cube->ceiling_color);
	while (y <= rays->draw_end)
	{
		tex_y = (int)tex_pos & (IMAGE_HEIGHT - 1);
		tex_pos += step;
		tex_color = get_correct_texture_color(cube, rays, tex_x, tex_y);
		if (tex_color > 0)
			mlx_pixel_put(cube->mlx_ptr, cube->window_ptr, x, y, tex_color);
		y++;
	}
	while (y <= WINDOW_HEIGHT)
		mlx_pixel_put(cube->mlx_ptr, cube->window_ptr, x, y++, cube->floor_color);
}

int	get_correct_texture_color(t_cube *cube, t_ray *rays, int tex_x, int tex_y)
{
	int	tex_color;
	
	if (rays->side == 1)
	{
		if (rays->dir_y < 0)
			tex_color = cube->wall_north.addr[tex_x + IMAGE_HEIGHT * tex_y];
		else
			tex_color = cube->wall_south.addr[tex_x + IMAGE_HEIGHT * tex_y];
	}
	else
	{
		if (rays->dir_x < 0)
			tex_color = cube->wall_west.addr[tex_x + IMAGE_HEIGHT * tex_y];
		else
			tex_color = cube->wall_east.addr[tex_x + IMAGE_HEIGHT * tex_y];
	}
	if (rays->side == 1)
    	tex_color = (tex_color >> 1) & 8355711;
	return (tex_color);
}
