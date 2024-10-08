/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:35:19 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/08 12:41:02 by shaintha         ###   ########.fr       */
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
}
