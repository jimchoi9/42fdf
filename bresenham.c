#include <stdio.h>

void bresenham(int x1, int y1, int x2, int y2)
{
	int addx, addy;
	int count;

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

	if (dx >= dy)
    {
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

		}
    }
	//dx < dy 일 경우 (기울기 > 1) x의 조건이 만족하면 y를 1 증가시킨다
    else
    {
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
		}
    }
}



int main()
{
	bresenham(0,0,10,20);
}