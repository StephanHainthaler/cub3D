/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:35:19 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/14 11:20:48 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	initialize_cube(t_cube *cube)
{
	cube->mlx_ptr = NULL;
	cube->window_ptr = NULL;
	cube->map = NULL;
	cube->n_path = NULL;
	cube->e_path = NULL;
	cube->s_path = NULL;
	cube->w_path = NULL;
	cube->f_color = NULL;
	cube->c_color = NULL;
	initialize_images(cube);
}

void	free_cube(t_cube *cube)
{
	// ft_free(cube->n_path);
	// ft_free(cube->e_path);
	// ft_free(cube->s_path);
	// ft_free(cube->w_path);
	// ft_free(cube->f_color);
	// ft_free(cube->c_color);
	if (cube->map != NULL)
		ft_free_strarr(cube->map);
	if (cube->window_ptr != NULL)
		mlx_destroy_window(cube->mlx_ptr, cube->window_ptr);
	if (cube->mlx_ptr != NULL)
	{
		mlx_destroy_display(cube->mlx_ptr);
		free(cube->mlx_ptr);
	}
	
}
