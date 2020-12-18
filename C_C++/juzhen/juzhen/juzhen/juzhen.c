#include<stdio.h>
#include<windows.h>


void add(double *matrix1,double *matrix2,double *matrix,int col,int row) {
	int m;
	for ( m = 0; m < col*row; m++)
	{
		matrix[m] = matrix1[m] + matrix2[m];
	}
	return;
}

void minus(double* matrix1, double* matrix2, double* matrix, int col, int row) {
	int m;
	for (m = 0; m < col * row; m++)
	{
		matrix[m] = matrix1[m] - matrix2[m];
	}
	return;
}

void inputMatrix(double* matrix1, double* matrix2, int *col, int *row) {
	int i;
	printf("请输入矩阵的行列：");
	scanf_s("%d%d", row, col);
	for (i = 0;i < (*row) * (*col);i++) {
		printf("请输入矩阵1的 行：%d，列：%d的值:", i / (*col), i % (*col));
		scanf_s("%lf", matrix1+i);
	}
	putchar('\n');
	for (i = 0;i < (*row) * (*col);i++) {
		printf("请输入矩阵2的 行：%d，列：%d的值:", i / (*col), i % (*col));
		scanf_s("%lf", matrix2 + i);
	}
	return;
}
void inputMatrix1(double* matrix1, int* col, int* row) {
	int i;
	printf("请输入矩阵的行列：");
	scanf_s("%d%d", row, col);
	for (i = 0;i < (*row) * (*col);i++) {
		printf("请输入矩阵1的 行：%d，列：%d的值:", i / (*col), i % (*col));
		scanf_s("%lf", matrix1 + i);
	}
	return;
}

void zhuan(double* matrix1, double* matrix, int col, int row) {
	int i ;
	for ( i = 0; i < col*row; i++)
	{
		matrix[(i % col)*col+ (i / col)] = matrix1[i];
	}
}
void output(double* matrix,int col ,int row) {
	int i, j;
	printf("\n\n\n\n答案为:\n");
	for (i = 0;i < row;i++) {
		for ( j = 0; j < col; j++){
			printf("%.2f", matrix[i * col + j]);
		}
		printf("\n");
	}
}
int main(){
	int select;
	double matrix1[100] = {0}, matrix2[100] = {0}, matrix[100] = {0};
	int col, row;
	printf("功能如下:\n");
	printf("矩阵相加 1\n");
	printf("矩阵相减 2\n");
	printf(" 矩阵的转置 3\n");
	printf("结束 0\n");
	printf("请选定您需要的操作:\n");
	scanf_s("%d", &select);
	switch (select)
	{
	case 1:
		inputMatrix(matrix1, matrix2, &col, &row);
		add(matrix1, matrix2, matrix, col, row);
		break;
	case 2:
		inputMatrix(matrix1, matrix2, &col, &row);
		minus(matrix1, matrix2, matrix, col, row);
		break;
	case 3:
		inputMatrix1(matrix1, &col, &row);
		zhuan(matrix1, matrix, col, row);
	default:
		printf("输入有误！");
		break;
	}
	output(matrix, col, row);

	system("pause");
	return 0;
}