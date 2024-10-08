/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:35:19 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/08 10:48:14 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	initialize_cube(t_cube *cube)
{
	cube->mlx_ptr = NULL;
	cube->window_ptr = NULL;
	cube->map = NULL;
	cube->wall_north = NULL;
	cube->wall_east = NULL;
	cube->wall_south = NULL;
	cube->wall_west = NULL;
}
