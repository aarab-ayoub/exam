#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sort (char *str)
{
	char tmp;
	int len = strlen(str);
	char *result = malloc(len + 1);
	for (int i = 0; i < len; i++)
		result[i]= str[i];
	result[len] = '\0';

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (result[j] > result [j + 1])
			{
				tmp = result[j];
				result[j] =result[j + 1];
				result[j + 1] = tmp;  
			}
		}
	}
	return result;
}

void permutation(char *str , char *result , char *used , int index ,int res_i , int len )
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
		permutation(str , result , used , index + 1,res_i + 1, len);
		used[i] = 0;
	}
	
}
int main(int argc, char **argv)
{
	if (argc !=2)
	{
		return 0;
	}
	char *str = sort(argv[1]);
	// printf("%s" , str);
	int len = strlen(str);
	char *result = malloc(len + 1);
	char *used = calloc(len , 1);
	permutation(str , result , used ,0, 0,len);
	free(result);
	free(used);
}