/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:15:39 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/09 12:22:20 by onevil_x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/cub3d.h"

//========================================== DEBUG ==========================================================
void	print_cubed_elements(t_cubed *cubed)
{
	printf("North Texture Path (NO): %s\n", cubed->no_path ? cubed->no_path : "Not set");
	printf("South Texture Path (SO): %s\n", cubed->so_path ? cubed->so_path : "Not set");
	printf("West  Texture Path (WE): %s\n", cubed->we_path ? cubed->we_path : "Not set");
	printf("East  Texture Path (EA): %s\n", cubed->ea_path ? cubed->ea_path : "Not set");

	printf("Floor Color (F): #%06X\n", cubed->floor_rgb);
	printf("Ceiling Color (C): #%06X\n", cubed->ceiling_rgb);

	printf("Map Path: %s\n", cubed->map_path ? cubed->map_path : "Not set");
	if (cubed->map)
	{
		int i = 0;
		printf("Map:\n");
		while (cubed->map[i])
		{
			printf("%s\n", cubed->map[i]);
			i++;
		}
	}
	else
		printf("Map: Not set\n");
}
//========================================== DEBUG ==========================================================

static void	init_cubed(t_cubed *cubed)
{
	cubed->no_path = NULL;
	cubed->so_path = NULL;
	cubed->we_path = NULL;
	cubed->ea_path = NULL;
	cubed->floor_rgb = -1;
	cubed->ceiling_rgb = -1;
	cubed->c_set = 0;
	cubed->f_set = 0;
	cubed->map = NULL;
	cubed->map_path = NULL;
	cubed->map_fd = -1;
}

int	main(int ac, char **av)
{
	t_cubed		cubed;
	t_player	player;
	mlx_t		*mlx;
	t_game		game;
	mlx_image_t	*img;

	init_cubed(&cubed);
	if (ac != 2)
	{
		ft_putstr_fd("Error: wrong format\n", 2);
		return (1);
	}
	cubed.map_path = av[1];
	if (parsing(&cubed) == 1)
		return (free_cubed(&cubed), 1);
	print_cubed_elements(&cubed);
	init_player(&player, cubed.map);
	mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!mlx)
		return (printf("Error initializing MLX\n"), 1);
	mlx_set_cursor_mode(mlx, MLX_MOUSE_DISABLED);
	if (!load_textures(&cubed))
	{
		free_textures(&cubed);
		//more checks
		exit(1);
	}
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (printf("Error creating image\n"), 1);
	init_game(&game, &cubed, &player);
	init_game_img(&game, img, mlx);
	// draw_minimap(img, &cubed, &player);
	render_3d_view(img, &player, &cubed);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, game_loop, &game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	// free_cubed(&cubed);
	return (0);
}
