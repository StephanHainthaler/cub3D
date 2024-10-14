/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:32:10 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/14 14:44:39 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	setup_cube(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	if (cube->mlx_ptr == NULL)
		return (1);
	// if (get_images(cube) == 1)
	// 	return (1);
	cube->window_ptr = mlx_new_window(cube->mlx_ptr,
		500, 500, "cub:3D");
	if (cube->window_ptr == NULL)
		return (1);
	return (0);
}

int	run_cube(t_cube *cube)
{
	if (setup_cube(cube) == 1)
		return (free_cube(cube), 1);
	mlx_hook(cube->window_ptr, DestroyNotify, StructureNotifyMask,
		&close_cube, &cube);
	mlx_loop(cube->mlx_ptr);
	return (0);
}


void	print_cube(t_cube *cube)
{
	printf("North Wall Path: %s\n", cube->n_path);
	printf("East Wall Path: %s\n", cube->e_path);
	printf("South Wall Path: %s\n", cube->s_path);
	printf("West Wall Path: %s\n", cube->w_path);
	
	printf("Floor Color RGB: %s\n", cube->f_color);
	printf("Floor Color Code: %i\n", cube->floor_color);
	
	printf("Ceiling Color RGB: %s\n", cube->c_color);
	printf("Ceiling Color Code: %i\n", cube->ceiling_color);
	printf("Map-Layout:\n");
	ft_putstrarr_fd(cube->map, 1);
}

int	close_cube(t_cube *cube)
{
	free_mlx(cube);
	free_cube(cube);
	exit(0);
	return (0);
}
