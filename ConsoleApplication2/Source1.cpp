#include<stdio.h>
#include<locale.h>
#include"Header.h"
#include <iostream>
using namespace std;


//ACx025145
int sum(int a, int b)
{
	return a + b;
}

void FillArr(int *mas, int len)
{
	for (int i = 0; i < len; i++)
		*(mas + i) = 0 + rand() % 10;
}

void PrintArr(int *mas, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d \t",*(mas + i));

	printf("\n");
}

//������� ��������� �� �������
void(*pt)(int *, int) = NULL;

void main4()
{
	int * p = testRef();

	printf("%d \n", *p);

	return;
	int mas[10] = {0};

	//���������� �������
	FillArr(mas, 10);

	//������� �� �����
	PrintArr(mas, 10);
	
	//���������� �������� �� ���������
	pt = sorU;

	//����������
	sort(mas, 10, pt);

	printf("\n-----------\n");
	//������� �� �����
	PrintArr(mas, 10);



	pt = sorD;
	//����������
	sort(mas, 10, pt);

	printf("\n-----------\n");
	//������� �� �����
	PrintArr(mas, 10);
}