/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:32:10 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/15 13:12:28 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	setup_cube(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	if (cube->mlx_ptr == NULL)
		return (put_error("MLX pointer initialization failed!"), 1);
	cube->window_ptr = mlx_new_window(cube->mlx_ptr,
		500, 500, "cub:3D");
	if (cube->window_ptr == NULL)
		return (put_error("Window pointer initialization failed!"), 1);
	if (get_images(cube) == 1)
		return (put_error("Texture(s) have not been found!"), 1);
	return (0);
}

int	run_cube(t_cube *cube)
{
	if (setup_cube(cube) == 1)
		return (free_cube(cube), 1);
	mlx_pixel_put(cube->mlx_ptr, cube->window_ptr, 100, 100, cube->floor_color);
	mlx_hook(cube->window_ptr, KeyPress, KeyPressMask, key_pressed, cube);
	mlx_hook(cube->window_ptr, DestroyNotify, StructureNotifyMask,
		&close_cube, cube);
	mlx_loop(cube->mlx_ptr);
	return (0);
}

int	key_pressed(int syskey, t_cube *cube)
{
	if (syskey == KEY_ESC)
		close_cube(cube);
	return (0);
}

int	close_cube(t_cube *cube)
{
	free_cube(cube);
	exit(0);
	return (0);
}
