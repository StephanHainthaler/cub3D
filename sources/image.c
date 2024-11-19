/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:06:11 by shaintha          #+#    #+#             */
/*   Updated: 2024/11/19 09:59:43 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	get_images(t_cube *cube)
{
	cube->wall_north = get_image(cube, cube->n_path);
	cube->wall_east = get_image(cube, cube->e_path);
	cube->wall_south = get_image(cube, cube->s_path);
	cube->wall_west = get_image(cube, cube->w_path);
	if (cube->error_code == 1)
		return (put_error("Texture(s) not found!"), 1);
	if (cube->error_code == 2)
		return (put_error("Inconsistent texture height!"), 1);
	if (cube->error_code == 3)
		return (put_error("Inconsistent texture width!"), 1);
	return (0);
}

t_image	get_image(t_cube *cube, char *image_path)
{
	t_image	image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	image.ptr = mlx_xpm_file_to_image(cube->mlx_ptr, image_path,
			&image.x, &image.y);
	if (image.ptr == NULL)
		return (cube->error_code = 1, image);
	if (cube->image_h == 0)
		cube->image_h = image.y;
	else
		if (cube->image_h != (size_t)image.y)
			return (cube->error_code = 2, image);
	if (cube->image_w == 0)
		cube->image_w = image.x;
	else
		if (cube->image_w != (size_t)image.x)
			return (cube->error_code = 3, image);
	image.addr = (int *)mlx_get_data_addr(image.ptr,
			&bits_per_pixel, &size_line, &endian);
	return (image);
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
