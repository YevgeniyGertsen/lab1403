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

//Создаем указатель на функцию
void(*pt)(int *, int) = NULL;

void main4()
{
	int * p = testRef();

	printf("%d \n", *p);

	return;
	int mas[10] = {0};

	//Заполнение массива
	FillArr(mas, 10);

	//Выведем на экран
	PrintArr(mas, 10);
	
	//Присвоеить значение на указатель
	pt = sorU;

	//Сортировка
	sort(mas, 10, pt);

	printf("\n-----------\n");
	//Выведем на экран
	PrintArr(mas, 10);



	pt = sorD;
	//Сортировка
	sort(mas, 10, pt);

	printf("\n-----------\n");
	//Выведем на экран
	PrintArr(mas, 10);
}