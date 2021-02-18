#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//猜数字游戏
//1.电脑会生成一个随机数
//2.猜数字
void menu()
{
	printf("*****************************\n");
	printf("****  1. play   0. exit  ****\n");
	printf("*****************************\n");
}

//RAND_MAX - 32676

void game()
{
	//1.生成一个随机数
	int ret = 0;
	int guess = 0;
	//拿时间戳来设置随机数的生成起始点
	//time_t time(time_t *timer)

	//srand((unsigned int)time(NULL));//需要一个总在变化的值；可以建立一个时间戳
	                            //时间戳：当前计算机的时间-计算机的起始时间（1970.1.1.0:0:0）=（xxxx）秒
	ret = rand()%100+1;//生成1-100之间随机数
	//printf("%d\n", ret);
	//2.猜数字
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
	printf("猜数字\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//srand生成数的起点只要在代码中设置一次就可以，不需要重复设置，频繁调用
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game(); //猜数字游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);

	return 0;
}