#include"PushBox.h"



int main()
{
	cas = 0;
	while (1)
	{
		DrawMap();//��ӡ��ͼ
		Import();//�����������Ҳ��ƶ�
		system("cls");//����
		//�����������
		if (GetSpareBox() == 0)
		{
			printf("����ʤ����");
			cas++;
			//ȫ���ؿ����
			if (cas == 3)
			{
				printf("\n����ȫ��ͨ�أ�");
				break;
			}
		}		
	}

	return 0;
}