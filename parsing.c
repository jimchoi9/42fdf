/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:21:49 by jimchoi           #+#    #+#             */
/*   Updated: 2024/03/21 18:40:49 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

t_map	*parsing(char *argv[])
{
	// atexit(check_leaks);
	char *line = "test";
	char **str;
	
	int x_len = 0;
	int y_len = 0;
	int i = 0;

	int fd = open(argv[1], O_RDONLY);

	while (1)
	{
		line = get_next_line(fd);
		if(line == 0)
			break;
		x_len = 0;

		str = ft_split(line, ' ');
		while (str[x_len] != NULL)
			{
				printf("%s  ", str[x_len]);
				free(str[x_len]);
				x_len++;
			}
		y_len++;
	free(line);
	free(str);
	}
	printf("x = %d y = %d\n", x_len, y_len);

	close(fd);

	t_map *map=malloc(sizeof(t_map));
	map->width=x_len;
	map->height=y_len;
	map->points=(t_point **)malloc(sizeof(t_point *) * map->height);
	for(i=0;i<map->height;i++)
	    map->points[i]=(t_point *)malloc(sizeof(t_point) * map->width);
	fd = open(argv[1], O_RDONLY);


	i = 0;
	while (i < y_len)
	{
		line = get_next_line(fd);
		int j = 0;
		str = ft_split(line, ' ');
		while(j < x_len)
		{

			map->points[i][j].x =j ;
			map->points[i][j].y= i;
			map->points[i][j].z= ft_atoi(str[j]);
			j++;
		
		}
		i++;
	}
	for(int i = 0; i < y_len; i++)
	{
		for(int j = 0; j < x_len; j++)
		{
            printf("%d ", map->points[i][j].z);
        }
		printf("\n");
	}

	return (map);
}