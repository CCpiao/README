#include"PushBox.h"



int main()
{
	cas = 0;
	while (1)
	{
		DrawMap();//打印地图
		Import();//输入上下左右并移动
		system("cls");//清屏
		//箱子推完过关
		if (GetSpareBox() == 0)
		{
			printf("本关胜利！");
			cas++;
			//全部关卡完成
			if (cas == 3)
			{
				printf("\n您已全部通关！");
				break;
			}
		}		
	}

	return 0;
}