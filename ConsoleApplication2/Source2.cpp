#include<stdio.h>
#include<locale.h>
#include"Header1.h"
#include <iostream>
char f;
void main2()
{
	setlocale(LC_ALL, "RUS");
	do
	{
		int N;
		scanf("%d", &N);
		switch (N)
		{

		case 1:
		{
			/*12.	int * pc; создает указатель pc и int c; создает нормальную переменную c.
			Поскольку pc и c оба не инициализированы, указатель pc указывает на отсутствие адреса или случайного адреса.
			Аналогично, переменной c присваивается адрес, но он содержит случайное / мусорное значение.*/
			int *pc;
			int c;
			printf("с=%d и pc=p ", c);
		}
		break;
		case 2:
		{
			/*Функция находит в строке пары инвертированных фрагментов
			(например "123apr" и "rpa321") и возвращает указатель на
			первый. С помощью функции найти все пары.*/
			char stroka[40] = "123apr 12 12 rpa321 21";
			char massiv[5][10];
			for (int i = 0;i < 5;i++)
			{
				for (int j = 0;j < 10;j++)
					massiv[i][j] = '\0';
			}


			char(*pt)[10] = massiv;
			Poisk(stroka, massiv[0], 40);

			for (int i = 0;i < 5;i++)
			{
				for (int j = 0;j < 10;j++)
					printf("%c\t", massiv[i][j]);
				printf("\n");
			}

			char mass3[10];
			int j = 0;
			for (int i = 9;i >= 0;i--)
			{
				//for(int j=0;j)
				
				mass3[j] = massiv[0][i];
				j++;
			}
			printf("%s", mass3);
			int y = 0;

		}
		}

		scanf("%c", &f);
	} while (f == 'y');
}