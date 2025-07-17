/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:15:39 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/17 18:28:48 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/cub3d.h"

static void	init_cubed(t_cubed *cubed)
{
	cubed->no_path = NULL;
	cubed->so_path = NULL;
	cubed->we_path = NULL;
	cubed->ea_path = NULL;
	cubed->door_path = NULL;
	cubed->op_door = false;
	cubed->floor_rgb = -1;
	cubed->ceiling_rgb = -1;
	cubed->map = NULL;
	cubed->map_path = NULL;
	cubed->map_fd = -1;
}

static int	handle_parsing(t_cubed *cubed, int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error: wrong format\n", 2);
		return (1);
	}
	cubed->map_path = av[1];
	if (parsing(cubed) == 1)
	{
		free_cubed(cubed);
		return (1);
	}
	return (0);
}

static int	handle_mlx_and_textures(t_cubed *cubed, mlx_t **mlx)
{
	*mlx = mlx_init(WIDTH, HEIGHT, "Cub3D_bonus", false);
	if (!*mlx)
	{
		ft_putstr_fd("Error initializing MLX\n", 2);
		return (1);
	}
	mlx_set_cursor_mode(*mlx, MLX_MOUSE_DISABLED);
	if (!load_textures(cubed))
	{
		free_textures(cubed);
		free_cubed(cubed);
		return (1);
	}
	return (0);
}

static int	start_game(mlx_t *mlx, t_cubed *cubed, t_player *player)
{
	t_game		game;
	mlx_image_t	*img;

	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		ft_putstr_fd("Error creating image\n", 2);
		return (1);
	}
	init_game(&game, cubed, player);
	init_game_img(&game, img, mlx);
	render_3d_view(img, player, cubed);
	mlx_loop_hook(mlx, game_loop, &game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_cubed		cubed;
	t_player	player;
	mlx_t		*mlx;

	init_cubed(&cubed);
	if (handle_parsing(&cubed, ac, av))
		return (1);
	init_player(&player, cubed.map);
	if (handle_mlx_and_textures(&cubed, &mlx))
		return (1);
	if (start_game(mlx, &cubed, &player))
		return (1);
	free_textures(&cubed);
	free_cubed(&cubed);
	return (0);
}
