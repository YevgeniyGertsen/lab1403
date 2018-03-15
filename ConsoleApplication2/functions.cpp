#include<iostream>
#include<locale.h>
#include"Header.h"
#include<time.h>
#include<stdio.h>

using namespace std;

void dinstr(char *str, int r)
{
	unsigned char * word = (unsigned char*)calloc(50, sizeof(unsigned char));

	int n = 0, kon = 0, ws = 0;
	while (kon < r)
	{
		while (str[kon] != ' '&&str[kon] != ',')
		{
			if (kon != r)
				kon++;
			else break;

		}
		for (int i = n;i < kon;i++)
		{
			word[ws] = str[i];
			ws++;
		}
		word[ws] = '\0';
		if (kon - n != 1)
		{
			/*if (isupper(word[0]))
			{*/
			//word[0] = tolower(word[0]);
			if (tolower(word[0]) == tolower(word[ws - 1]))
				cout << word << endl;
			/*}*/
			/*else
			{
				if (word[0] == word[ws - 1])
					cout << word << endl;
			}*/
		}
		n = kon + 1;
		if (str[kon] != ' ' || str[kon] != ',') kon++;
		ws = 0;
	}
}

int * createDunamic(int len)
{
	return (int *)malloc(len * sizeof(int));
}

char * createDunamicChar(int len)
{
	return (char *)malloc(len * sizeof(char));
}

char * reallocDunamicChar(char * str, int len)
{
	return (char*)realloc(str, len * sizeof(char));
}

void replacestr(char *str, char * old, char * tonew)
{
	int count = 0;
	int lenOld = strlen(old);
	int lenToNew = strlen(tonew);
	int strLen = strlen(str);
	int start = 0;

	for (int i = 0;i < strlen(str);i++)
	{
		if (str[i] == *old)
		{
			count++;
			old++;
		}
		else
		{
			old = old - count;
			count = 0;
		}

		if (count == lenOld)
		{
			int different = strlen(tonew) - lenOld;
			if (different > 0)
			{
				str = reallocDunamicChar(str, (strLen + different + 1));
				if (str == NULL) break;
				//Доделать 
				for (int j = strlen(str) + 1;j > i;j--)
				{
					*(str + j) = *(str + j - 1);
				}
				*(str + strLen + different + 1) = '\0';
				tonew = tonew - lenToNew;
				for (int j = i - lenOld;j < i;j++)
				{
					*(str + j) = *(tonew);
					tonew++;
				}
				printf("\n\n%d\n%s\n\n", strlen(str), str);
			}
			else if (different == 0)
				for (int j = 0;j < lenOld;j++)
					*(str + j) = *(tonew + j);
		}
	}

}

static int cSymb(char*str, char symb)
{
	int count = 0;
	for (int i = 0;i < strlen(str);i++)
		if (*(str + i) == symb)count++;
	return count;
}

void repl2(char*str)
{
	int c = cSymb(str, ' ');
	str = (char*)realloc(str, sizeof(char)*(strlen(str) + c));
	int kon = 0;
	while (kon < strlen(str))
	{
		while (str[kon] != ' ')
		{
			if (kon != strlen(str))
				kon++;
			else break;
		}
		for (int i = strlen(str) + 1;i >= kon;i--)
		{
			*(str + i) = *(str + i - 1);
		}
		*(str + kon) = ',';
		kon = kon + 2;
	}
	printf("\n\n%s\n", str);
}

void alf(char*str)
{
	unsigned char symb;
	int k;
	/*for (unsigned char i = 0;i <= 256;i++)
	{
		printf("%d - %c\n", (int)i, i);
	}*/
	for (int i = 192;i <= 255;i++)
	{
		k = cSymb(str, (unsigned char)i);
		if (k != 0)
		{
			if (k > 1 && k < 5)
				printf("Символ %c встречается %d раза\n", (unsigned char)i, k);
			else
				printf("Символ %c встречается %d раз\n", (unsigned char)i, k);
		}
	}
}

int c = 89;

int * testRef()
{		
	int b = 666;
	return &b;
}


void sorU(int * mas, int j)
{
	int temp;

	if (*(mas + j) < *(mas + j - 1))
	{
		temp = *(mas + j);
		*(mas + j) = *(mas + j - 1);
		*(mas + j - 1) = temp;
	}
}

void sorD(int * mas, int j)
{
	int temp;

	if (*(mas + j) > *(mas + j - 1))
	{
		temp = *(mas + j);
		*(mas + j) = *(mas + j - 1);
		*(mas + j - 1) = temp;
	}
}

void sort(int * mas, int length,  void(*pt)(int *, int))
{
	for (int i = 0; i < length; i++)
	{
		for (int j = length - 1; j > i; j--)
		{
			if(pt !=NULL)
				pt(mas, j);
		}
	}
}



void Poisk(char *mass, char * pt, int len)
{
	int j=0;
	int s=0;
	int k = 0;
	for (int i = 0;i < len;i++)
	{
		if (*(mass + i) == ' ')
		{
			for (int l = 0;l < i;l++)
			{
				*(pt + k * 10 + l) = *(mass +s+l);
			}			
			//*(pt + k * 10 + l) = '\0';
			s = i+1;
			k++;
		}
		

	}
}

