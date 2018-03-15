#include<iostream>
#include<locale.h>
#include"Header.h"
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include <conio.h>

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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
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
			/*1.	Дана строка из нескольких слов.
				Слова отделяются друг от друга пробелами или запятыми.
				Вывести слова, начинающиеся и заканчивающиеся одной
				и той же буквой.*/
			char mas[] = "Автотрасса Москва - Алма-Ата, как я по ней ехал";
			dinstr(mas, strlen(mas));

		}
		break;
		case 2:
		{
			char * a = "<i>", *b = "</#>";
			char * m = createDunamicChar(150);
			strcpy(m, "<i><body><hr><ul><i>Чебурашка</i><i>Крокодил Гена</i><i>Шапокляк</i><i>Крыса Лариса</i></ul><hr></body>");

			printf("\n Before replace : %s \n", m);

			replacestr(m, a, b);

			printf("\n After replace : %s \n", m);
		}
		break;
		case 3:
		{
			/*4.	Дан массив символов, содержащий текст.
				Определить длину содержащейся в нем максимальной
				серии символов, отличных от букв.*/
			char * mas = "Дан массив 1 1 символов, содержащий текст.111 Определить 111111 длину содержащейся 1111 в нем максимальной ";
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
			/*6.	Дан массив символов.Указать те слова,
				которые содержат хотя бы одну букву k.*/
			char *str = "Дан мkассив символов . Укаkзать те слова.";
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
		case 5:
		{
			/*7.	Дан массив символов, содержащий текст.В строке между
			словами вставить вместо пробела запятую и пробел*/
			char *str = (char*)malloc(107 * sizeof(char));
			strcpy(str, "7. Дан массив символов, содержащий текст. В строке между словами вставить вместо пробела запятую и пробел");
			repl2(str);
		}
		break;
		case 6:
		{
			/*8. Массив не более чем из 100 символов, содержащий
			произвольный русский текст. Написать, какие буквы и сколько
			раз встречаются в этом тексте.Ответ должен приводиться в
			грамматически правильной форме, например, а – 5 раз, к – 7
			раз и т.д.*/

			char*str = (char*)calloc(10 * sizeof(char),sizeof(char));
			int r = 0, c=0;
			cin.get();
			printf("Введите строку \n");
			
			while (c != 13)
			{
				c = getch();
				printf("%c", (char)c);
				str = (char*)realloc(str, (r + 1) * sizeof(char));
				str[r] = (char)c;
				r++;
			}
			str[r] = '\0';

			//fgets(str,10,stdin);

			//printf("\n%s\n", str);


			/*printf("%d", (int)str[r]);*/
			/*while (true)
			{
				if ((int)str[r] == 10|| (int)str[r] == 13)
					break;
				
				if (r > 10)
					str = (char*)realloc(str, sizeof(char)*r + 1);
				r++;
				printf("%c-%d\n", str[r - 1], str[r - 1]);
			}*/
			//while ((int)str[r-1] != 10);

			alf(str);
			system("pause");
		}
		break;
		default:printf("No exemple\n");
			break;
		}
		printf("Продолжить? 1-Yes 2-No:");
		scanf("%d", &exit);
		printf("\n");
	} while (exit == 1);
}