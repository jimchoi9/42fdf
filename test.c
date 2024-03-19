#include <unistd.h>
#include "./minilibx_mms_20210621/mlx.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

#include <stdio.h>

//이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	parsing();
int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;

	printf("Loading\n");

	parsing();

	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hellow World!");
	// image.img = mlx_new_image(mlx_ptr, 500, 500); // 이미지 객체 생성
	// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	// 		double x = 0;
	// 		double y = 0;
	// 		double theta = 3.14 / 4.0;
	// for (int i = 0 ; i <= 200 ; i++)
	// {
			
	// 	for (int j = 0 ; j <= 200 ; j++)
	// 	{
	// 		// mlx_pixel_put (mlx_ptr, win_ptr, 5, 5, 0x00FFFFFF);
	// 		if (i % 20 == 0 || j % 20 == 0)
	// 		{
	// 		my_mlx_pixel_put(&image, x + j + 100, y + i + 100,  0x00FF00 * i);
	// 		my_mlx_pixel_put(&image, ((x + j)* cos(theta) - (y+i) * sin(theta))+ 200, ((x+j)*sin(theta)+(y+i)*cos(theta)),  0x00FF00* i);
	// 		}
	// 	}	
	// }
	// mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);
	// mlx_loop(mlx_ptr);
	// return (0);
}
void check_leaks(void) 
{ system("leaks test1"); } 
void	parsing()
{
	// atexit(check_leaks);
	char *line = "test";
	char **str;
	
	int x_len = 0;
	int y_len = 0;
	int i = 0;

	int fd = open("./test_maps/elem-col.fdf", O_RDONLY);

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


				// printf("%c  ", str[0]);
				// printf("%s  ", str[0]);

	// free(str);
	// }
	return;
}