/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:32:10 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/13 15:58:40 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	setup_cube(t_cube *cube)
{
	t_player	player;

	cube->mlx_ptr = mlx_init();
	if (cube->mlx_ptr == NULL)
		return (put_error("MLX pointer initialization failed!"), 1);
	cube->window_ptr = mlx_new_window(cube->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub:3D");
	if (cube->window_ptr == NULL)
		return (put_error("Window pointer initialization failed!"), 1);
	if (get_images(cube) == 1)
		return (put_error("Texture(s) have not been found!"), 1);
	get_player_info(&player, cube->map);
	cube->player = player;
	printf("Player Start: x = %f, y = %f\n",
		cube->player.pos_x, cube->player.pos_y);
	return (0);
}

int	run_cube(t_cube *cube)
{
	if (setup_cube(cube) == 1)
		return (free_cube(cube), 1);
	draw_pov(cube);
	mlx_hook(cube->window_ptr, KeyPress, KeyPressMask, key_pressed, cube);
	mlx_hook(cube->window_ptr, DestroyNotify, StructureNotifyMask,
		close_cube, cube);
	mlx_loop(cube->mlx_ptr);
	return (0);
}

int	key_pressed(int syskey, t_cube *cube)
{
	if (syskey == KEY_ESC)
		close_cube(cube);
	else if (syskey == KEY_W || syskey == KEY_A
		|| syskey == KEY_S || syskey == KEY_D)
		move_pov(cube, &cube->player, syskey);
	else if (syskey == KEY_LEFT || syskey == KEY_RIGHT)
		rotate_pov(cube, &cube->player, syskey);
	draw_pov(cube);
	return (0);
}

int	close_cube(t_cube *cube)
{
	free_cube(cube);
	exit(0);
	return (0);
}
