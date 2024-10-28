/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:18:58 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/28 09:16:27 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void	print_cube(t_cube *cube)
{
	printf("North Wall Path: %s\n", cube->n_path);
	printf("East Wall Path: %s\n", cube->e_path);
	printf("South Wall Path: %s\n", cube->s_path);
	printf("West Wall Path: %s\n", cube->w_path);
	printf("Floor Color RGB: %s\n", cube->f_color);
	//printf("Floor Color Code: %i\n", cube->floor_color);
	printf("Ceiling Color RGB: %s\n", cube->c_color);
	//printf("Ceiling Color Code: %i\n", cube->ceiling_color);
	printf("Map-Layout:\n");
	ft_putstrarr_fd(cube->map, 1);
}

int main(int argc, char *argv[])
{
	t_cube	cube;
	
	if (argc != 2)
		return (printf("Wrong number of arguments\n"), 1);
	if (is_format_valid(argv[1], ".cub") == false)
		return (printf("Wrong format\n"), 1);
	initialize_cube(&cube);
	if (parse_map(&cube, argv[1]) == 1)
		return (1);
	print_cube(&cube);
	if (run_cube(&cube) == 1)
		return (1);
	free_cube(&cube);
	return (0);
}
