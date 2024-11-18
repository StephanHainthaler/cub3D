/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:16:37 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/18 14:39:36 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	draw_textures(t_cube *cube, t_ray *rays, int x, int y)
{
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	int		tex_color;
	double	step;

	tex_pos = get_texture_position(cube, &cube->rays, &tex_x, &step);
	while (y < rays->draw_start)
		mlx_pixel_put(cube->mlx_ptr, cube->window_ptr,
			x, y++, cube->ceiling_color);
	while (y <= rays->draw_end)
	{
		tex_y = (int)tex_pos & (cube->screen_h - 1);
		tex_pos += step;
		tex_color = get_texture_color(cube, rays, tex_x, tex_y);
		if (tex_color > 0)
			mlx_pixel_put(cube->mlx_ptr, cube->window_ptr,
				x, y, tex_color);
		y++;
	}
	while (y <= WINDOW_HEIGHT)
		mlx_pixel_put(cube->mlx_ptr, cube->window_ptr,
			x, y++, cube->floor_color);
}

double	get_texture_position(t_cube *cube, t_ray *rays, int *tex_x, double *step)
{
	double	tex_pos;

	*tex_x = rays->wall_hit * cube->screen_w;
	if ((rays->side == 0 && rays->dir_x > 0)
		|| (rays->side == 1 && rays->dir_y < 0))
		*tex_x = *tex_x - cube->screen_w - 1;
	else
		*tex_x = cube->screen_w - *tex_x - 1;
	*step = cube->screen_h * 1.0 / rays->line_height;
	tex_pos = (rays->draw_start
			- WINDOW_HEIGHT / 2 + rays->line_height / 2) * *step;
	return (tex_pos);
}

int	get_texture_color(t_cube *cube, t_ray *rays, int tex_x, int tex_y)
{
	int	tex_color;

	if (rays->side == 1)
	{
		if (rays->dir_y < 0)
			tex_color = cube->wall_north.addr[tex_x + cube->screen_h * tex_y];
		else
			tex_color = cube->wall_south.addr[tex_x + cube->screen_h * tex_y];
	}
	else
	{
		if (rays->dir_x < 0)
			tex_color = cube->wall_west.addr[tex_x + cube->screen_h * tex_y];
		else
			tex_color = cube->wall_east.addr[tex_x + cube->screen_h * tex_y];
	}
	if (rays->side == 1)
		tex_color = (tex_color >> 1) & 8355711;
	return (tex_color);
}
