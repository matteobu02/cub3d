/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/27 19:27:25 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*init_map_struct(void)
{
	t_map	*ret;

	ret = (t_map *)malloc(sizeof(t_map));
	if (!ret)
		close_program(MALLOC_ERROR, NULL);
	ret->map = NULL;
	ret->no = NULL;
	ret->so = NULL;
	ret->we = NULL;
	ret->ea = NULL;
	ret->c = -1;
	ret->f = -1;
	ret->start_posx = -1;
	ret->start_posy = -1;
	ret->width = 0;
	return (ret);
}

void	init_images(t_data *data, t_main *main)
{
	data->north.img = mlx_xpm_file_to_image(data->mlx, main->map->no,
			&data->north.width, &data->north.height);
	if (!data->north.img)
		end(data, INVALID_TEXTURE_ERROR);
	data->north.addr = mlx_get_data_addr(data->north.img, &data->north.bpp,
			&data->north.lb, &data->north.endian);
	data->south.img = mlx_xpm_file_to_image(data->mlx, main->map->so,
			&data->south.width, &data->south.height);
	if (!data->south.img)
		end(data, INVALID_TEXTURE_ERROR);
	data->south.addr = mlx_get_data_addr(data->south.img, &data->south.bpp,
			&data->south.lb, &data->south.endian);
	data->west.img = mlx_xpm_file_to_image(data->mlx, main->map->we,
			&data->west.width, &data->west.height);
	if (!data->west.img)
		end(data, INVALID_TEXTURE_ERROR);
	data->west.addr = mlx_get_data_addr(data->west.img, &data->west.bpp,
			&data->west.lb, &data->west.endian);
	data->east.img = mlx_xpm_file_to_image(data->mlx, main->map->ea,
			&data->east.width, &data->east.height);
	if (!data->east.img)
		end(data, INVALID_TEXTURE_ERROR);
	data->east.addr = mlx_get_data_addr(data->east.img, &data->east.bpp,
			&data->east.lb, &data->east.endian);
}

void	init_value(t_data *data, t_main *main)
{	
	data->mlx = mlx_init();
	if (!data->mlx)
		close_program(MLX_ERROR, main);
	init_images(data, main);
	data->width = main->map->width;
	data->height = main->map->height;
	data->map = main->map->map;
	onedirection(data, main);
	data->px = (float)main->map->start_posx + 0.5;
	data->py = (float)main->map->start_posy + 0.5;
	data->pdx = cos(degtorad(data->pa));
	data->pdy = -sin(degtorad(data->pa));
	data->map_data = main->map;
	data->main = main;
	data->win = mlx_new_window(data->mlx, W, H, "cub3D");
	if (!data->win)
		close_program(MLX_ERROR, main);
	data->img = mlx_new_image(data->mlx, W, H);
	if (!data->img)
		end(data, MLX_ERROR);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_bytes, &data->endian);
	if (!data->addr)
		end(data, MLX_ERROR);
}

void	parser(int ac, char *path, t_main *data)
{
	if (ac != 2)
		close_program(ARG_NUM_ERROR, NULL);
	data->map = init_map_struct();
	basic_check_arg(path, data);
	get_map_info(path, data);
	deep_check_info(data->raw_map, data);
	find_map(data);
	data->map->height = 0;
	convert_map(data);
	data->raw_map = ft_free_tab((void **)data->raw_map);
	check_map(data, data->map->map, data->map->width);
	if (data->map->start_posx == -1)
		close_program(NO_SPAWN_ERROR, data);
	check_map_closed(data->map->map, data);
	return ;
}

int	main(int ac, char **av)
{
	t_main	main;
	t_data	data;

	parser(ac, av[1], &main);
	init_value(&data, &main);
	mlx_hook(data.win, 2, 0, key_hook_press, &data);
	mlx_hook(data.win, 3, 0, key_hook_release, &data);
	mlx_hook(data.win, 17, 0, end, &data);
	mlx_loop_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
