/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:35:19 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/29 14:13:04 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	initialize_cube(t_cube *cube, t_player *player)
{
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
	ft_bzero(player, sizeof(&player));
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

void	free_images(t_cube *cube)
{
	if (cube->wall_north.ptr != NULL)
		mlx_destroy_image(cube->mlx_ptr, cube->wall_north.ptr);
	if (cube->wall_east.ptr != NULL)
		mlx_destroy_image(cube->mlx_ptr, cube->wall_east.ptr);
	if (cube->wall_south.ptr != NULL)
		mlx_destroy_image(cube->mlx_ptr, cube->wall_south.ptr);
	if (cube->wall_west.ptr != NULL)
		mlx_destroy_image(cube->mlx_ptr, cube->wall_west.ptr);
}

void	init_player(t_cube *cube, t_player *player)
{
	size_t	y;
	size_t	x;
	
	y = 0;
	while (cube->map[y])
	{
		x = 0;
		while (cube->map[y][x])
		{
			if (cube->map[y][x] == 'N' || cube->map[y][x] == 'E' || cube->map[y][x] == 'S' || cube->map[y][x] == 'W')
			{
				player->pos_y = y;
				player->pos_x = x;
			}
			x++;
		}
		y++;
	}
}

