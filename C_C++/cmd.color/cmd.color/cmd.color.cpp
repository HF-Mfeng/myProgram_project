#include<Windows.h>
#include<string.h>
#include<time.h>
#include<stdio.h>
int main()
{
	char color[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	char p[10] = "COLOR   ";
	srand(time(NULL));
	for (int i = 0; i < 16; i )
	{
		int j = rand() % 16 + 0;
		p[6] = color[j];
		p[7] = color[16 - j];
		system(p);
		system("cls");
		printf("\n\n\t\t\t我\n\n\t\t\t爱\n\n\t\t\t你");
		Sleep(100*(rand()%5+1));
	}
	return 0;
}