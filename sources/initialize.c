/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:35:19 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/13 14:44:48 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	initialize_cube(t_cube *cube)
{
	t_player	player;
	t_rays		rays;

	cube->mlx_ptr = NULL;
	cube->window_ptr = NULL;
	cube->map_str = NULL;
	cube->map = NULL;
	cube->n_path = NULL;
	cube->e_path = NULL;
	cube->s_path = NULL;
	cube->w_path = NULL;
	cube->wall_north.ptr = NULL;
	cube->wall_east.ptr = NULL;
	cube->wall_south.ptr = NULL;
	cube->wall_west.ptr = NULL;
	cube->f_color = NULL;
	cube->c_color = NULL;
	cube->error_code = 0;
	ft_bzero(&player, sizeof(&player));
	cube->player = player;
	initialize_rays(&rays);
	cube->rays = rays;
}

void	initialize_rays(t_rays *rays)
{
	rays->delta_dist_x = 0;
	rays->delta_dist_y = 0;
	rays->step_x = 0;
	rays->step_y = 0;
	rays->map_x = 0;
	rays->map_y = 0;
	rays->side = 0;
	rays->init_step_x = 0;
	rays->init_step_y = 0;
	rays->dir_x = 0;
	rays->dir_y = 0;
	rays->wall_height = 0;
	rays->wall_hit = 0;
	rays->line_height = 0;
	rays->draw_start = 0;
	rays->draw_end = 0;
}

void	free_cube(t_cube *cube)
{
	ft_free(cube->map_str);
	ft_free(cube->n_path);
	ft_free(cube->e_path);
	ft_free(cube->s_path);
	ft_free(cube->w_path);
	ft_free(cube->f_color);
	ft_free(cube->c_color);
	if (cube->map != NULL)
		ft_free_strarr(cube->map);
	free_images(cube);
	if (cube->window_ptr != NULL)
		mlx_destroy_window(cube->mlx_ptr, cube->window_ptr);
	if (cube->mlx_ptr != NULL)
	{
		mlx_destroy_display(cube->mlx_ptr);
		free(cube->mlx_ptr);
	}
}
