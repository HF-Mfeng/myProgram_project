#include<iostream>
using namespace std;

int main()
{
	int a , b ;
	int c ;
	cin >> a >> b ;
	if(a>b){
		c = a - b ;
	}else
	{
		c = b - a ;
	}
	
	cout << c << endl ;

	cout << "请按任意键结束" << endl ;
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}