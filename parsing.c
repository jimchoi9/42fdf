/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:21:49 by jimchoi           #+#    #+#             */
/*   Updated: 2024/03/20 21:32:06 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

typedef struct s_idx
{
	int x;
	int y;
	int z;
	char *color;
}		t_idx;


void	parsing(char *argv[])
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

	t_idx map[y_len][x_len];
	fd = open(argv[1], O_RDONLY);


	i = 0;
	while (i < y_len)
	{
		line = get_next_line(fd);
		int j = 0;
		str = ft_split(line, ' ');
		while(j < x_len)
		{

			map[i][j].x = j;
			map[i][j].y = i;
			map[i][j].z = ft_atoi(str[j]);
			j++;
		
		}
		i++;
	}
	for(int i = 0; i < y_len; i++)
	{
		for(int j = 0; j < x_len; j++)
		{
            printf("%d ", map[i][j].z);
        }
		printf("\n");
	}


				// printf("%c  ", str[0]);
				// printf("%s  ", str[0]);

	// free(str);
	// }
	return;
}