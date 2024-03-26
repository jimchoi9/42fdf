/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:21:49 by jimchoi           #+#    #+#             */
/*   Updated: 2024/03/26 19:52:39 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int is_valid_map(char *argv[], int fd, t_map *map)
{
	char *line = "test";
	char **str;
	int x_len = -1;
	int y_len = 0;
	int i = 0;
	int check = 0;

	while (1)
	{
		line = get_next_line(fd);
		if(line == 0)
			break;
		x_len = -1;
		str = ft_split(line, ' ');
		while (str[++x_len] != NULL)
				free(str[x_len]);
		if (check != x_len && check != 0)
			exit(1);
		check = x_len;
		y_len++;
		free(line);
		free(str);
	}
	map->height = y_len;
	map->width = x_len;
	printf("x = %d y = %d\n", x_len, y_len);
	close(fd);
	return (1);
}


t_map	*parsing(char *argv[])
{
	// atexit(check_leaks);
	char *line = "test";
	char **str;
	int i = 0;
	int fd = open(argv[1], O_RDONLY);
	t_map *map=malloc(sizeof(t_map));
	is_valid_map(argv,fd, map);
	map->points=(t_point **)malloc(sizeof(t_point *) * map->height);
	for(i=0;i<map->height;i++)
	    map->points[i]=(t_point *)malloc(sizeof(t_point) * map->width);
	fd = open(argv[1], O_RDONLY);
	map->max_z = 0;

	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		int j = 0;
		str = ft_split(line, ' ');
		while(j < map->width)
		{
			map->points[i][j].x =j ;
			map->points[i][j].y= i;
			map->points[i][j].z= ft_atoi(str[j]);
			if (map->points[i][j].z > map->max_z || map->points[i][j].z * -1 > map->max_z)
				map->max_z = map->points[i][j].z;
			j++;
		
		}
		i++;
	}

	return (map);
}
