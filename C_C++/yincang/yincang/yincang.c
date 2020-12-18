//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	FILE* p , *h;
//	if ((h=fopen_s(&p ,"D:/number1/text.txt", "w+"))!=NULL) {
//		printf("Success");
//		fprintf(h, "hello");
//		fclose(h);
//	}
//	else printf("Error");
//	
//		
//}

#include<stdio.h>
#include<string.h>

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
int main() {

	char s[10] = { 0 };
	strcpy_s(s,5, "abcd");
	int i = 0;
	printf("%d", i);
	//putchar(TOUPPER(s[++i]));
	('a' <= (s[++i]) && (s[++i]) <= 'z' ? (s[++i])-'a' + 'A' : (s[++i]));

	printf("%d", i);
	return 0;
}