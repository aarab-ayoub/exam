#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void powerset(int *tab, int *result , int target , int index, int res_i ,int len,int total , int *flag)
{
	if (index == len)
	{
		if (target == total)
		{
			for (int i = 0; i < res_i; i++)
			{
				printf("%d" , result[i]);
				if (i < res_i - 1)
					printf(" ");
				
			}
			printf("\n");
			*flag = 1;
		}
		return ;
	}
	powerset(tab , result , target ,index + 1 , res_i, len ,total , flag);
	result[res_i] = tab[index];
	powerset(tab , result , target ,index + 1 , res_i + 1, len ,total + tab[index], flag);
}

int main(int argc , char **argv)
{
	if (argc < 3)
	{
		return 0;
	}
	int len = argc - 2;
	int *tab = malloc(sizeof(int) * len);
	int *result = malloc(sizeof(int)* len);
	int target = atoi(argv[1]);
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		tab[i] = atoi(argv[i + 2]);
	}
	powerset(tab , result , target , 0 , 0 , len ,0, &flag);
	free(result);
	free(tab);
}