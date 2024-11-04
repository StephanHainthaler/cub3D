/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:32:10 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/04 12:47:52 by shaintha         ###   ########.fr       */
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
		500, 500, "cub:3D");
	if (cube->window_ptr == NULL)
		return (put_error("Window pointer initialization failed!"), 1);
	if (get_images(cube) == 1)
		return (put_error("Texture(s) have not been found!"), 1);
	get_player_info(&player, cube->map);
	cube->player = player;
	printf("Player Start: x = %f, y = %f\n", cube->player.pos_x, cube->player.pos_y);
	return (0);
}

int	run_cube(t_cube *cube)
{
	if (setup_cube(cube) == 1)
		return (free_cube(cube), 1);
	mlx_pixel_put(cube->mlx_ptr, cube->window_ptr, 100, 100, cube->floor_color);
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
	else if (syskey ==  KEY_W || syskey == KEY_A
		|| syskey ==  KEY_S || syskey == KEY_D)
		move_pov(cube, syskey);
	// else if (syskey ==  KEY_LEFT || syskey == KEY_RIGHT)
	// 	rotate_pov(cube);
	return (0);
}

int	close_cube(t_cube *cube)
{
	free_cube(cube);
	exit(0);
	return (0);
}

void	move_pov(t_cube *cube, int syskey)
{
	t_player	player;

	player = cube->player;
	if (syskey == KEY_W)
		if (is_wall(cube, player.pos_x, player.pos_y - MOV_SPD) == false)
			player.pos_y = player.pos_y - MOV_SPD;
	if (syskey == KEY_A)
		if (is_wall(cube, player.pos_x - MOV_SPD, player.pos_y) == false)
			player.pos_x = player.pos_x - MOV_SPD;
	if (syskey == KEY_S)
		if (is_wall(cube, player.pos_x, player.pos_y + MOV_SPD) == false)
			player.pos_y = player.pos_y + MOV_SPD;
	if (syskey == KEY_D)
		if (is_wall(cube, player.pos_x + MOV_SPD, player.pos_y) == false)
			player.pos_x = player.pos_x + MOV_SPD;
	cube->player = player;
	printf("Current POS: x = %f, y = %f\n", cube->player.pos_x, cube->player.pos_y);
	render_pov(cube, player);
}

bool	is_wall(t_cube *cube, float x, float y)
{
	int		ix;
	int		iy;
	
	ix = x;
	iy = y;
	if (cube->map[iy][ix] == '1' || cube->map[iy][ix] == ' ')
		return (true);
	return (false);
}

void	get_player_info(t_player *player, char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'N' || map[y][x] == 'E'
				|| map[y][x] == 'S' || map[y][x] == 'W')
			{
				get_player_direction(player, map[y][x]);
				player->pos_x = x;
				player->pos_y = y;
				// player->pos_x = player->pos_x + 0.5;
				// player->pos_y = player->pos_y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_player_direction_ns(t_player *player, char dir_char)
{
	if (dir_char == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	if (dir_char == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}
void	get_player_direction_ew(t_player *player, char dir_char)
{
	if (dir_char == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	if (dir_char == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

void	get_player_direction(t_player *player, char dir_char)
{
	get_player_direction_ns(player, dir_char);
	get_player_direction_ew(player, dir_char);
}
