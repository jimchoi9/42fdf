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
void bresenham(int x1, int y1, int x2, int y2, t_data image);
int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;

	printf("Loading\n");

	// parsing();

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 500, 500); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
			double x = 0;
			double y = 0;
			double theta = 3.14 / 4.0;
	bresenham(0 , 0, 100, 200, image);
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
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
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

void bresenham(int x1, int y1, int x2, int y2, t_data image)
{
	int addx, addy;
	int count = 0;

	int dx = x2 - x1;
	int dy = y2 - y1;


	//음수방향
	if (dx < 0)
    {
        dx = -dx;
        addx = -1;
    }
    else
    {
        addx = 1;
    }
	if (dy < 0)
	{
		dy = -dy;
        addy = -1;
	}
	else{
		addy = 1;
	}

	int x = x1;
	int y = y1;
	// printf("x: %d, y: %d\n", x, y);
	if (dx >= dy)
    {
		printf("xxxx");
		for(int i = 0; i < dx; i++)
		{
			//x를 1증가 시키고 dy만큼 count 증가
			x += addx;
			//x의 증가만큼 count 증가
			count += dy;

			//증가하는 y값보다 크다면 
			if(count >= dx)
			{
				//y 를 1 증가시키고 count를 초기화
				y += addy;
                count -= dx;
			}
			printf("x = %d, y = %d\n", x, y);
			my_mlx_pixel_put(&image,x, y ,  0x00FF00 );


		}
    }
	//dx < dy 일 경우 (기울기 > 1) x의 조건이 만족하면 y를 1 증가시킨다
    else
    {
		printf("yyyy");
        for(int i=0; i<dy; i++)
		{
			
			//y를 1증가 시키고 dx만큼 count 증가
            y += addy;
            //y의 증가만큼 count 증가
            count += dx;

            //증가하는 x값보다 크다면 
            if(count >= dy)
            {
                //x 를 1 증가시키고 count를 초기화
                x += addx;
                count -= dy;
            }
            printf("x = %d, y = %d\n", x,y);
			my_mlx_pixel_put(&image,x, y ,  0x00FF00 );
		}
    }
}
