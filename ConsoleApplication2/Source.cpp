#include<iostream>
#include<locale.h>
#include"Header.h"
#include<time.h>
#include<stdio.h>

using namespace std;



void main()
{

	//char * pt = NULL;
	//pt = (char*)malloc(8 * sizeof(char));
	//strcpy(pt, "Test Page");

	//printf("%s - strlen = %d\n", pt, strlen(pt));

	//pt =(char*) realloc(pt, 10 * sizeof(char));
	//pt = "Test Page##";
	//printf("%s - strlen = %d\n", pt, strlen(pt));



	//return;

	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int n, exit;
	do
	{
		printf("please enter exemple: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*1.	���� ������ �� ���������� ����.
				����� ���������� ���� �� ����� ��������� ��� ��������.
				������� �����, ������������ � ��������������� �����
				� ��� �� ������.*/
			char mas[] = "���������� ������ - ����-���, ��� � �� ��� ����";
			dinstr(mas, strlen(mas));

		}
		break;
		case 2:
		{
			char * a = "<i>", *b = "<#>";
			char * m = createDunamicChar(150);
			strcpy(m, "<i><body><hr><ul><i>���������</i><i>�������� ����</i><i>��������</i><i>����� ������</i></ul><hr></body>");
			
			printf("\n Before replace : %s \n", m);

			replacestr(m, a, b);

			printf("\n After replace : %s \n", m);
		}
		break;
		case 3:
		{
			/*4.	��� ������ ��������, ���������� �����.
				���������� ����� ������������ � ��� ������������
				����� ��������, �������� �� ����.*/
			char * mas = "��� ������ 1 1 ��������, ���������� �����.111 ���������� 111111 ����� ������������ 1111 � ��� ������������ ";
			int count = 0, max = 0;
			for (int i = 0;i < strlen(mas);i++)
			{
				//printf("%d - %c\n", (int)mas[i], mas[i]);
				if ((int)mas[i] >= 48 && (int)mas[i] <= 57)
					count++;
				else
				{
					if (max < count)
						max = count;
					count = 0;
				}

			}
			printf("%s \n", mas);
			printf("Max = %d \n", max);
		}
		break;
		case 4:
		{
			/*6.	��� ������ ��������.������� �� �����, 
				������� �������� ���� �� ���� ����� k.*/
			char *str = "��� �k����� �������� . ���k���� �� �����.";
			char * word = (char*)calloc(50, sizeof(char));

			int n = 0, kon = 0, ws = 0;
			while (kon < strlen(str))
			{
				
				while (str[kon] != ' '&&str[kon] != ',')
				{
					if (kon != strlen(str))
						kon++;
					else break;

				}
				for (int i = n;i < kon;i++)
				{
					word[ws] = str[i];
					ws++;
				}
				word[ws] = '\0';

				for (int i = 0;i < strlen(word);i++)
				{
					if (word[i] == 'k')
					{
						printf("%s \n", word);
						break;
					}
				}
				n = kon + 1;
				if (str[kon] != ' ' || str[kon] != ',') kon++;
				ws = 0;
			}
		}
		break;
		default:printf("No exemple\n");
			break;
		}
		printf("����������? 1-Yes 2-No:");
		scanf("%d", &exit);
		printf("\n");
	} while (exit == 1);
}