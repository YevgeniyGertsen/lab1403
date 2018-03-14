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

void replacestr(char *str, char * old, char * tonew)
{
	int count = 0;
	int lenOld = strlen(old);
	char *newStr = str;

	for (int i = 0;i < strlen(str);i++)
	{
		//первое вхзождение
		if (str[i] == *old)
		{
			count++;
			old++;
			/*while (*old!='\0')
			{
				if (str[i] == *old)
				{
					old++;
					
				}
				i++;
			}*/
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
				/*printf("strlen before %d \n", strlen(str));
				str = (char*)realloc(str, sizeof(char)*different);
				if (str == NULL) break;
				printf("strlen after %d \n", strlen(str));
				printf("%s \n", str);
*/

				//str[strlen(str)+1] = 

				//for(int i=strlen(str);)
			}
			else if (different == 0)
			{
				tonew = tonew + strlen(tonew)-1;
				for (int j = 0;j < lenOld;j++)
				{
					printf("%c - %c\n", newStr[i - j], *tonew);
					newStr[i - j] = *tonew;
					tonew--;
				}
			}

				
		}
	}
	
}