#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sort (char *str)
{
	if(str == NULL)
		return NULL;
	int len = strlen(str);
	char *res= malloc(len);
	for (int i = 0; i < len; i++)
	{
		res[i] = str[i];
	}
	res[len] = '\0';
	char tmp;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (res[j] > res[j + 1])
			{
				tmp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = tmp ;
			}
		}
	}
	return res;
}

void permutation(char *str , char *result , char *used ,int index , int res_i ,int len)
{
	if (index == len)
	{
		puts(result);
		return ;
	}
	for (int i = 0; i < len; i++)
	{
		if(used[i])
			continue;
		used[i] = 1;
		result[res_i] = str[i];
		permutation(str , result , used , index + 1 , res_i + 1 , len);
		used[i] = 0;
	}	
}

int main(int argc ,char **argv)
{
	if (argc != 2)
	{
		return 0;
	}
	char *str = sort(argv[1]);
	int len = strlen(str);
	char *result = malloc(len + 1);
	char *used  = calloc(len , 1);
	permutation(str , result , used , 0 , 0 , len);
	return 0;
}