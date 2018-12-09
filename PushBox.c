#include"PushBox.h"

/*******************
          目录
地图数组        （三维）
打印地图        （根据地图数组打印）
获取空箱子个数  （判断是否通关）
输入指令        （玩家输入移动指令）
上
下
左
右
********************/


//地图对应的数组		//0:空地（空格）  1：墙▒▒   2：箱子□   3：目的地☆  4：人♀//
int Map[3][7][8] = {		  
	{
		0,0,1,1,1,0,0,0,
		0,0,1,3,1,0,0,0,
		1,1,1,2,1,1,1,1,
		1,3,2,4,2,0,3,1,
		1,1,1,2,1,1,1,1,
		0,0,1,3,1,0,0,0,
		0,0,1,1,1,0,0,0
	},
	{
		1,1,1,1,1,1,1,1,
		1,0,0,3,1,0,4,1,
		1,0,1,0,2,0,0,1,
		1,0,2,3,1,2,0,1,
		1,1,0,3,0,0,0,1,
		0,1,0,0,1,1,1,1,
		0,1,1,1,1,0,0,0
	},
	{
		0,1,1,1,1,1,1,0,
		0,1,0,0,0,0,1,1,
		1,1,3,1,1,0,0,1,
		1,0,3,3,2,0,0,1,
		1,0,2,1,2,4,0,1,
		1,0,0,0,0,1,1,1,
		1,1,1,1,1,1,0,0
	}
};



//打印地图
void DrawMap()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (Map[cas][i][j])
			{
			case 0:
				printf("  ");//空地
				break;
			case 1:
				printf("■");//墙
				break;
			case 2:
				printf("□");//箱子
				break;
			case 3:
				printf("☆");//目的地
				break;
			case 4:
				printf("♀");//人
				break;
			case 5:
				printf("√");//箱子与目的地重合
				break;
			case 7:
				printf("♀");//人与目的地重合
				break;
			}
		}
		printf("\n");
	}
}


//获取玩家位置
POINT GetPlayerPosition()
{
	POINT pos = { -1,-1 };//未找到玩家位置情况

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Map[cas][i][j] == 4||Map[cas][i][j]==7)
			{
				pos.x = i;
				pos.y = j;
				return pos;
			}
		}
	}

	return pos;
}


//获取空箱子个数
int GetSpareBox()
{
	int Count = 0;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Map[cas][i][j] ==2);
			Count++;
		}
	}
	return Count;
}


//输入指令
void Import()
{
	char Input;//输入字符
	Input = _getch();//玩家输入

	switch (Input)
	{
	case'W'://上
		Up();
		break;
	case'S'://下
		Down();
		break;
	case'A'://左
		Left();
		break;
	case'D'://右
		Right();
		break;
	}
}


//上
void Up()
{
	POINT pos = GetPlayerPosition();//获取玩家坐标
	if (Map[cas][pos.x - 1][pos.y] == 0 || Map[cas][pos.x - 1][pos.y] == 3)//移动前方为空地或目的地
	{
		Map[cas][pos.x - 1][pos.y] += 4;
		Map[cas][pos.x][pos.y] -= 4;
	}
	else if (Map[cas][pos.x - 1][pos.y] == 2 || Map[cas][pos.x - 1][pos.y] == 5)//移动前方为箱子
	{
		if (Map[cas][pos.x - 2][pos.y] == 0 || Map[cas][pos.x - 2][pos.y] == 3)//箱子可移
		{
			Map[cas][pos.x - 2][pos.y] += 2;
			Map[cas][pos.x - 1][pos.y] += 2;
			Map[cas][pos.x][pos.y] -= 4;
		}
	}
}


//下
void Down()
{
	POINT pos = GetPlayerPosition();
	if (Map[cas][pos.x + 1][pos.y] == 0 || Map[cas][pos.x + 1][pos.y] == 3)
	{
		Map[cas][pos.x + 1][pos.y] += 4;
		Map[cas][pos.x][pos.y] -= 4;
	}
	else if (Map[cas][pos.x + 1][pos.y] == 2 || Map[cas][pos.x + 1][pos.y] == 5)
	{
		if (Map[cas][pos.x + 2][pos.y] == 0 || Map[cas][pos.x + 2][pos.y] == 3)
		{
			Map[cas][pos.x + 2][pos.y] += 2;
			Map[cas][pos.x + 1][pos.y] += 2;
			Map[cas][pos.x][pos.y] -= 4;
		}
	}
}


//左
void Left()
{
	POINT pos = GetPlayerPosition();
	if (Map[cas][pos.x][pos.y - 1] == 0 || Map[cas][pos.x][pos.y - 1] == 3)
	{
		Map[cas][pos.x][pos.y - 1] += 4;
		Map[cas][pos.x][pos.y] -= 4;
	}
	else if (Map[cas][pos.x][pos.y - 1] == 2 || Map[cas][pos.x][pos.y - 1] == 5)
	{
		if (Map[cas][pos.x][pos.y - 2] == 0 || Map[cas][pos.x][pos.y - 2] == 3)
		{
			Map[cas][pos.x][pos.y - 2] += 2;
			Map[cas][pos.x][pos.y - 1] += 2;
			Map[cas][pos.x][pos.y] -= 4;
		}
	}
}


//右
void Right()
{
	POINT pos = GetPlayerPosition();
	if (Map[cas][pos.x][pos.y + 1] == 0 || Map[cas][pos.x][pos.y + 1] == 3)
	{
		Map[cas][pos.x][pos.y + 1] += 4;
		Map[cas][pos.x][pos.y] -= 4;
	}
	else if (Map[cas][pos.x][pos.y + 1] == 2 || Map[cas][pos.x][pos.y + 1] == 5)
	{
		if (Map[cas][pos.x][pos.y + 2] == 0 || Map[cas][pos.x][pos.y + 2] == 3)
		{
			Map[cas][pos.x][pos.y + 2] += 2;
			Map[cas][pos.x][pos.y + 1] += 2;
			Map[cas][pos.x][pos.y] -= 4;
		}
	}
}
