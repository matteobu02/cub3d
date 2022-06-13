/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:27:24 by mbucci            #+#    #+#             */
/*   Updated: 2022/06/14 01:29:22 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define MINLEN_ARG				5
# define ARG_NUM_ERROR			"Error\nNeed exactly one '.cub' parameter"
# define INVALID_ARG_ERROR		"Error\nArgument does not have '.cub' extension"
# define FILE_ERROR				"Error\nFile can't be opened or doesn't exist"
# define FILE_EMPTY_ERROR		"Error\nFile empty"
# define MALLOC_ERROR 			"Error\nMalloc failed"
# define INVALID_DATA_ERROR 	"Error\nInvalid data"
# define INVALID_RGB_ERROR 		"Error\nInvalid RGB data"
# define DUPLICATED_ENTRY_ERROR "Error\nMultiple entries for same identifier"
# define MISSING_DATA_ERROR		"Error\nMissing or invalid data in file"
# define AFTER_PATH_ERROR		"Error\nInvalid data after path"
# define NO_SPACE_ENTRY_ERROR	"Error\nNeed at least one space after identifier"
# define IDENTIFIER_PATH_ERROR	"Error\nInvalid data between identifier and path"
# define INVALID_MAP_ERROR		"Error\nInvalid map"
# define MULTIPLE_SPAWN_ERROR	"Error\nMultiple spawn locations found"
# define SPAWN_ERROR			"Error\nInvalid spawn location"
# define NO_SPAWN_ERROR			"Error\nNo spawn found"
# define MAP_OPEN_ERROR			"Error\nMap is not closed"

typedef struct s_map
{
	int		height;
	int		width;
	int		**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	int		start_posx;
	int		start_posy;
	char	orientation;
}	t_map;

typedef struct s_main
{
	t_map	*map;
	char	**raw_map;
}	t_main;

/** GET_FILE_INFO.C **/
void	basic_check_arg(char const *path, t_main *data);
void	get_map_info(char const *path, t_main *data);
char	*retrieve_info(char **tab, char const *target, t_main *data);
void	get_info(t_main *data);

/** CHECK_FILE_INFO.C  **/
int		check_line(char const *str, int c);
void	deep_check_info(char **tab, t_main *data);

/** PARSING_MAP.C  **/
void	find_map(t_main *data);
void	check_map(t_main *data, char **tab);
void	convert_map(t_main *data);
void	check_map_closed(int **tab, t_main *data);

/** PARSING_UTILS.C  **/
char	*skip_spaces(char const *str, char const *target);
int		get_map_width(char **tab);
void	fill_with_space(int *tab, int size);
void	skip_empty_lines(t_main *data, int *index);

/** FREE.C  **/
void	close_program(char const *msg, t_main *ptr);
void	*free_map(t_map *ptr);

#endif
