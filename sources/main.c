/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaintha <shaintha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:18:58 by shaintha          #+#    #+#             */
/*   Updated: 2024/10/14 14:54:31 by shaintha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

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
	if (get_images(&cube) == 1)
		return (free_images(&cube), free_cube(&cube), 1);
	// if (run_cube(&cube) == 1)
	// 	return (1);
	return (free_cube(&cube), 0);
}
