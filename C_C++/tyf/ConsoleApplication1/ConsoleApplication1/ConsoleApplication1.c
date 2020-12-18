#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define OK 1;
typedef int Status;
typedef int Element;
typedef struct PNode
{
	int coef;
	int exp;
	struct PNode* link;
}PNode;
typedef struct
{
	struct PNode* head;
}polynominal;
void Creat(polynominal* p) {
	p->head = (PNode*)malloc(sizeof(PNode));
	p->head->exp = -1;
	p->head->link = NULL;
	PNode* pn, * pre;
	PNode* q;
	for (;;) {
		pn = (PNode*)malloc(sizeof(PNode));
		printf("coef:");//输入为系数
		scanf_s("%d", &pn->coef);;
		printf("exp:");//输入为指数
		scanf_s("%d", &pn->exp);
		fflush(stdin);
		if (pn->exp < 0) //如果输入的为负数，则退出
		{
			free(pn);
			break;
		}
		pre = p->head;
		q = p->head->link;
		while (q && q->exp > pn->exp) {
			pre = q;
			q = q->link;
		}
		pn->link = q;
		pre->link = pn;
	}
}
//多项式的加法运算
Status Add(polynominal* px, polynominal* qx) {//结果保存在qx中
	PNode* p = px->head->link;
	PNode* q, * q1;
	PNode* temp;
	q1 = qx->head;
	q = q1->link; //q1一直在q的前面
	if (!q)
	{
		qx = px;
	}
	while (p && q) {
		printf("进来了\n");
		while (p->exp < q->exp) {
			q1 = q;
			q = q->link;
		}
		if (p->exp == q->exp)
		{
			q->coef = q->coef + p->coef;
			if (q->coef == 0)
			{
				q1->link = q->link;
				free(q);//释放q空间
				q = q1->link; //重置一下q
				p = p->link; //p前进
			}
			else {
				q1 = q;
				p = p->link;
				q = q->link;
			}
		}
		else {
			temp = (PNode*)malloc(sizeof(PNode));
			temp->coef = p->coef;
			temp->exp = p->exp;
			temp->link = q1->link;
			q1->link = temp;
			p = p->link;
		}
	}
	return OK;
}

//多项式的乘法操作：
polynominal* multOperation(polynominal* p, polynominal* q) {
	polynominal* result = (polynominal*)malloc(sizeof(polynominal));//开辟空间存放结果
	result->head->coef = -1;
	result->head->link = NULL;
	PNode* p1 = p->head->link;
	PNode* q1 = q->head->link;
	while (p1) {//用p1的各项与p2相乘
		PNode* temp = (PNode*)malloc(sizeof(PNode));
		polynominal* polyTest = (polynominal*)malloc(sizeof(polynominal));
		while (q1) {
			temp->coef = p1->coef * q1->coef;
			temp->exp = p1->exp * q1->exp;
			polyTest->head->link = temp;
			//查找是否重合然后相加
			Add(polyTest, result);
			q1 = q1->link;
		}

		p1 = p1->link;
	}\
	return result;
}
//多项式的输出操作
Status Output(polynominal* p) {
	PNode* temp = p->head;
	while (temp->link != NULL) {
		temp = temp->link;
		printf("%d", temp->coef);
		printf("^%d", temp->exp);
		printf("+");
	}

	return OK;
}
//多项式的撤销操作
Status destory(polynominal* p) {
	PNode* temp;
	while (p->head) {
		temp = p->head->link;
		free(p->head);
		p->head = temp;
	}
	//free(temp);
	return OK;
}
int main() {
	system("chcp 65001");//将CMD窗口编码格式变为UTF-8编码格式
	polynominal* testOne = (polynominal*)malloc(sizeof(polynominal));
	polynominal* testTwo = (polynominal*)malloc(sizeof(polynominal));
	printf("请依次输入多项式一的系数和指数\n");
	Creat(testOne);
	Output(testOne);
	printf("请依次输入多项式二的系数和指数\n");
	Creat(testTwo);
	Output(testTwo);
	Add(testOne, testTwo);
	printf("加法结果为：\n");
	Output(testTwo);
	polynominal* result = multOperation(testOne, testTwo);
	printf("乘法结果为：\n");
	Output(result);
	destory(testOne);
	destory(testTwo);
	destory(result);
	return 0;
}
