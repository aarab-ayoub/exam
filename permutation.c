#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *sort(char *av)
{
	int len = strlen(av);
	char *result = malloc(len + 1);
	char temp;
	
	for (int i = 0; i < len; i++)
		result[i] = av[i];
	result[len] = '\0';

	for(int i = 0;i <len -1;i++)
	{
		for(int j=0;j< len-1 ;j++)
		{
			if(result[j] > result [j+1])
			{
				temp = result[j];
				result[j] = result[j+1];
				result[j+1] =temp;
			}
		}
	}
	return result;
}

void perm(char *str, char *result, char *used, int index, int res_i, int len)
{
	if(res_i == len)
	{
		result[res_i] = '\0';
		printf("%s\n", result);
		return;
	}
	for(int i =0;i <len ; i++)
	{
		if(used[i])
			continue;
		used[i]=1;
		result[res_i] = str[i];
		perm(str, result,used, index +1,res_i +1,len);
		used[i]=0;
	}
}

int main(int argc, char **argv)
{
	if(argc != 2)
		return 0;

	char *str = sort(argv[1]);
	char *result = malloc(strlen(str) + 1);
	char *used = calloc(strlen(str), 1); 
	
	perm(str, result, used, 0, 0, strlen(str));
	
	free(str);
	free(result);
	free(used);
	
	return 0;
}
