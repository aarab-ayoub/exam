#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


char    *sort(char *av)
{
    char *result;
    size_t len = strlen(av);
    char    tmp;

    result  = malloc(len + 1);
    for (int i = 0; i < len; i++)
        result[i] = av[i];
    result[len] = '\0';
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len -1; j++)
        {
            if (result[j] > result[j + 1])
            {
                tmp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = tmp;
            }
        }
    }
    return (result);
}

void permutation(char *str ,  char *result , int *used ,int index , int res_i , int len)
{
	if (res_i == len)
	{
		printf("%s\n" , result);
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

int main(int argc , char **argv)
{
	char *str = sort(argv[1]);
	char *result = malloc(strlen(str) + 1);
	int *used = calloc(strlen(str) ,1);
	permutation(str, result, used, 0, 0, strlen(str));
}